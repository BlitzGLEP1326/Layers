#ifndef MAPINFOWIDGET_H
#define MAPINFOWIDGET_H

#include <QWidget>

#include "ui_MapInfoWidget.h"
#include "Atlas.h"

class MapInfoWidget : public QWidget
{
	Q_OBJECT

public:
	MapInfoWidget( QWidget* parent = 0 );
	~MapInfoWidget();

private slots:
    void MousePositionChanged( QPointF logicPoint );
	void ScaleHasChanged( const qreal scale );
	void VisibleMapHasChanged( MapSharedPointer map );
	void CurrentMapHasChanged( MapSharedPointer map, Map::DataType type );
	
private:
	void paintEvent( QPaintEvent* paintEvent );
	void showEvent( QShowEvent* e );
	void closeEvent( QCloseEvent* e );

	Ui::MapInfoWidgetClass _ui;
	MapSharedPointer _visibleMap;
	MapSharedPointer _currentMatrixMap;
};

#endif // MAPINFOWIDGET_H
