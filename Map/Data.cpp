#include <QtCore/QSharedPointer>
#include <QtCore/QHash>
#include <QtCore/QFileInfo>

#include "Map.h"
#include "Data.h"

#include <QMessageBox>

Data::Data( const QString& path, Map::DataType type  )
	: _id( 0 )
	, _type( type )
{
	if ( !Open( path ) )
	{
//		throw Exception::FileNotFoundException( "Файл данных не найден или поврежден" );
        QMessageBox::warning(0, "", "Файл данных не найден или поврежден");
	}
	SetName( path );
}

Data::~Data()
{
	Close();
}

bool Data::Open( const QString& path )
{
	// Dirty hack for gisacces 10
	int count = 0;
	const int maxCount = 3;
	while (count != maxCount) {
		_id = GisToolWrapper::OpenData( path );

		if (_id)
			break;
		++count;
	}

	return _id;
}

void Data::Close()
{
	GisToolWrapper::CloseData( _id );
	_id = 0;
}

int Data::GetId() const
{
	return _id;
}

QString Data::GetPath() const
{
	return _path;
}

QString Data::GetName() const
{
	return _name;
}

void Data::SetName( const QString& path )
{
	if ( path.isEmpty() )
		return;

	_path = path;
	QFileInfo pathInfo( path );
	_name = pathInfo.fileName();
}

Map::DataType Data::GetType() const
{
	return _type;
}

void Data::SetType( Map::DataType type )
{
	_type = type;
}

