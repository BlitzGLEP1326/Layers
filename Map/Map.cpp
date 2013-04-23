#include "Map.h"
#include "Data.h"
#include "HeightFinder.h"
#include "Converter.h"
#include "ConverterPixelToPlane.h"
#include "ConverterGeoToPlane.h"
#include "ConverterGeoToGK.h"
#include "ConverterComposite.h"
#include "MapImage.h"
#include "ImageProperty.h"
#include "CompositionObject.h"
#include "Scale.h"
#include "Line.h"

//#include "graphicitemmanager.h"

Map::Map( QSharedPointer< const Data > data, QObject* parent )
	: QObject( parent )	
	, _data( data )
	, _scene( new QGraphicsScene() )
	, _mapImage( new MapImage( data ) )
	, _scale( new Scale( data ) )
	, _heightFinder( new HeightFinder( data ) )
	, _compositionObject( new CompositionObject( data ) )
{
	_scene->addItem( _mapImage.data() );
    _scene->setBackgroundBrush(Qt::white);
	
	_converterArray.insert( LogicToPlane, QSharedPointer< Converter >( new ConverterPixelToPlane( _data, _scale.data()) ) );	
	_converterArray.insert( GeoToPlane, QSharedPointer< Converter >( new ConverterGeoToPlane( _data ) ) );
	_converterArray.insert( GeoToGK, QSharedPointer< Converter >( new ConverterGeoToGK( _data ) ) );

    ConverterComposite *planeToGk = new ConverterComposite( _data );
    planeToGk->AddConverter( _converterArray.value(GeoToPlane), true );
    planeToGk->AddConverter( _converterArray.value(GeoToGK) );
    _converterArray.insert( PlaneToGK, QSharedPointer< Converter >( planeToGk ) );

    ConverterComposite *logicToGk = new ConverterComposite( _data );
    logicToGk->AddConverter( _converterArray.value(LogicToPlane) );
    logicToGk->AddConverter( _converterArray.value(PlaneToGK) );
    _converterArray.insert( LogicToGK, QSharedPointer< Converter >( logicToGk ) );

	connect( _mapImage.data(), SIGNAL( MousePositionChanged( QPointF ) ),
             this, SIGNAL( MousePositionChanged( QPointF ) ) );
	connect( _mapImage.data(), SIGNAL( MouseClick( Qt::MouseButton, QPointF ) ),
					this, SIGNAL( MouseClick( Qt::MouseButton, QPointF ) ) );

        connect( this, SIGNAL( scaleHasChanged( qreal ) ), _mapImage.data(), SLOT( ScaleChanged( qreal ) ) );
}

Map::~Map()
{
	if (  !_scene || _scene->views().isEmpty() )
		return;
	
	_scene->views()[ 0 ]->setDragMode( QGraphicsView::NoDrag );
}

//scale
qreal Map::GetBaseScale() const
{
	return _scale->GetBaseScale();
}

qreal Map::GetScale() const
{
	return _scale->GetScale();
}

void Map::SetScale( const qreal scale )
{
	_scale->SetScale( scale );
	

	emit scaleHasChanged( _scale->GetScalingCoefficient() );// for scenery

	if ( _scene->views().isEmpty() )
		return;

	 QTransform transform( _scale->GetTransform() );
	 _scene->views()[ 0 ]->setTransform( transform );

	 emit ScaleHasChanged( scale );//for MapInfo
}

//bright
int Map::GetBright() const
{
	return _mapImage.data()->_imageProperty.GetBright();
}

void Map::SetBright( const int bright )
{
	_mapImage.data()->_imageProperty.SetBright( bright );
	_mapImage.data()->Update();
}

//contrast
int Map::GetContrast() const
{
	return _mapImage.data()->_imageProperty.GetContrast();
}

void Map::SetContrast( const int contrast )
{
	_mapImage.data()->_imageProperty.SetContrast( contrast );
	_mapImage.data()->Update();
}

//transparent
int Map::GetTransparent() const
{
	qreal alpha =_mapImage.data()->_imageProperty.GetTransparent();
	return ( alpha == 0 ) ? alpha : alpha * 100;
}

void Map::SetTransparent( const int alphaChanel )
{
	_mapImage.data()->_imageProperty.SetTransparent( alphaChanel / 100.0 );
	_mapImage.data()->Update();
}

//get height
double Map::GetHeight( const QPointF& point ) const
{
	return _heightFinder->GetHeight( point );
}

QVector< double > Map::GetHeight( const QPointF& beginPoint, const QPointF& endPoint, const double countHeight ) const
{
	return _heightFinder->GetHeight( beginPoint, endPoint, countHeight );
}

//converter
bool Map::IsConvertSupported() const
{
	return GisToolWrapper::IsConvertSupported( _data->GetId() );
}

QPointF Map::Convert( const QPointF& point, ConvertType convertType ) const
{
	QSharedPointer< Converter > converter( _converterArray.value( convertType ) );
	return converter->Convert( point );
}

QPointF Map::ConvertBack( const QPointF& point, ConvertType convertType ) const
{
	QSharedPointer< Converter > converter( _converterArray.value( convertType ) );
	return converter->ConvertBack( point );
}

//Layers
void Map::EnableLayer( const QString& nameLayer )
{
	_compositionObject->EnableLayer( nameLayer );
}

void Map::DisableLayer( const QString& nameLayer )
{
	_compositionObject->DisableLayer( nameLayer );
}

QStringList Map::GetListNamesLayers() const
{
	return _compositionObject->GetListNamesLayers();
}

bool Map::IsVisibleLayer( const QString& nameLayer ) const
{
	return _compositionObject->IsVisibleLayer( nameLayer );
}

//Objects
void Map::EnableObject( const QString& nameLayer, const QString& nameObject )
{
	_compositionObject->EnableObject( nameLayer, nameObject );
}

void Map::DisableObject( const QString& nameLayer, const QString& nameObject )
{
	_compositionObject->DisableObject( nameLayer, nameObject );
}	

const QStringList Map::GetListNamesObjects( const QString& nameLayer ) const
{
	return _compositionObject->GetListNamesObjects( nameLayer );
}

bool Map::IsVisibleObject( const QString& nameLayer, const QString& nameObject ) const
{
	return _compositionObject->IsVisibleObject( nameLayer, nameObject );
}

//Update
void Map::Update()
{
	_mapImage.data()->Update();
}

//show
void Map::Show( QGraphicsView* const view )
{
	if ( !view )
		return;
  
	view->setTransform( _scale->GetTransform() );
	view->setScene( _scene.data() );
	view->setDragMode( QGraphicsView::ScrollHandDrag );
	SetPos(GetPos());
}

void Map::DrawItem( QGraphicsItem* const item )
{
	_scene->addItem( item );
}

void Map::EraseItem( QGraphicsItem* const item )
{
    if (_scene.isNull())
        return;
    _scene->removeItem( item );
}

//Info about  map 
int Map::GetId() const
{
	return _data->GetId();
}

QString Map::GetName() const
{
	return _data->GetName();
}

QString Map::GetPath() const
{
	return _data->GetPath();
}

Map::DataType Map::GetType() const
{
	return _data->GetType();
}

void Map::SetCursor( const QCursor& cursor )
{
	_mapImage->setCursor( cursor );
}

void Map::NoDrawing(bool flNoDraw)
{
    _mapImage->NoDrawing(flNoDraw);
}

void Map::Wait()
{
    _mapImage->Wait();
}

QPointF Map::GetPos()
{
	return _position;
}

void Map::SetPos( QPointF center )
{
    if (!_scene->views().isEmpty())
    {
        QGraphicsView* view = _scene->views()[0];
        QRectF rect = view->rect();
        QPointF currentCenter = view->mapToScene(rect.center().toPoint());

        QPoint offset = (currentCenter - center).toPoint();
        view->translate( offset.x(), offset.y() );
    }
		
    _position = center;
}

void Map::CenterOnMark(QPointF pos)
{
    if (!_scene->views().isEmpty())
    {
        QGraphicsView* view = _scene->views()[0];

        view->centerOn( pos );
    }
}
