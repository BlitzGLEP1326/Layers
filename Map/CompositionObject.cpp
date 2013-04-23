#include "Map.h"
#include "Data.h"
#include "CompositionObject.h"

CompositionObject::CompositionObject( QSharedPointer< const Data > data )
	: _data( data )
	, _selectContextId( GisToolWrapper::CreateSelectContext( data->GetId() ) )
{
	CreateAllLayers();
}

CompositionObject::~CompositionObject()
{
	GisToolWrapper::DeleteSelectContext( _selectContextId );
}

void CompositionObject::EnableLayer( const QString& nameLayer )
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return;
		//to do: error 
	}

	layer->Enable( _selectContextId );
	GisToolWrapper::SetViewSelect( _data->GetId(), _selectContextId );
}

void CompositionObject::DisableLayer( const QString& nameLayer )
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return;
		//to do: error
	}

	layer->Disable( _selectContextId );
	GisToolWrapper::SetViewSelect( _data->GetId(), _selectContextId );
}

QStringList CompositionObject::GetListNamesLayers() const
{
	if ( !_allLayers.isEmpty() )
	{
		return _allLayers.keys();
	}
	else
	{
		return QStringList();
	}
}

bool CompositionObject::IsVisibleLayer( const QString& nameLayer ) const
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return false;
		//to do: error;
	}
	return layer->IsVisible();
}

void CompositionObject::EnableObject( const QString& nameLayer, const QString& nameObject )
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return;
		//to do: error
	}
	
	const int numberLayer( layer->GetNumber() );
	layer->GetObject( nameObject )->Enable( _selectContextId, numberLayer );
}

void CompositionObject::DisableObject( const QString& nameLayer, const QString& nameObject )
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return;
		//to do: error		
	}

	const int numberLayer( layer->GetNumber() );
	layer->GetObject( nameObject )->Disable( _selectContextId, numberLayer );
}

QStringList CompositionObject::GetListNamesObjects( const QString& nameLayer ) const
{
	PointerToLayer layer( _allLayers.value( nameLayer ) );
	if ( !layer )
	{
		return QStringList();
	}

	return layer->GetNameObjectList();
}

bool CompositionObject::IsVisibleObject( const QString& nameLayer, const QString& nameObject ) const
{
	PointerToLayer layer( _allLayers.value( nameLayer ) ); 
	if ( !layer )
	{
		return false; 
		//to do: error
	}
	return layer->GetObject( nameObject )->IsVisible();
}

void CompositionObject::CreateAllLayers()
{
	const int countLayer( GisToolWrapper::GetLayerCount( _data->GetId() ) );	
	for ( int numberLayer( 0 ); numberLayer < countLayer; ++numberLayer )
	{
		PointerToLayer ptrLayer( new Layer( _data, numberLayer ) );
		_allLayers.insert( ptrLayer->GetName(), ptrLayer );
	}
}
