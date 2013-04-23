#include "Map.h"
#include "Data.h"
#include "Layer.h"

Layer::Layer( QSharedPointer< const Data > data, const int number )
	: _data( data )
	, _name( GisToolWrapper::GetLayerName( data->GetId(), number ) ) 
	, _number( number )
	, _visible( true )
{
	CreateAllObjects();
}

Layer::~Layer()
{	
}

QString Layer::GetName() const
{
	return _name;
}

int Layer::GetNumber() const
{
	return _number;
}

bool Layer::IsVisible() const
{
	return _visible;
}

void Layer::Enable( const GisToolWrapper::SelectContextId selectContextId )
{
	_visible = true;
	GisToolWrapper::SelectLayer( selectContextId, _number, _visible );
}

void Layer::Disable( const GisToolWrapper::SelectContextId selectContextId )
{
	QHash< QString, PointerToObject >::iterator curent( _allObjects.begin() );
	while ( curent != _allObjects.end() )
	{
		( *curent )->Disable( selectContextId, _number );
		++curent;
	}

	_visible = false;
	GisToolWrapper::SelectLayer( selectContextId, _number, _visible );
}

PointerToObject Layer::GetObject( const QString& nameObject ) 
{
	return _allObjects.value( nameObject );
}

QStringList Layer::GetNameObjectList() const
{
	if ( !_allObjects.isEmpty() )
	{
		return _allObjects.keys();
	}
	else
	{
		return QStringList();
	}
}

void Layer::CreateAllObjects()
{
	const int countObjects( GisToolWrapper::GetRscObjectCountInLayer( _data->GetId(), _number ) );	
	for( int numberObject( 0 ); numberObject < countObjects; ++numberObject )
	{
        PointerToObject ptrObject( new Object( _data, _number, numberObject ) );
		QString nameObject( ptrObject->GetName() );
		if ( !nameObject.isEmpty() )
		{
			_allObjects.insert( nameObject, ptrObject );
		}
		else
		{
			//object have empty name 
		}
	}

}
