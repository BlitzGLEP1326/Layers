#pragma once

class ImageProperty 
{
public:
	explicit ImageProperty( QSharedPointer< const Data > data );
	~ImageProperty();
	
	//яркость
	int GetBright() const;
	void SetBright( const int brightValue );

	//контрастность
	int GetContrast() const;
	void SetContrast( const int contrastValue );
	
	//прозрачность
	qreal GetTransparent() const;
	void SetTransparent( const qreal alphaChanel );
	
private:
	QSharedPointer< const Data > _data;
	qreal _alphaChanel;
};