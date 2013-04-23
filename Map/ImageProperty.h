#pragma once

class ImageProperty 
{
public:
	explicit ImageProperty( QSharedPointer< const Data > data );
	~ImageProperty();
	
	//�������
	int GetBright() const;
	void SetBright( const int brightValue );

	//�������������
	int GetContrast() const;
	void SetContrast( const int contrastValue );
	
	//������������
	qreal GetTransparent() const;
	void SetTransparent( const qreal alphaChanel );
	
private:
	QSharedPointer< const Data > _data;
	qreal _alphaChanel;
};