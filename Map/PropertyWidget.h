#ifndef PROPERTY_H
#define PROPERTY_H

#include <QDialog>

#include "ui_PropertyWidget.h"
#include "Atlas.h"

class PropertyWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PropertyWidget( QWidget* parent = 0 );
	~PropertyWidget();
	void SetDefaultProperty();

private slots:
	void on_brightSlider_valueChanged( const int bright );
	void on_contrastSlider_valueChanged( const int contrast );
	void on_transparentSlider_valueChanged( const int transparent );
	void on_defaultPushButton_clicked();

	void VisibleMapHasChanged( MapSharedPointer map );

private:
	void showEvent( QShowEvent* e ); 

	Ui::PropertyClass _ui;
	QWeakPointer< Map > _map;
};

#endif // PROPERTY_H
