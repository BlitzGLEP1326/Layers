#include "Map.h"
#include "Data.h"
#include "Object.h"

Object::Object( QSharedPointer< const Data > data, const int numberLayer, const int numberObject )
	: _data( data )
	, _name( GisToolWrapper::GetRscObjectNameInLayer( data->GetId(), numberLayer, numberObject ) )
	, _number( numberObject ) 
	, _visible( true )
{
}

Object::~Object()
{
}

QString Object::GetName() const
{
	return _name;
}


int Object::GetNumber() const
{
	return _number;
}

bool Object::IsVisible() const
{
	return _visible;
}


void Object::Enable( const GisToolWrapper::SelectContextId selectContextId, const int numberLayer )
{
	_visible = true;
	SetAccessObject( selectContextId, numberLayer );
}

void Object::Disable( const GisToolWrapper::SelectContextId selectContextId, const int numberLayer )
{
	_visible = false;
	SetAccessObject( selectContextId, numberLayer );
}

void Object::SetAccessObject( const GisToolWrapper::SelectContextId selectContextId, const int numberLayer ) const
{
	const int objectCodeInLayer( GisToolWrapper::GetRscObjectCodeInLayer( _data->GetId(), 
		numberLayer, _number ) );
	GisToolWrapper::SelectObject( selectContextId, objectCodeInLayer, _visible );
	GisToolWrapper::SetViewSelect( _data->GetId(), selectContextId );
}


