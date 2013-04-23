#pragma once

class ConverterGeoToPlane : public Converter
{
public:
	explicit ConverterGeoToPlane( QSharedPointer< const Data > data );
	~ConverterGeoToPlane();

	QPointF Convert( const QPointF& point ) const;
	QPointF ConvertBack( const QPointF&  point ) const;
};