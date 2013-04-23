
#include "Map.h"
#include "Data.h"
#include "Converter.h"
#include "ConverterGeoToGK.h"

ConverterGeoToGK::ConverterGeoToGK( QSharedPointer< const Data > data )
: Converter( data )
{
}

ConverterGeoToGK::~ConverterGeoToGK(void)
{
}


QPointF ConverterGeoToGK::Convert( const QPointF& point ) const
{
	return GisToolWrapper::GeoToGK( _data->GetId(), point );
}

QPointF ConverterGeoToGK::ConvertBack( const QPointF& point ) const
{
	return GisToolWrapper::GKToGeo( _data->GetId(), point );
}
