#include <QtCore/QFile>
#include <QtCore/QTextIStream>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>

//#include "Exception/FileNotFoundException.h"
#include <QMessageBox>
#include "Map.h"
#include "HistoryModel.h"

const QString HistoryModel::FileName( "MapHistory.xml" );
const QString HistoryModel::DirName( "Settings" );

HistoryModel::HistoryModel()
{
	CreateTypeTable();
}

HistoryModel::~HistoryModel()
{
}

void HistoryModel::CreateTypeTable()
{
	_typeTable.insert( "Vector", Map::Vector );
	_typeTable.insert( "Matrix", Map::Matrix );
	_typeTable.insert( "Raster", Map::Raster );
}

QString HistoryModel::GetFileName() const
{
    QFileInfo pathInfo( FileName );
	return pathInfo.fileName();
}

QList< HistoryData > HistoryModel::GetHistoryDataList()
{
	ReadHistory();
	return _historyDataList;
}

void HistoryModel::SetHistoryDataList( const QList< HistoryData >& historyDataList )
{
	_historyDataList = historyDataList;
	WriteHistory();
}

Map::DataType HistoryModel::ConvertStringToDataType( const QString& type ) const
{
    return _typeTable.value(type);
}

void HistoryModel::CheckDir()
{
    QDir dir;
    dir.cdUp();

    if(!dir.exists(DirName))
        dir.mkdir(DirName);
}

void HistoryModel::ReadHistory()
{
    CheckDir();
    const QString filePath = GetFilePath();

    QFile file(filePath);
	if ( !file.open( QIODevice::ReadOnly ) )
	{
//		throw Exception::FileNotFoundException( "Файл истории карты не найден" );
        QMessageBox::warning(0, "", "Файл истории карты не найден");
	}

	QDomDocument document( GetFileName() );
	
	document.setContent( &file, false );
	
	file.close();

	QDomElement rootElement( document.documentElement() );
	QDomNode childElement( rootElement.firstChild() );

	while( !childElement.isNull() )
	{
		const QString type( childElement.toElement().attribute( "type" ) );
		const QString isCurrent( childElement.toElement().attribute( "isCurrent" ) ); 
		const QString isVisible( childElement.toElement().attribute( "isVisible" ) ); 

		QDomNode childChildElement = childElement.firstChild();
		
		const QString path( childChildElement.toElement().text() );
		const QString scale( childChildElement.nextSiblingElement( "scale" ).text() );
		const QString bright( childChildElement.nextSiblingElement( "bright" ).text() );
		const QString contrast( childChildElement.nextSiblingElement( "contrast" ).text() );
		const QString transparent( childChildElement.nextSiblingElement( "transparent" ).text() );
		
		QDomElement nextElement = childChildElement.nextSiblingElement("position");
		const QString x(nextElement.toElement().attribute( "x" ));
		const QString y(nextElement.toElement().attribute( "y" ));

		if ( type.isEmpty() || path.isEmpty() )
			continue;
		
		HistoryData historyData;
		historyData.path = path;
				
		Map::DataType dataType = ConvertStringToDataType( type );
		if ( dataType == Map::WrongDataType )
			return;

		historyData.type = dataType;
		historyData.isCurrent = ( isCurrent == "true" ) ? true : false;
		historyData.isVisible = ( isVisible == "true" ) ? true : false;
		historyData.scale = scale.toDouble();
		historyData.bright = bright.toInt();
		historyData.contrast = contrast.toInt();
		historyData.transparent = transparent.toInt();
		historyData.x = x.toInt();
		historyData.y = y.toInt(); 

		_historyDataList << historyData;

		childElement = childElement.nextSibling();
	}
}

void HistoryModel::WriteHistory()
{
    CheckDir();
    const QString filePath = GetFilePath();

    QFile file( filePath );
	if ( !file.open( QIODevice::WriteOnly ) )
	{
//		throw Exception::FileNotFoundException( "Файл истории карты не найден" );
        QMessageBox::warning(0, "", "Файл истории карты не найден");
	}

	QDomDocument document( GetFileName() );
	QDomElement root( document.createElement( "atlas" ) );
	document.appendChild( root );

	foreach ( HistoryData historyData, _historyDataList )
	{
		QDomElement tagMap( document.createElement( "map" ) );
		root.appendChild( tagMap );
		
		tagMap.setAttribute( "type", _typeTable.key( historyData.type ) );
		tagMap.setAttribute( "isCurrent", historyData.isCurrent ? "true" : "false" );
		tagMap.setAttribute( "isVisible", historyData.isVisible ? "true" : "false" );

		//path
		QDomElement tagPath( document.createElement("path") );
		tagMap.appendChild( tagPath );

		QDomText text( document.createTextNode( historyData.path ) ); 
		tagPath.appendChild( text );
		
		//scale
		QDomElement tagScale( document.createElement("scale") );
		tagMap.appendChild( tagScale );

		const int persistion( 6 );
		text = document.createTextNode( QString::number( historyData.scale, 'g', persistion ) ); 
		tagScale.appendChild( text ); 

		//bright
		QDomElement tagBright( document.createElement("bright") );
		tagMap.appendChild( tagBright );

		text = document.createTextNode( QString::number( historyData.bright ) ); 
		tagBright.appendChild( text ); 
		
		//contrast
		QDomElement tagContrast( document.createElement("contrast") );
		tagMap.appendChild( tagContrast );

		text = document.createTextNode( QString::number( historyData.contrast ) ); 
		tagContrast.appendChild( text ); 

		//transparent
		QDomElement tagTransparent( document.createElement("transparent") );
		tagMap.appendChild( tagTransparent );

		text = document.createTextNode( QString::number( historyData.transparent ) ); 
		tagTransparent.appendChild( text ); 

		//position
		QDomElement tagPosition( document.createElement("position") );
		tagMap.appendChild( tagPosition );
		
		tagPosition.setAttribute( "x", QString::number( historyData.x));
		tagPosition.setAttribute( "y", QString::number( historyData.y));
	}
	
	QTextStream out( &file );
	const int indent( 4 );
	document.save( out, indent );
    file.close();
}

QString HistoryModel::GetFilePath()
{
    QDir dir;
    dir.cdUp();
    QString path = dir.path() + dir.separator() + DirName + dir.separator() + FileName;
    return path;
}
