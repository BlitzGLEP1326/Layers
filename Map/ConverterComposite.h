#pragma once

class ConverterComposite : public Converter
{
public:

    explicit ConverterComposite( QSharedPointer< const Data > data );
    ~ConverterComposite(void);

    void AddConverter(QSharedPointer< Converter > converter,
                      bool isConvertBack = false);

    QPointF Convert( const QPointF& point ) const;
    QPointF ConvertBack( const QPointF&  point ) const;

private:

    typedef QPair<QSharedPointer< Converter >, bool> ConvertItem;

    QVector< ConvertItem > _convertersChain;
};
