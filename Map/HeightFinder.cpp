#include "Map.h"
#include "Data.h"
#include "HeightFinder.h"

HeightFinder::HeightFinder( QSharedPointer< const Data > data )
	: _data( data )
{
}

HeightFinder::~HeightFinder()
{
}

double HeightFinder::GetHeight( const QPointF point ) const
{
	return GisToolWrapper::GetHeightValue( _data->GetId(), point );
}

QVector< double > HeightFinder::GetHeight( const QPointF beginPoint, const QPointF endPoint,
	const double countHeight ) const
{
	return GisToolWrapper::GetHeightArray( _data->GetId(), beginPoint, endPoint, countHeight );
}