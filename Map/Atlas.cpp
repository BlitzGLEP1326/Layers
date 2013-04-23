#include "Atlas.h"
#include "Data.h"
#include "HistoryModel.h"

int meta = qRegisterMetaType< MapSharedPointer >( "MapSharedPointer" );
int meta2 = qRegisterMetaType< Map::DataType >( "Map::DataType" );

Atlas::Atlas(QObject *parent)
	: QObject(parent)
{
	GisToolWrapper::EnableMessage( false );
}

Atlas::~Atlas()
{
	WriteToHistory();

	foreach (MapSharedPointer map, _mapArray.values()) {
		CloseMap(map->GetId());
	}
}

MapWeakPtr Atlas::OpenMap( const QString& path, Map::DataType dataType )
{
 	QSharedPointer< const Data > data( new Data( path, dataType ) );
 	MapSharedPointer map( new Map( data ) );
	
	_mapArray.insert( data->GetId(), map );
	
 	return map; 
}	
 
void Atlas::CloseMap( const int id )
{
 	if ( !id )
		return;
	
        if ( !_mapOnScreen.isNull() && (id == _mapOnScreen.toStrongRef()->GetId()) )
		emit VisibleMapHasChanged( MapSharedPointer() );
	
	foreach ( MapSharedPointer map, _arrayCurentMaps.values() ) {
		if ( id != map->GetId() ) 
			continue;
		
		emit CurrentMapHasChanged( MapSharedPointer(), map->GetType() );
		_arrayCurentMaps.remove(map->GetType());
	}

	_mapArray.remove( id );
}

MapWeakPtr Atlas::GetMapOnScreen() const
{
	return _mapOnScreen;
}

void Atlas::SetMapOnScreen( const int id )
{
	_mapOnScreen = _mapArray.value( id );
	if ( !_mapOnScreen  )
		return;

	emit VisibleMapHasChanged( _mapOnScreen.toStrongRef() );
}

bool Atlas::IsVisibleMap( MapSharedPointer map ) const
{
	return ( map == _mapOnScreen ); 
}

void Atlas::SetCurrentMap( int id )
{
	MapSharedPointer map = _mapArray.value( id );
	
	if ( !map )
		return;

	Map::DataType type = map->GetType(); 
	_arrayCurentMaps.insert( type, map );

	emit CurrentMapHasChanged( map, type );
}

MapWeakPtr Atlas::GetCurrentMap( Map::DataType type ) const
{
	return _arrayCurentMaps.value( type );
}

bool Atlas::IsCurrentMap( MapSharedPointer map ) const
{
	return ( map == _arrayCurentMaps.value( map->GetType() ) );
}

QList< MapSharedPointer > Atlas::GetAllMaps()
{
	if ( _mapArray.isEmpty() )
	{
		ReadFromHistory();
	}
	else
	{
		//nothing
	}

	return _mapArray.values();

}

void Atlas::connectNotify( const char* signal )
{
	const QString vissibleMapSignal( SIGNAL( VisibleMapHasChanged(MapSharedPointer) ) );
	const QString currentMapSignal( SIGNAL( CurrentMapHasChanged(MapSharedPointer,Map::DataType) ) );

	if ( vissibleMapSignal == QLatin1String( signal ) ) {
		emit VisibleMapHasChanged( _mapOnScreen.toStrongRef() );
	}
	else if ( currentMapSignal == QLatin1String( signal ) ) {
		foreach ( MapSharedPointer map, _arrayCurentMaps.values() ) {
			emit CurrentMapHasChanged( map, map->GetType() );
		}
	}
	else {
		//nothing
	}
}

void Atlas::ReadFromHistory()
{
	QList< HistoryData > historyDataList( HistoryModel().GetHistoryDataList() );

	foreach ( HistoryData historyData, historyDataList )
	{
		MapSharedPointer map( OpenMap( historyData.path, historyData.type ) );

		map->SetScale( historyData.scale );
		map->SetBright( historyData.bright );
		map->SetContrast( historyData.contrast );
		map->SetTransparent( historyData.transparent );
		map->SetPos(QPoint(historyData.x, historyData.y));

		if ( historyData.isCurrent )
		{
			_arrayCurentMaps.insert( map->GetType(), map );
		}
		else
		{
			//nothing
		}

		if ( historyData.isVisible )
		{
			_mapOnScreen = map;
		} 
		else
		{
			//nothing
		}
	}
}

void Atlas::WriteToHistory() const 
{
	QList< HistoryData > historyDataList;
	foreach ( MapSharedPointer map, _mapArray.values() ) {
		HistoryData historyData;
		historyData.path = map->GetPath();
		historyData.type = map->GetType();
		historyData.isCurrent = ( _arrayCurentMaps.value( map->GetType() ).data() == 
			map.data() ) ? true : false;
		historyData.isVisible = ( _mapOnScreen == map ) ? true : false;
		historyData.scale = map->GetScale();
		historyData.bright = map->GetBright();
		historyData.contrast = map->GetContrast();
		historyData.transparent = map->GetTransparent();
		historyData.x = map->GetPos().x();
		historyData.y = map->GetPos().y();
		
		historyDataList << historyData;
	}

	HistoryModel().SetHistoryDataList( historyDataList );
}
