#ifndef PHASORLINE_H
#define PHASORLINE_H

#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>
#include <QPainter>

class PhasorLine : public QGraphicsItem
{
public:
    explicit PhasorLine(double mag, double phase);

    QRectF boundingRect() const;
    //QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
    
signals:
    
public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    double mag;
    double phase;   // radians
};

#endif // PHASORLINE_H
