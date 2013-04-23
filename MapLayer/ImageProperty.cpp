#include "Map.h"
#include "Data.h"
#include "ImageProperty.h"

ImageProperty::ImageProperty( QSharedPointer< const Data > data )
	: _data( data )
	, _alphaChanel( 0.5 )
{
	
}

ImageProperty::~ImageProperty()
{
}

int ImageProperty::GetBright() const
{
	return GisToolWrapper::GetBright( _data->GetId() );
}

void ImageProperty::SetBright( const int brightValue ) 
{
	if ( _data->GetType() == Map::Matrix )
	{
		GisToolWrapper::SetMtrBright( _data->GetId(), brightValue );
	}
	else if ( _data->GetType() == Map::Vector )
	{
		GisToolWrapper::SetBright( _data->GetId(), brightValue );
	}
	else if ( _data->GetType() == Map::Raster )
	{
		GisToolWrapper::SetRstBright( _data->GetId(), brightValue );
	}
	else
	{
		//undefined type
		return;
	}
}

int ImageProperty::GetContrast() const
{
	return GisToolWrapper::GetContrast( _data->GetId() );
}

void ImageProperty::SetContrast( const int contrastValue )
{
	if ( Map::Matrix == _data->GetType() )
	{
		GisToolWrapper::SetMtrContrast( _data->GetId(), contrastValue );
	}
	else if ( Map::Vector  == _data->GetType() )
	{
		GisToolWrapper::SetContrast( _data->GetId(), contrastValue );
	}
	else if ( Map::Raster == _data->GetType() )
	{
		GisToolWrapper::SetRstContrast( _data->GetId(), contrastValue );
	}
	else
	{
		//undefined type
		return;
	}
}

qreal ImageProperty::GetTransparent() const
{
	return ( _alphaChanel );
}

void ImageProperty::SetTransparent( const qreal alphaChanel )
{
	_alphaChanel = alphaChanel;
}
