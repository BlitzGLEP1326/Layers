#undef	UNICODE
	#include <mapapi.h>
#define	UNICODE

#include <QtCore/QPair>
#include <QtGui/QImage>
#include <QtCore/QRect>
#include <QtCore/QSharedPointer>
#include <QtCore/QHash>

#include "Map.h"
#include "Data.h"
#include "ImageBulder.h"

ImageBulder::ImageBulder( QSharedPointer< const Data > data )
	: _data( data )
{
	SetBoudingRect();
}

ImageBulder::~ImageBulder()
{
}

QRectF ImageBulder::GetBoudingRect() const
{
	return _boudingRect;
}

void ImageBulder::SetBoudingRect()
{
	long width( 0 );
	long height( 0 );
	mapGetPictureSize( _data->GetId(), &width, &height );
	_boudingRect = QRectF( 0.0, 0.0, static_cast< qreal >( width ), static_cast< qreal >( height ) );
}

#ifdef WIN32API
ImageBulder::Dib ImageBulder::PrepareDib( const QRect& rect ) const
{
	const long width = rect.width();
	const long height = rect.height();
	const int bitCount = 32;
	const int byteCount = 4;
	const int capacity = 31;
	const int bytesPerLine = ( ( width * bitCount + capacity ) / bitCount ) * byteCount;
	const int sizeOfImage = bytesPerLine * height;

	Dib dib = Dib();
	dib.biSize= sizeof( Dib );
	dib.biWidth = rect.width();
	dib.biHeight = rect.height();
	dib.biPlanes = 1;
	dib.biBitCount = bitCount;
	dib.biCompression = BI_RGB;
	dib.biSizeImage = sizeOfImage;

	return dib;
}
#endif //WIN32API

#ifdef LINUXAPI
ImageBulder::XImage ImageBulder::PrepareXImage( const QRect& rect, QImage& mapImage ) const
{
	const long width = rect.width();
	const long height = rect.height();

	const long bitCount = 32;
	const long cellSize = bitCount / 8;
	const int capacity = 31;
	const long rowSize = ( ( bitCount * width + capacity ) / bitCount ) * cellSize;

	XImage  xImage = XImage();
	xImage.Point = reinterpret_cast< char* >( mapImage.bits() );
	xImage.Width = width;
	xImage.Height = height;
	xImage.Depth = bitCount;
	xImage.CellSize = cellSize;
	xImage.RowSize = rowSize;

	return xImage;
}
#endif //LINUXAPI

DataImage ImageBulder::GetImage( const QRect& rect ) const
{
	RECT viewer;
	viewer.left = rect.left();
	viewer.top = rect.top();
	viewer.right = rect.right();
	viewer.bottom = rect.bottom();

	QImage image( rect.size(), QImage::Format_RGB32 );

#ifdef WIN32API
	BITMAPINFOHEADER dib = PrepareDib( rect );
		
	if ( !mapPaintToDib( _data->GetId(), &dib, reinterpret_cast< char* >( image.bits() ), &viewer ) )
	{
		image = QImage();
	}

	image = image.mirrored();
#endif //WIN32API

#ifdef LINUXAPI 
	const long xLeft = 0;
	const long yLeft = 0;
	XImage xImage = PrepareXImage( rect, image );
	if ( !mapPaintToXImage( _data->GetId(), &xImage, xLeft, yLeft, &viewer) )
	{
		image = QImage();
	}
#endif //LINUXAPI
	
	//установка альфа канала в 255 для совместимости с Qt
 	uchar* arrayPixels = image.bits();
 	const int byteCount = image.byteCount();
 	const int alphaChanel = 255;
 	for ( int curentByte = 3; curentByte < byteCount; curentByte += 4 )
 	{
 		arrayPixels[ curentByte ] = alphaChanel;
 	}

	return DataImage( image, rect );
}