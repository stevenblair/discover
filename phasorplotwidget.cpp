#include "phasorplotwidget.h"

void PhasorPlotWidget::update()
{
    currentPhasorScene->streamTableModelSelectionChanged(this->model, &this->index);
    voltagePhasorScene->streamTableModelSelectionChanged(this->model, &this->index);

    QListIterator<QGraphicsView*> i (views);
    while (i.hasNext()) {
        const QGraphicsView *view = i.next();
        view->scene()->update();        // TODO: may need to override this (or other function or slot) in subclass?
    }
}

void PhasorPlotWidget::removeView()
{
    currentPhasorScene->streamRemoved();
    voltagePhasorScene->streamRemoved();
}

PhasorPlotWidget::PhasorPlotWidget(QWidget *parent) : TabViewWidget(parent)
{
    QGridLayout *graphLayout = new QGridLayout(this);

    currentPhasorScene = new CurrentPhasorScene();
    voltagePhasorScene = new VoltagePhasorScene();
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPhasorScene, SLOT(streamSelectionChanged(Stream*)));    // TODO: connect directly between TableView and Phasors?
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePhasorScene, SLOT(streamSelectionChanged(Stream*)));
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
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPlotScene, SLOT(streamSelectionChanged(Stream*)));
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePlotScene, SLOT(streamSelectionChanged(Stream*)));

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
