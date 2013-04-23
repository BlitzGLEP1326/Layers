#ifndef SCALEWIDJET_H
#define SCALEWIDJET_H

#include <QtGui/QWidget>

#include "ui_ScaleWidget.h"
#include "Atlas.h"

class ScaleWidget : public QWidget
{
	Q_OBJECT

public:
    ScaleWidget( QWidget* parent = 0 );
    ~ScaleWidget();

private slots:
	void on_scaleSlider_valueChanged( const int scale );
	void on_zoomInButton_clicked();
	void on_zoomOutButton_clicked();
	void VisibleMapHasChanged( MapSharedPointer map );

    void ScaleChanged();

private:
    void InsertScaleButtons();
    void UncheckAll();

private:
	Ui::ScaleWidgetClass _ui;
	QVector< qreal > _scalesSet;
	MapSharedPointer _map;
    QMap<qreal, QPushButton*> _scaleToButton;
};

#endif // SCALEWIDJET_H
