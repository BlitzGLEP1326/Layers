#ifndef ATLAS_H
#define ATLAS_H

#include <QObject>

#include "Map.h"
#include "LibraryDeclaration.h"

typedef QWeakPointer< Map > MapWeakPtr;
typedef QSharedPointer< Map > MapSharedPointer;

class QFile;

class MAP_EXPORT Atlas : public QObject
{
	Q_OBJECT

public:
	Atlas( QObject* parent = 0 );
	~Atlas();

	//open/close
	MapWeakPtr OpenMap( const QString& path, Map::DataType dataType );
	void CloseMap( const int id );
	
	//map on the screen
	void SetMapOnScreen( const int id );
	MapWeakPtr GetMapOnScreen() const;
	bool IsVisibleMap( MapSharedPointer map ) const;
	
	//current map any type
	void SetCurrentMap( int id );
	MapWeakPtr GetCurrentMap( Map::DataType type ) const;
	bool IsCurrentMap( MapSharedPointer map ) const;
	
	//return all maps
	QList< MapSharedPointer > GetAllMaps();
signals:
	void VisibleMapHasChanged( MapSharedPointer map );
	void CurrentMapHasChanged( MapSharedPointer map, Map::DataType type );

private:
	void connectNotify( const char* signal );
	void ReadFromHistory();
	void WriteToHistory() const;
	
	QHash< int, MapSharedPointer > _mapArray;
	MapWeakPtr _mapOnScreen;
	QHash< Map::DataType, MapWeakPtr > _arrayCurentMaps;
};

Q_DECLARE_METATYPE( Atlas* )

#endif // ATLAS_H
