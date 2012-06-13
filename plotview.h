#ifndef PLOTVIEW_H
#define PLOTVIEW_H

#include <QGraphicsView>
#include "phasorview.h"

#define PLOT_VIEW_WIDTH     550
#define PLOT_VIEW_HEIGHT    PHASOR_VIEW_WIDTH

class PlotView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PlotView(QObject *parent = 0);

signals:
    
public slots:

protected:
    //Holds the current centerpoint for the view, used for panning and zooming
    QPointF CurrentCenterPoint;

    //From panning the view
    QPoint LastPanPoint;

    //Set the current centerpoint in the
    void SetCenter(const QPointF& centerPoint);
    QPointF GetCenter() { return CurrentCenterPoint; }

    //Take over the interaction
    //virtual void mousePressEvent(QMouseEvent* event);
    //virtual void mouseReleaseEvent(QMouseEvent* event);
    //virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    //virtual void resizeEvent(QResizeEvent* event);
    
};

#endif // PLOTVIEW_H
