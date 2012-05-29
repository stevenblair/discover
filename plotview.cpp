#include "plotview.h"
#include "phasorscene.h"

PlotView::PlotView(QObject *parent)
{
    this->setMinimumSize(PLOT_VIEW_WIDTH, PLOT_VIEW_HEIGHT);
    //this->setMinimumHeight(PLOT_VIEW_HEIGHT);
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
