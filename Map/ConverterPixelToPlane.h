#pragma once

class Scale;

class ConverterPixelToPlane : public Converter
{
public:
	explicit ConverterPixelToPlane( QSharedPointer< const Data > data, Scale* scale );
	~ConverterPixelToPlane();

	QPointF Convert( const QPointF& point ) const;
	QPointF ConvertBack( const QPointF& point ) const;

private:

	Scale *_scale;
};