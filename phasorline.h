#ifndef PHASORLINE_H
#define PHASORLINE_H

#include <QtGui/QColor>
#include <QtWidgets/QGraphicsItem>
#include <QPainter>
#include "stream.h"
#include "phasorscene.h"

class PhasorLine : public QGraphicsItem
{
public:
    explicit PhasorLine(PhasorScene *phasorScene);

    QRectF boundingRect() const;
    //QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

    void setPhasorData(Stream *stream);
    
signals:
    
public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:            // TODO: pointer to Stream; treat as model; and check for it's existence on paint()
                    //       or, connect data by slot/signal; disconnect when selection changed
    PhasorScene *phasorScene;
    //Stream *stream;
    //double *mag;
    //double *phase;   // radians

};

#endif // PHASORLINE_H
