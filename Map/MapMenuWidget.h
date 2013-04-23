#ifndef MAPMENU_H
#define MAPMENU_H

#include <QWidget>

#include "ui_MapMenuWidget.h"
#include "Atlas.h"

class ScaleWidget;
class QMenu;
class QMenuBar;

class MapMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapMenuWidget( Atlas* const atlas, QWidget* parent = 0 );
    ~MapMenuWidget();

signals:
    void ShowDistanceWidget();

public slots:
    void SetEnableDistance(bool isEnabled);

private slots:
	void ShowMapsList();
	void VisibleMapHasChanged( MapSharedPointer );
	void on_hideButton_clicked( bool checked );

private:
    void paintEvent( QPaintEvent* paintEvent );
	
	void CreateWidgetGeometry();

    QMenu* CreateMenu( QWidget* const widget, const QString& menuName ) const;

    Ui::MapMenuWidget _ui;
    QPushButton *_distanceButton;
	QMenuBar* _mapMenuBar;
	
	QMenu* _mapsListMenu;
	
	QWidget* _objectsList;
	QWidget* _propertys;

	QColor _background;

};

#endif // MAPMENU_H
