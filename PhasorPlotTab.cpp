#include "PhasorPlotTab.h"

void PhasorPlotTab::update()
{
    voltagePhasorScene->streamTableModelSelectionChanged(this->model, &this->index);
    currentPhasorScene->streamTableModelSelectionChanged(this->model, &this->index);
    voltagePlotScene->streamTableModelSelectionChanged(this->model, &this->index);
    currentPlotScene->streamTableModelSelectionChanged(this->model, &this->index);

    QListIterator<QGraphicsView*> i (views);
    while (i.hasNext()) {
        const QGraphicsView *view = i.next();
        view->scene()->update();        // TODO: may need to override this (or other function or slot) in subclass?
    }
}

void PhasorPlotTab::removeView()
{
    voltagePhasorScene->streamRemoved();
    currentPhasorScene->streamRemoved();
    voltagePlotScene->streamRemoved();
    currentPlotScene->streamRemoved();
}

PhasorPlotTab::PhasorPlotTab(QWidget *parent) : TabViewWidget(parent)
{
    QGridLayout *graphLayout = new QGridLayout(this);

    currentPhasorScene = new CurrentPhasorScene();
    voltagePhasorScene = new VoltagePhasorScene();
    currentPhasorView = new PhasorView(this);
    voltagePhasorView = new PhasorView(this);
    currentPhasorView->setScene(currentPhasorScene);
    voltagePhasorView->setScene(voltagePhasorScene);

    currentPlotScene = new CurrentPlotScene();
    voltagePlotScene = new VoltagePlotScene();
    currentPlotView = new PlotView(this);
    voltagePlotView = new PlotView(this);
    currentPlotView->setScene(currentPlotScene);
    voltagePlotView->setScene(voltagePlotScene);

    graphLayout->addWidget(voltagePhasorView, 0, 0, Qt::AlignLeft);
    graphLayout->addWidget(currentPhasorView, 1, 0, Qt::AlignLeft);
    graphLayout->addWidget(voltagePlotView, 0, 1, 0);
    graphLayout->addWidget(currentPlotView, 1, 1, 0);
    graphLayout->setColumnStretch(0, 0);
    graphLayout->setColumnStretch(1, 1);

    this->views.append(currentPhasorView);
    this->views.append(voltagePhasorView);
    this->views.append(currentPlotView);
    this->views.append(voltagePlotView);
}
