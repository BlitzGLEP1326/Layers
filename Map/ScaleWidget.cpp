#include "MapWindow.h"
#include "ScaleWidget.h"

ScaleWidget::ScaleWidget( QWidget* parent )
    : QWidget( parent )
{
    _ui.setupUi( this );
    setWindowFlags( Qt::FramelessWindowHint );

    _scalesSet.append( 10000 );
    _scalesSet.append( 25000 );
    _scalesSet.append( 50000 );
    _scalesSet.append( 100000 );
    _scalesSet.append( 200000 );
    _scalesSet.append( 500000 );
    _scalesSet.append( 1000000 );
    _scalesSet.append( 2000000 );

    InsertScaleButtons();
}

ScaleWidget::~ScaleWidget()
{
}

void ScaleWidget::InsertScaleButtons()
{
    for (int i = 0; i < _scalesSet.size(); ++i)
    {
        qreal scale = _scalesSet.at(i);
        QPushButton *button = new QPushButton;
        button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        connect(button, SIGNAL(clicked()), this, SLOT(ScaleChanged()));
        QString number = QString("%L1").arg(scale, 10, 'f', 0, QLatin1Char(' '));
        QString str = "- 1:" + number.trimmed();
        button->setText(str);

        button->setFlat(true);
        button->setCheckable(true);
        _scaleToButton[i] = button;
        _ui.frame->layout()->addWidget(button);
    }
}

void ScaleWidget::on_scaleSlider_valueChanged( const int scale )
{
    if ( !_map || scale >= _scalesSet.size() || scale < 0 )
        return;

    _map->SetScale( _scalesSet.at( scale ) );
    UncheckAll();
    _scaleToButton.value(scale)->setChecked(true);
}

void ScaleWidget::on_zoomInButton_clicked()
{
    _ui.scaleSlider->setValue( _ui.scaleSlider->value() - 1 );
}

void ScaleWidget::on_zoomOutButton_clicked()
{
    _ui.scaleSlider->setValue( _ui.scaleSlider->value() + 1 );
}

void ScaleWidget::VisibleMapHasChanged( MapSharedPointer map )
{
    if(_map == map)
        return;

    _map = map;

    if ( !map )
        return;

    //catch exeption
    const int scaleSliderValue( _scalesSet.indexOf( map->GetScale() ) );
    _ui.scaleSlider->setValue( scaleSliderValue );
}

void ScaleWidget::ScaleChanged()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    _ui.scaleSlider->setValue( _scaleToButton.key(button) );
}

void ScaleWidget::UncheckAll()
{
    foreach (QPushButton *button, _scaleToButton)
    {
        button->setChecked(false);
    }
}
