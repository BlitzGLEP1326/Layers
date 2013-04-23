#pragma once

#include <QObject>
#include <QtCore/QPointF>
#include <QtGui/QPixmap>
#include <QGraphicsItem>

#include "Atlas.h"

class Line : public QObject 
{
	Q_OBJECT

public:
	explicit Line( MapSharedPointer map, QObject* parent = 0 );
	~Line();

    void SetPoints( QList< QPointF > points );
	void SetVisible(bool isVisible);
//    void SetVisibleFuckLine(bool isVisible);
    void MarkPoint(QPointF startPoint);
    void Activate(bool isActivated);

private slots:
    void ChangeScale(qreal scale);
	void MousePositionChanged(QPointF point);

private:
	void DeleteAllItems();

	MapSharedPointer _map;
	QGraphicsItem* _group;
//	QGraphicsLineItem* _fuckLine;
	QPointF _lastPoint;
    QGraphicsEllipseItem *_selectedRect;
    const QPixmap _flagIcon;
};
