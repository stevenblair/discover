#include "plotview.h"
#include "phasorscene.h"

#include <QtGui>
#ifndef QT_NO_OPENGL
#include <QtOpenGL>
#endif

PlotView::PlotView(QObject *parent)
{
    this->setMinimumSize(PLOT_VIEW_WIDTH, PLOT_VIEW_HEIGHT);
    //this->setMinimumHeight(PLOT_VIEW_HEIGHT);
    this->setDragMode(QGraphicsView::RubberBandDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    //this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /*QMatrix matrix;
    matrix.scale(7000.0, 0.05);
    this->setMatrix(matrix);*/
    //this->centerOn(0.0, 0.0);
    //setViewport(new QGLWidget);
}
