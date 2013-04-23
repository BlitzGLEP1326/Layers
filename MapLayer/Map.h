#pragma once

#include <QtCore/QHash>
#include <QtCore/QPointF>
#include <QtCore/QSharedPointer>
#include <QtGui/QGraphicsItem>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>
#include <QtCore/QMetaType>

//#include "LibraryDeclaration.h"
#include "dll.h"

class Data;
class ImageProperty;
class MapImage;
class Scale;
class Converter;
class HeightFinder;
class CompositionObject;

class MAP_LAYER_EXPORT Map : public QObject
{
	
	Q_OBJECT

public:

	//тип данных
	enum DataType
	{
		WrongDataType,
		Vector,
		Matrix,
		Raster
	};
		
	//тип матрицы высот
	enum HeightType
	{
		Relief,
		Topography, //надстройки
		ReliefAndTopography
	};

	//тип конвертации
	enum ConvertType
	{
		LogicToPlane,
		GeoToPlane,
        GeoToGK,
        PlaneToGK,
        LogicToGK
	};

	explicit Map( QSharedPointer< const Data > data, QObject* parent = 0 );
	~Map();
	
	//scale
	qreal GetBaseScale() const;
	qreal GetScale() const;
	void SetScale( const qreal scale );
	
	//bright
	int GetBright() const;
	void SetBright( const int bright );

	//contrast
	int GetContrast() const;
	void SetContrast( const int contrast );

	//transparent
	int GetTransparent() const;
	void SetTransparent( const int alphaChanel );
	
    //height
	double GetHeight( const QPointF& point ) const;
	QVector< double > GetHeight( const QPointF& beginPoint, const QPointF& endPoint, const double countHeight ) const;
	
	//converter
	bool IsConvertSupported() const;
	QPointF Convert( const QPointF& point, ConvertType convertType ) const;
	QPointF ConvertBack( const QPointF& point, ConvertType convertType ) const;

	//Layers
	void EnableLayer( const QString& nameLayer );
	void DisableLayer( const QString& nameLayer );
	QStringList GetListNamesLayers() const;
	bool IsVisibleLayer( const QString& nameLayer ) const;

	//Objects
	void EnableObject( const QString& nameLayer, const QString& nameObject );
	void DisableObject( const QString& nameLayer, const QString& nameObject );
	const QStringList GetListNamesObjects( const QString& nameLayer ) const;
	bool IsVisibleObject( const QString& nameLayer, const QString& nameObject ) const;
	
	//update
	void Update();
	
	//draw operations
	void Show( QGraphicsView* const view );
	void DrawItem( QGraphicsItem* const item );
	void EraseItem( QGraphicsItem* const item );

	//Info about map
	int GetId() const;
	QString GetName() const;
	QString GetPath() const;
	DataType GetType() const;
	
	//Viewport position 
	QPointF GetPos();
	void SetPos(QPointF pos);
    void CenterOnMark( QPointF pos );
	
	// Set cursor into map
	void SetCursor( const QCursor& cursor );
	
	// work for raster map
	// class Raster	
	// QRect SelectGeoGrid( QRect );
	// int GetGeoCode( QPointF );
	// _Data
	//void SetLineageMode( bool lineageMode );
	
	//Synchronized for working thread 
    void NoDrawing(bool flNoDraw);
    void Wait();



signals:
    void MousePositionChanged( QPointF );
	void MouseClick( Qt::MouseButton, QPointF );
	void scaleHasChanged( qreal ); //delete this signal
	void ScaleHasChanged( qreal );

private:
	QSharedPointer< const Data > _data;
	QScopedPointer< QGraphicsScene > _scene;
	QScopedPointer< MapImage > _mapImage; 
	QScopedPointer< Scale > _scale;
	QScopedPointer< HeightFinder > _heightFinder;
	QScopedPointer< CompositionObject > _compositionObject;
	QHash< ConvertType, QSharedPointer< Converter > > _converterArray;
	QPointF _position;
};

Q_DECLARE_METATYPE( Map::DataType )
