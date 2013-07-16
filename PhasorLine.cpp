#include "phasorline.h"
#include <qmath.h>


void PhasorLine::setPhasorData(Stream *stream)
{
    this->stream = stream;

    update();
}

PhasorLine::PhasorLine(PhasorScene *phasorScene)
{
    this->phasorScene = phasorScene;
}

QRectF PhasorLine::boundingRect() const
{
    return QRectF(0.0, 0.0, 200.0, 200.0);//QRectF(0.0, 0.0, mag * cos(phase), -1 * mag * sin(phase));
}

void PhasorLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    if (stream != NULL) {
        painter->drawLine(0.0, 0.0, *mag * cos(*phase), -1 * *mag * sin(*phase));
        painter->drawLine(0.0, 0.0, *mag * cos(*phase), -1 * *mag * sin(*phase));
    }
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
