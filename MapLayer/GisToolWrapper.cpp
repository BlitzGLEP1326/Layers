#include "GisTool.h"

#include <QtCore/QString>
#include <QtCore/QTextCodec>

#include "GisToolWrapper.h"


void GisToolWrapper::EnableMessage( const bool enable )
{
    mapMessageEnable( enable ? 1: 0 );
}

GisToolWrapper::DataId GisToolWrapper::OpenData( const QString& path )
{
	return mapOpenData( path.toStdString().c_str(), GENERIC_READ ); 
}

void GisToolWrapper::CloseData( const DataId dataId )
{
	mapCloseData( dataId );
}

QRectF GisToolWrapper::GetImageSize( const DataId dataId )
{
	long width( 0 );
	long height( 0 );

	mapGetPictureSize( dataId, &width, &height );

	return QRectF( 0, 0, static_cast< qreal >( width ), static_cast< qreal >( height ) );
}
namespace GisToolWrapper 
{

#ifdef Q_OS_WIN
	typedef BITMAPINFOHEADER Dib;
	Dib PrepareDib( const QRect& rect )
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
		dib.biClrImportant = 2;
		dib.biClrUsed = 2;

		return dib;
	}
#endif //WIN32API

#ifdef Q_OS_LINUX
	typedef XIMAGEDESC XImage;
	XImage PrepareXImage( const QRect& rect, QImage& mapImage )
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
#endif	//LINUXAPI

}

GisToolWrapper::DataImage GisToolWrapper::GetImage( const GisToolWrapper::DataId dataId, const QRect& rect )
{
	RECT viewer;
	viewer.left = rect.left();
	viewer.top = rect.top();
	viewer.right = rect.right();
	viewer.bottom = rect.bottom();

	QImage image( rect.size(), QImage::Format_RGB32 );

#ifdef WIN32API
	Dib dib = PrepareDib( rect );
	
		
	if ( !mapPaintToDib( dataId, &dib, reinterpret_cast< char* >( image.bits() ), &viewer ) )
	{
		image = QImage();
	}
	
	image = image.mirrored();
#endif //WIN32API

#ifdef LINUXAPI 
	const long xLeft = 0;
	const long yLeft = 0;
	XImage xImage = PrepareXImage( rect, image );
	if ( !mapPaintToXImage( dataId, &xImage, xLeft, yLeft, &viewer) )
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

double GisToolWrapper::GetHeightValue( const GisToolWrapper::DataId dataId, const QPointF& point )
{
	const double height = mapGetHeightValue( dataId, point.x(), point.y() );
	return ( height == ERRORHEIGHT ) ? ERRORHEIGHT : height;
}

QVector< double > GisToolWrapper::GetHeightArray( const GisToolWrapper::DataId dataId, 
	const QPointF& beginPoint, const QPointF& endPoint, const double countHeight )
{
	QVector< double > arrayHeights;
	arrayHeights.resize( countHeight );

	DOUBLEPOINT firstPoint;
	firstPoint.x = beginPoint.x();
	firstPoint.y = beginPoint.y();

	DOUBLEPOINT secondPoint;
	secondPoint.x = endPoint.x();
	secondPoint.y = endPoint.y();

	if ( mapGetHeightArray( dataId, arrayHeights.data(), countHeight, &firstPoint, &secondPoint ) )
	{
		return arrayHeights;
	}
	else
	{
		arrayHeights.fill( ERRORHEIGHT, countHeight );
		return arrayHeights;
	}
}

bool GisToolWrapper::IsConvertSupported( const GisToolWrapper::DataId dataId )
{
	return mapIsGeoSupported( dataId );
}

QPointF GisToolWrapper::GeoToPlane( const GisToolWrapper::DataId dataId, const QPointF& point )
{
	double x = point.x();
	double y = point.y();
	if ( IsConvertSupported( dataId ) && mapGeoToPlane( dataId, &x, &y ) )
	{
		return QPointF( x, y );
	}
	else
	{
		return QPointF( 0, 0 );
	}
}

QPointF GisToolWrapper::PlaneToGeo( const GisToolWrapper::DataId dataId, const QPointF& point )
{
	double x = point.x();
	double y = point.y();
	if ( IsConvertSupported( dataId ) && mapPlaneToGeo( dataId, &x, &y ) )
	{
		return QPointF( x, y );
	}
	else
	{
		return QPointF( 0, 0 );
	}	
}

QPointF GisToolWrapper::PictureToPlane( const GisToolWrapper::DataId dataId, const QPointF& point )
{
	double x =  point.x();
	double y = point.y();
	mapPictureToPlane( dataId, &x, &y );
	return QPointF( x, y );
}

QPointF GisToolWrapper::PlaneToPicture( const GisToolWrapper::DataId dataId, const QPointF& point )
{
	double x =  point.x();
	double y = point.y();
	mapPlaneToPicture( dataId, &x, &y );
	return QPointF( x, y );
}

#define PI2	1.57079632679489661923132169163975
#include <math.h>

void Geo42ToGK(double Bl,double LG,double& x,double& y)
{

	double B=Bl;
	double L=LG;
	double Lg=L*90/PI2;
	double n=floor((6+Lg)/6);
	double l=(Lg-(3+6*(n-1)))/57.29577951;
	double sb=sin(B),s2b=sin(2*B);
	double sb2=sb*sb;
	double sb4=sb2*sb2;
	double sb6=sb2*sb2*sb2;
	double cb=cos(B);
	x=6367558.4968*B-s2b*(16002.89+66.9607*sb2+0.3515*sb4-
		l*l*(1594561.25+5336.535*sb2+26.79*sb4+0.149*sb6+
		l*l*(672483.4-811219.9*sb2+5420*sb4-10.6*sb6+
		l*l*(278194-830174*sb2+572434*sb4-16010*sb6+
		l*l*(109500-574700*sb2+863700*sb4-398600*sb6)))));
	y=(5+10*n)*100000+l*cb*(6378245+21346.1415*sb2+107.159*sb4+0.5977*sb6+
		l*l*(1070204.16-2136826.66*sb2+17.98*sb4-11.99*sb6+
		l*l*(270806-1523417*sb2+1327645*sb4-21701*sb6+
		l*l*(79690-866190*sb2+1730360*sb4-945460*sb6))));
}

void GKToGeo42(double x,double y,double& B,double& L)
{
	double bet=x/6367558.4968;
	double n=floor(y/1000000);
	double sb,s2b,s4b;
	sb=sin(bet);
	s2b=sb*sb;
	s4b=s2b*s2b;
	double B0=bet+sin(2*bet)*(0.00252588685-0.00001491860*s2b+0.00000011904*s4b);
	double z0=(y-(10*n+5)*100000)/(6378245*cos(B0));
	double z02=z0*z0;
	double sB=sin(B0);
	double s2B=sB*sB;
	double s4B=s2B*s2B;
	double s6B=s4B*s2B;
	double dB;
	double ldp;
	dB=-z02*sin(2*B0)*(0.251684631-0.003369263*s2B+0.000011276*s4B-
		z02*(0.10500614-0.04559916*s2B+0.00228901*s4B-0.00002987*s6B-
		z02*(0.042858-0.025318*s2B+0.014346*s4B-0.001264*s6B-
		z02*(0.01672-0.0063*s2B+0.01188*s4B-0.00328*s6B))));
	ldp=z0*(1-0.0033467108*s2B-0.0000056002*s4B-0.0000000187*s6B-
		z02*(0.16778975+0.16273586*s2B-0.0005249*s4B-0.00000846*s6B-
		z02*(0.0420025+0.1487407*s2B+0.0059420*s4B-0.000015*s6B-
		z02*(0.01225+0.09477*s2B+0.03282*s4B-0.00034*s6B-
		z02*(0.0038+0.0524*s2B+0.0482*s4B+0.0032*s6B)))));
	B=B0+dB;
	L=6*(n - 0.5)/57.29577951 + ldp;
}


QPointF GisToolWrapper::GeoToGK( const DataId /*dataId*/, const QPointF& point )
{
	double x,y;
	Geo42ToGK(point.x(),point.y(),x,y);
	return QPointF( x, y );
}


QPointF GisToolWrapper::GKToGeo( const DataId /*dataId*/, const QPointF& point )
{
	double B,L;
	GKToGeo42(point.x(),point.y(),B,L);
	return QPointF( B, L );

}

GisToolWrapper::SelectContextId GisToolWrapper::CreateSelectContext( const GisToolWrapper::DataId dataId )
{
	 return mapCreateMapSelectContext( dataId );
}
void GisToolWrapper::SetViewSelect( const GisToolWrapper::DataId dataId, 
	const GisToolWrapper::SelectContextId selectContextId )
{
	mapSetViewSelect( dataId, selectContextId );
}

void GisToolWrapper::DeleteSelectContext( const GisToolWrapper::SelectContextId selectContextId )
{
	mapDeleteSelectContext( selectContextId );
}

int GisToolWrapper::GetLayerCount( const GisToolWrapper::DataId dataId )
{
    int foo = mapGetLayerCount( dataId );
    return foo > 100 ? 0 : foo;	//TODO linux-gistool hack
}

namespace GisToolWrapper
{
    QTextCodec* /*const*/ GetTextCodec()
	{
	#ifdef Q_OS_WIN
		return QTextCodec::codecForName("Windows-1251");
	#else
		return QTextCodec::codecForName("KOI8-R");
	#endif
	}
}

QString GisToolWrapper::GetLayerName( const GisToolWrapper::DataId dataId, const int numberLayer )
{
	const char* name( mapGetLayerName( dataId, numberLayer ) );
	return GetTextCodec()->toUnicode( name );
}


void GisToolWrapper::SelectLayer( const GisToolWrapper::SelectContextId selectContextId, 
	const int numberLayer, const bool access )
{
	mapSelectLayer( selectContextId, numberLayer, access ? 1 : 0 );
}


int GisToolWrapper::GetRscObjectCountInLayer( const GisToolWrapper::DataId dataId, const int numberLayer )
{
	return mapRscObjectCountInLayer( dataId, numberLayer );
}


QString GisToolWrapper::GetRscObjectNameInLayer( const GisToolWrapper::DataId dataId, 
	const int numberLayer, const int numberObject )
{
	const char* name( mapRscObjectNameInLayer( dataId, numberLayer, numberObject ) );
	return GetTextCodec()->toUnicode( name );
}

int GisToolWrapper::GetRscObjectCodeInLayer( const DataId dataId, 
	const int numberLayer, const int numberObject )
{
	return mapRscObjectCodeInLayer( dataId, numberLayer, numberObject );
}

void GisToolWrapper::SelectObject( const GisToolWrapper::SelectContextId selectContextId, 
	const int objectCodeInLayer, const bool access )
{
	mapSelectObject( selectContextId, objectCodeInLayer, access ? 1 : 0 );
}


double GisToolWrapper::GetRealShowScale( const GisToolWrapper::DataId dataId )
{
	return mapGetRealShowScale( dataId );
}

bool GisToolWrapper::SetViewScale( const GisToolWrapper::DataId dataId, const double scale )
{
	long x( 0 );
	long y( 0 );

	return ( mapSetViewScale( dataId, &x, &y, scale ) ? true : false );
}

int GisToolWrapper::GetBright( const GisToolWrapper::DataId dataId )
{
	return mapGetBright( dataId );
}

bool GisToolWrapper::SetBright( const GisToolWrapper::DataId dataId, const int brightValue )
{
	return ( mapSetBright( dataId, brightValue )? true : false );
}

bool GisToolWrapper::SetMtrBright( const GisToolWrapper::DataId dataId, const int brightValue )
{
	return ( mapSetMtrBright( dataId, brightValue )? true : false );
}

bool GisToolWrapper::SetRstBright( const GisToolWrapper::DataId dataId, const int brightValue )
{
	const int fileNumberInChain( 1 );
	return ( mapSetRstBright( dataId, brightValue, fileNumberInChain ) ? true : false );
}

int GisToolWrapper::GetContrast( const GisToolWrapper::DataId dataId )
{
	return mapGetContrast( dataId );
}

bool GisToolWrapper::SetContrast( const GisToolWrapper::DataId dataId, const int contrastValue )
{
	return ( mapSetContrast( dataId, contrastValue ) ? true : false );
}

bool GisToolWrapper::SetMtrContrast( const GisToolWrapper::DataId dataId, const int contrastValue )
{
	return ( mapSetMtrContrast( dataId, contrastValue ) ? true : false );
}

bool GisToolWrapper::SetRstContrast( const GisToolWrapper::DataId dataId, const int contrastValue )
{
	const int fileNumberInChain( 1 );
	return ( mapSetRstContrast( dataId, contrastValue, fileNumberInChain ) ? true : false );
}
