#pragma once

class Converter
{
public:
	explicit Converter( QSharedPointer< const Data > data )
		: _data( data )
	{
	}

	virtual ~Converter()
	{
	}

	virtual QPointF Convert( const QPointF& point ) const = 0;
	virtual QPointF ConvertBack( const QPointF& point ) const = 0;

protected:
	QSharedPointer< const Data > _data;	
};

