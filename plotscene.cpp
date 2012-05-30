#include "plotscene.h"
#include <QGraphicsPathItem>
#include "plotview.h"
#include "phasorscene.h"

PlotScene::PlotScene(QObject *parent) : QGraphicsScene(parent)
{
    //path = new QPainterPath();

    QColor lineColors[3] = {QColor(180, 33, 38, PHASOR_LINE_ALPHA), QColor(240, 181, 0, PHASOR_LINE_ALPHA), QColor(36, 78, 198, PHASOR_LINE_ALPHA)};
    QColor plotLineColor = QColor(180, 180, 180);

    plotLinePen = QPen(plotLineColor);

    for (int i = 0; i < 3; i++) {
        plot[i] = QGraphicsScene::addPath(path[i], QPen(QColor(lineColors[i])));
        plot[i]->hide();
    }

    horizontalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);
    verticalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);
}

void PlotScene::streamSelectionChanged(Stream *stream)
{
    this->stream = stream;

    if (this->stream != NULL) {
        // pre-initialise paths with the correct number of elements
        quint32 iterations = stream->getSampleRate()->getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;
        for (int i = 0; i < 3; i++) {
            if (path[i].length() <= 1) {
                for (quint32 t = 0; t < iterations; t++) {
                    path[i].lineTo(0.001 * t, 0.001 * t);
                }
            }
        }

        //connect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved())); // TODO: just use streamSelectionChanged(Stream *stream) (i.e., this function) to handle deleted Stream?
        connect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
        draw();
    }
}

void PlotScene::streamChanged()
{
    draw();
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
            //qDebug() << i << path[i].length();

            view->fitInView(plot[i], Qt::IgnoreAspectRatio);        // only if not first plot, or not overridden
            //view->update();

            //view->scale(rectView.height() / rect.height(), rectView.width() / rect.width());
            //view->centerOn(centerPoint);
            //((PlotView *) this->views().first())->update();

            //((PlotView *) this->views().first())->ensureVisible(item);
            //this->invalidate(this->);
        }

        // TODO: use max instantaneous value for height
        // TODO: add padding, of a certain percentage of total width/height, at sides
        horizontalPlotLine->setLine(0.0, 0.0, plot[0]->boundingRect().width(), 0.0);
        verticalPlotLine->setLine(0.0, plot[0]->boundingRect().height() / -2.0, 0.0, plot[0]->boundingRect().height() / 2.0);
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
