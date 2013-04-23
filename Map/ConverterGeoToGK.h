#pragma once

class ConverterGeoToGK :	public Converter
{
public:
	explicit ConverterGeoToGK( QSharedPointer< const Data > data );
	~ConverterGeoToGK(void);

	QPointF Convert( const QPointF& point ) const;
	QPointF ConvertBack( const QPointF&  point ) const;
};
