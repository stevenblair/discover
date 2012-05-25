#include "phasorline.h"

PhasorLine::PhasorLine(double mag, double phase)
{
    this->mag = mag;
    this->phase = phase;
}

QRectF PhasorLine::boundingRect() const
{
    return QRectF(100.0, 50.0, 110.0, 70.0);
}

void PhasorLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->drawLine(15, 54, 94, 54);
}

void PhasorLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void PhasorLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /*if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }*/
    QGraphicsItem::mouseMoveEvent(event);
}

void PhasorLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
