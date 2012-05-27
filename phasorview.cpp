#include "phasorview.h"

PhasorView::PhasorView(QObject *parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setMinimumSize(PHASOR_VIEW_WIDTH, PHASOR_VIEW_WIDTH);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
