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

PhasorPlotWidget::PhasorPlotWidget(QWidget *parent) : TabViewWidget(parent)
{
    QGridLayout *graphLayout = new QGridLayout;

    currentPhasorScene = new CurrentPhasorScene();
    voltagePhasorScene = new VoltagePhasorScene();
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPhasorScene, SLOT(streamSelectionChanged(Stream*)));    // TODO: connect directly between TableView and Phasors?
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePhasorScene, SLOT(streamSelectionChanged(Stream*)));
    currentPhasorView = new PhasorView;
    voltagePhasorView = new PhasorView;
    currentPhasorView->setScene(currentPhasorScene);
    voltagePhasorView->setScene(voltagePhasorScene);

    currentPlotScene = new CurrentPlotScene();
    voltagePlotScene = new VoltagePlotScene();
    currentPlotView = new PlotView;
    voltagePlotView = new PlotView;
    currentPlotView->setScene(currentPlotScene);
    voltagePlotView->setScene(voltagePlotScene);
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), currentPlotScene, SLOT(streamSelectionChanged(Stream*)));
    //connect(tableModel, SIGNAL(streamSelected(Stream*)), voltagePlotScene, SLOT(streamSelectionChanged(Stream*)));

    graphLayout->addWidget(voltagePhasorView, 0, 0, Qt::AlignCenter);
    graphLayout->addWidget(currentPhasorView, 1, 0, Qt::AlignCenter);
    graphLayout->addWidget(voltagePlotView, 0, 1, Qt::AlignLeft);
    graphLayout->addWidget(currentPlotView, 1, 1, Qt::AlignLeft);
    graphLayout->setColumnStretch(0, 0);
    graphLayout->setColumnStretch(1, 1);

    this->views.append(currentPhasorView);
    this->views.append(voltagePhasorView);
    this->views.append(currentPlotView);
    this->views.append(voltagePlotView);

    setLayout(graphLayout);
}
