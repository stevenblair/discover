#include "plotscene.h"
#include <QGraphicsPathItem>
#include "plotview.h"
#include "phasorscene.h"

PlotScene::PlotScene(QObject *parent) : QGraphicsScene(parent)
{
    //path = new QPainterPath();

    QColor lineColors[3] = {QColor(180, 33, 38, PHASOR_LINE_ALPHA), QColor(240, 181, 0, PHASOR_LINE_ALPHA), QColor(36, 78, 198, PHASOR_LINE_ALPHA)};
    QColor plotLineColor = QColor(180, 180, 180);

    for (int i = 0; i < 3; i++) {
        plot[i] = QGraphicsScene::addPath(path[i], QPen(QColor(lineColors[i])));
        plot[i]->hide();
    }
}

void PlotScene::streamSelectionChanged(Stream *stream)
{
    this->stream = stream;

    if (this->stream != NULL) {
        //connect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved()));
        //connect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
        draw();
    }
}

Stream::PowerSystemQuantity PlotScene::getPowerSystemQuantity()
{
    return Stream::Voltage;
}

void PlotScene::draw() {
    if (stream != NULL) {
        for (int i = 0; i < 3; i++) {
            stream->getPainterPath(&path[i], getPowerSystemQuantity(), i);
            plot[i]->setPath(path[i]);
            plot[i]->show();
            //update();

            QGraphicsView *view = ((PlotView *) this->views().first());
            //QRectF rect = plot[i]->boundingRect();
            //QRectF rectView = view->sceneRect();

            //qDebug() << rect << rectView;

            view->fitInView(plot[i], Qt::IgnoreAspectRatio);
            //view->update();

            //view->scale(rectView.height() / rect.height(), rectView.width() / rect.width());
            //view->centerOn(centerPoint);
            //((PlotView *) this->views().first())->update();

            //((PlotView *) this->views().first())->ensureVisible(item);
            //this->invalidate(this->);
        }
    }
}



VoltagePlotScene::VoltagePlotScene(QObject *parent) : PlotScene(parent)
{
}

Stream::PowerSystemQuantity VoltagePlotScene::getPowerSystemQuantity()
{
    return Stream::Voltage;
}






CurrentPlotScene::CurrentPlotScene(QObject *parent) : PlotScene(parent)
{
}

Stream::PowerSystemQuantity CurrentPlotScene::getPowerSystemQuantity()
{
    return Stream::Current;
}
