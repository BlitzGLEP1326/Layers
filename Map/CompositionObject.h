#pragma once

#include "Layer.h"

class CompositionObject
{
public:
	explicit CompositionObject( QSharedPointer< const Data > data );
	~CompositionObject();
	
	//Layers
	void EnableLayer( const QString& nameLayer );
	void DisableLayer( const QString& nameLayer );
	QStringList GetListNamesLayers() const;
	bool IsVisibleLayer( const QString& nameLayer ) const;
	
	//Objects
	void EnableObject( const QString& nameLayer, const QString& nameObject );
	void DisableObject( const QString& nameLayer, const QString& nameObject );
	QStringList GetListNamesObjects( const QString& nameLayer ) const;
	bool IsVisibleObject( const QString& nameLayer, const QString& nameObject ) const;

private:
	void CreateAllLayers();
	
	QSharedPointer< const Data > _data;
	
	GisToolWrapper::SelectContextId _selectContextId;
	typedef QSharedPointer< Layer > PointerToLayer;
	QHash< QString, PointerToLayer > _allLayers;
};