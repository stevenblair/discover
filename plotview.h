#ifndef PLOTVIEW_H
#define PLOTVIEW_H

#include <QGraphicsView>
#include "phasorview.h"

#define PLOT_VIEW_WIDTH     600
#define PLOT_VIEW_HEIGHT    PHASOR_VIEW_WIDTH

class PlotView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PlotView(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PLOTVIEW_H
