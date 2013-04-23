#pragma once

#include "GisToolWrapper.h"
#include "Map.h"

class Data 
{

public:
	Data( const QString& path, Map::DataType type );
	~Data();

	bool Open( const QString& path );
	void Close();

	int GetId() const;

	QString GetPath() const;
	QString GetName() const;
	
	Map::DataType GetType() const;
	void SetType( Map::DataType type );

private:
	void SetName( const QString& path );

	GisToolWrapper::DataId _id;
	Map::DataType _type;
	QString _name;
	QString _path;
};
