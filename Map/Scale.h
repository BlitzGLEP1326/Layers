#pragma once

class Scale
{
public:

	explicit Scale( QSharedPointer< const Data > data );
	~Scale();
	
	qreal GetScale() const;
	qreal GetBaseScale() const;
	qreal GetScalingCoefficient() const;
	QTransform GetTransform() const;
	void SetScale( const qreal scale );

private:
	void SetTransform();

	QSharedPointer< const Data > _data;
	const qreal _baseScale;
	qreal _scalingCoefficient;
	QTransform _transform;
};
