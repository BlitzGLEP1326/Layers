#pragma once

#include <QtCore/QRect>
#include <QtCore/QPair>
#include <QtCore/QPointF>
#include <QtCore/QVector>
#include <QtGui/QImage>

namespace GisToolWrapper 
{
    void EnableMessage( const bool enable );
	
	 //type declaration
	typedef long int DataId;
	typedef QPair< QImage, QRect > DataImage; 
	typedef int SelectContextId;
	
	//data api
	DataId OpenData( const QString& path );
	void CloseData( const DataId dataId );
	
	//image api
	QRectF GetImageSize( const DataId dataId );
	DataImage GetImage( const DataId dataId, const QRect& rect );
	
	//height api
	double GetHeightValue( const DataId dataId, const QPointF& point );
	QVector< double > GetHeightArray( const DataId dataId, const QPointF& beginPoint, 
		const QPointF& endPoint, const double countHeight );
	
	//coordinate api
	bool IsConvertSupported( const DataId dataId );
	QPointF GeoToPlane( const DataId dataId, const QPointF& point );
	QPointF PlaneToGeo( const DataId dataId, const QPointF& point );
	QPointF PictureToPlane( const DataId dataId, const QPointF& point );
	QPointF PlaneToPicture( const DataId dataId, const QPointF& point );
	QPointF GeoToGK( const DataId dataId, const QPointF& point );
	QPointF GKToGeo( const DataId dataId, const QPointF& point );
	
	//search/select api
	SelectContextId CreateSelectContext( const DataId dataId );
	void SetViewSelect( const DataId dataId, const SelectContextId selectContextId );
	void DeleteSelectContext( const SelectContextId selectContextId );
	
	//layer api
	int GetLayerCount( const DataId dataId );
	QString GetLayerName( const DataId dataId, const int numberLayer );
	void SelectLayer( const SelectContextId selectContextId,
		const int numberLayer, const bool access );

	//object api
	int GetRscObjectCountInLayer( const DataId dataId, const int numberLayer );
	QString GetRscObjectNameInLayer( const DataId dataId, const int numberLayer, const int numberObject );
	int GetRscObjectCodeInLayer( const DataId dataId, const int numberLayer, const int numberObject );
	void SelectObject( const SelectContextId selectContextId,
		const int objectCodeInLayer, const bool access );

	//scale api
	double GetRealShowScale( const DataId dataId );
	bool SetViewScale( const DataId dataId, const double scale );

	//bright api
	int GetBright( const DataId dataId );
	bool SetBright( const DataId dataId, const int brightValue );
	bool SetMtrBright( const DataId dataId, const int brightValue );
	bool SetRstBright( const DataId dataId, const int brightValue );

	//contrast api
	int GetContrast( const DataId dataId );
	bool SetContrast( const DataId dataId, const int contrastValue );
	bool SetMtrContrast( const DataId dataId, const int contrastValue );
	bool SetRstContrast( const DataId dataId, const int contrastValue );
}
