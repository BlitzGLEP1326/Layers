#pragma once

class HeightFinder
{
public:
	explicit HeightFinder( QSharedPointer< const Data > data );
	~HeightFinder();

	double GetHeight( const QPointF point ) const;
	QVector< double > GetHeight( const QPointF beginPoint, const QPointF endPoint, 
		const double countHeight ) const;

private:
	QSharedPointer< const Data > _data;	
};