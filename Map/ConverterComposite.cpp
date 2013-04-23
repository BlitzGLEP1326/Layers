#include "Map.h"
#include "Data.h"
#include "Converter.h"

#include "ConverterComposite.h"

ConverterComposite::ConverterComposite( QSharedPointer< const Data > data )
    : Converter( data )
{
}

ConverterComposite::~ConverterComposite(void)
{
}

void ConverterComposite::AddConverter(QSharedPointer<Converter> converter,
                                      bool isConvertBack)
{
    _convertersChain.append( ConvertItem(converter, isConvertBack) );
}

QPointF ConverterComposite::Convert( const QPointF& point ) const
{
    QPointF tempPoint = point;
    foreach (ConvertItem item, _convertersChain)
    {
        tempPoint = item.second ? item.first->ConvertBack(tempPoint) :
                               item.first->Convert(tempPoint);
    }
    return tempPoint;
}


// метод ни разу не проверялся
QPointF ConverterComposite::ConvertBack( const QPointF& point ) const
{
    QPointF tempPoint = point;

    for (int i = _convertersChain.size() - 1; i >=0 ; i-- )
    {
        ConvertItem item = _convertersChain[i];
        tempPoint = item.second ? item.first->Convert(tempPoint) :
                               item.first->ConvertBack(tempPoint);
    }

    return tempPoint;
}
