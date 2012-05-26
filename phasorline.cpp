#include "phasorline.h"
#include <qmath.h>

PhasorLine::PhasorLine(double mag, double phase)
{
    this->mag = mag;
    this->phase = phase;
}

void PhasorLine::setPhasorData(double mag, double phase)
{
    this->mag = mag;
    this->phase = phase;

    update();
}

QRectF PhasorLine::boundingRect() const
{
    return QRectF(0.0, 0.0, mag * cos(phase), -1 * mag * sin(phase));
}

void PhasorLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->drawLine(0.0, 0.0, mag * cos(phase), -1 * mag * sin(phase));
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
