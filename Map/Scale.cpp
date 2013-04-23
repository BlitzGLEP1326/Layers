#include "GisToolWrapper.h"
#include "Map.h"
#include "Data.h"
#include "Scale.h"

Scale::Scale( QSharedPointer< const Data > data )
	: _data( data )	
	, _baseScale( GetScale() )
	, _scalingCoefficient( 1.0 )
{	
}

Scale::~Scale()
{
}

qreal Scale::GetScale() const
{
	return GisToolWrapper::GetRealShowScale( _data->GetId() );
}

qreal Scale::GetBaseScale() const
{
	return _baseScale;
}

qreal Scale::GetScalingCoefficient() const
{
	return _scalingCoefficient;
}

QTransform Scale::GetTransform() const
{
	return _transform;
}

void Scale::SetScale( const qreal scale )
{
	if ( GisToolWrapper::SetViewScale( _data->GetId(), scale ) )
	{
		SetTransform();
	}
	else
	{
		//nothing
	}
}

void Scale::SetTransform()
{
	const qreal newScale( GetScale() );
	_scalingCoefficient = ( newScale == 0 ) ? 1 : _baseScale / newScale;
	_transform.reset();
	_transform.scale( _scalingCoefficient, _scalingCoefficient );
}
