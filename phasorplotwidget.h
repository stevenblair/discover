#ifndef PHASORPLOTWIDGET_H
#define PHASORPLOTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "tabviewwidget.h"
#include "phasorscene.h"
#include "phasorview.h"
#include "plotscene.h"
#include "plotview.h"

class PhasorPlotWidget : public TabViewWidget
{
    Q_OBJECT
public:
    explicit PhasorPlotWidget(QWidget *parent = 0);
    void update();
    void removeView();
    
signals:
    
public slots:

private:
    QList<QGraphicsView*> views;

    CurrentPhasorScene *currentPhasorScene;
    VoltagePhasorScene *voltagePhasorScene;
    CurrentPlotScene *currentPlotScene;
    VoltagePlotScene *voltagePlotScene;
    PhasorView *currentPhasorView;
    PhasorView *voltagePhasorView;
    PlotView *currentPlotView;
    PlotView *voltagePlotView;
    
};

#endif // PHASORPLOTWIDGET_H
