#pragma once

typedef QPair< QImage, QRect > DataImage; 
//есть необходимость применить pimpl

class ImageBulder
{
public:
	explicit ImageBulder( QSharedPointer< const Data > data );
	~ImageBulder();

	QRectF GetBoudingRect() const;
	
	DataImage GetImage( const QRect& rect ) const;

private:
	void SetBoudingRect();

	QSharedPointer< const Data > _data;
	QRectF _boudingRect;

#ifdef Q_OS_WIN32
	typedef BITMAPINFOHEADER Dib;
	Dib PrepareDib( const QRect& rect ) const;
#endif //WIN32API

#ifdef Q_OS_LINUX
	typedef XIMAGEDESC XImage;
	XImage PrepareXImage( const QRect& rect, QImage& mapImage ) const;
#endif	//LINUXAPI
};