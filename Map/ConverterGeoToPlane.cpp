#include "Map.h"
#include "Data.h"
#include "Converter.h"
#include "ConverterGeoToPlane.h"

ConverterGeoToPlane::ConverterGeoToPlane( QSharedPointer< const Data > data )
	: Converter( data )
{
}

ConverterGeoToPlane::~ConverterGeoToPlane()
{
}

QPointF ConverterGeoToPlane::Convert( const QPointF& point ) const
{
	return GisToolWrapper::GeoToPlane( _data->GetId(), point );
}

QPointF ConverterGeoToPlane::ConvertBack( const QPointF& point ) const
{
	return GisToolWrapper::PlaneToGeo( _data->GetId(), point );
}