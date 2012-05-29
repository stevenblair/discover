#include "phasorview.h"
#include "phasorscene.h"

PhasorView::PhasorView(QObject *parent)
{
    this->setMinimumSize(PHASOR_VIEW_WIDTH, PHASOR_VIEW_WIDTH);
    //this->setDragMode(QGraphicsView::RubberBandDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QMatrix matrix;
    matrix.scale(1.0, 1.0);
    this->setMatrix(matrix);
    this->centerOn(0.0, 0.0);
}
