#include "MapWindow.h"
#include "PropertyWidget.h"

PropertyWidget::PropertyWidget( QWidget* parent )
        : QWidget( parent )
{
	_ui.setupUi( this );
	setAttribute( Qt::WA_NoMousePropagation );
}

PropertyWidget::~PropertyWidget()
{
}

void PropertyWidget::on_brightSlider_valueChanged( const int bright )
{
	if ( !_map )
		return;

	_map.toStrongRef()->SetBright( bright );
}

void PropertyWidget::on_contrastSlider_valueChanged( const int contrast )
{
	if ( !_map )
		return;

	_map.toStrongRef()->SetContrast( contrast );
}

void PropertyWidget::on_transparentSlider_valueChanged( const int transparent )
{
	if ( !_map )
		return;

	_map.toStrongRef()->SetTransparent( transparent );
}

void PropertyWidget::on_defaultPushButton_clicked()
{
	SetDefaultProperty();
}

void PropertyWidget::SetDefaultProperty()
{
	const int defaultBrightValue = 0;
	_ui.brightSlider->setSliderPosition( defaultBrightValue );
	const int defaultContrastValue = 0;
	_ui.contrastSlider->setSliderPosition( defaultContrastValue );
	const int defaultTransparentValue = 50;
	_ui.transparentSlider->setSliderPosition( defaultTransparentValue );
}

void PropertyWidget::showEvent( QShowEvent* e )
{
   QWidget::showEvent( e );

	if ( !_map )
		return;
	
	blockSignals( true );
	_ui.brightSlider->setValue( _map.toStrongRef()->GetBright() );
	_ui.contrastSlider->setValue( _map.toStrongRef()->GetContrast() );
	_ui.transparentSlider->setValue( _map.toStrongRef()->GetTransparent() );
	blockSignals( false );
}

void PropertyWidget::VisibleMapHasChanged( MapSharedPointer map )
{
	_map = map;
}