#pragma once

#include "Object.h"
 
typedef QSharedPointer< Object > PointerToObject;

class Layer
{
public:
	Layer( QSharedPointer< const Data > data, const int number );
	~Layer();
	
	QString GetName() const;
	int GetNumber() const; 
	bool IsVisible() const;

	void Enable( const GisToolWrapper::SelectContextId selectContextId );
	void Disable( const GisToolWrapper::SelectContextId selectContextId );
	
	//objects
	PointerToObject GetObject( const QString& nameObject );
	QStringList GetNameObjectList() const;
	
private:
	void CreateAllObjects();
		
	QSharedPointer< const Data > _data;
	QString _name;
	int _number;
	bool _visible;
	QHash< QString, PointerToObject > _allObjects;
};
