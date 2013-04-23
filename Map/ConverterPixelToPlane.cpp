#include "Map.h"
#include "Data.h"
#include "Scale.h"
#include "Converter.h"
#include "ConverterPixelToPlane.h"

ConverterPixelToPlane::ConverterPixelToPlane( QSharedPointer< const Data > data, Scale* scale )
	: Converter( data ),
	_scale(scale)
{
}

ConverterPixelToPlane::~ConverterPixelToPlane()
{
}

QPointF ConverterPixelToPlane::Convert( const QPointF& point ) const
{
	const QPointF pixelPoint( point * _scale->GetScalingCoefficient() );
	return GisToolWrapper::PictureToPlane( _data->GetId(), pixelPoint );
}

QPointF ConverterPixelToPlane::ConvertBack( const QPointF& point ) const
{
	QPointF pixelPoint( GisToolWrapper::PlaneToPicture( _data->GetId(), point ) );
	return pixelPoint /= _scale->GetScalingCoefficient();
}
