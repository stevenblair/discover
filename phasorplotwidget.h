#ifndef PHASORPLOTWIDGET_H
#define PHASORPLOTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "phasorscene.h"
#include "phasorview.h"
#include "plotscene.h"
#include "plotview.h"

class PhasorPlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PhasorPlotWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:
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
