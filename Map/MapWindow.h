#ifndef MapWindow_H
#define MapWindow_H

#include <QtGui/QWidget>
#include <QtGui/QActionGroup>
#include <QtGui/QLabel>

#include "Atlas.h"
#include "LibraryDeclaration.h"

namespace Ui{
	class MapWindowClass;
}

class MapMenuWidget;
class MapInfoWidget;
class DistanceWidget;
class QPushButton;

class MAP_EXPORT MapWindow : public QWidget
{
	Q_OBJECT

public:
    MapWindow( QWidget* parent = 0 );
    ~MapWindow();

signals:
    void WidgetResize( QRect rect );

private slots:
	void VisibleMapHasChanged( MapSharedPointer map );
	void ShowDistanceWidget();
	
private:
    bool eventFilter( QObject* object, QEvent* event );

	Ui::MapWindowClass* _ui;
	MapMenuWidget* _mapMenu;
	MapInfoWidget* _mapInfo;
	DistanceWidget* _distanceWidget;
	QSharedPointer<Map> _map;
};

#endif // MapWindow_H
