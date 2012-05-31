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

    drawnOnce = false;
}

void PlotScene::streamSelectionChanged(Stream *stream)
{
    /*if (this->stream != NULL) {
        //disconnect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved()));  // TODO: enable this?
        disconnect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
    }*/

    this->stream = stream;

    if (this->stream != NULL) {
        drawnOnce = false;

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
        // TODO: add padding, of a certain percentage of total width/height, at sides
        qreal maxValue = stream->getMaxInstantaneous(this->getPowerSystemQuantity());
        qreal totalTime = ((qreal) NUMBER_OF_CYCLES_TO_ANALYSE) / stream->getSampleRate()->getNominalFrequency();
        qreal yAxis = maxValue * 1.2;
        qreal xAxis = totalTime * 1.1;

        //qDebug() << getPowerSystemQuantity() << xAxis << yAxis;
        //qDebug() << getPowerSystemQuantity() << stream->getMaxInstantaneous(Stream::Voltage) << stream->getMaxInstantaneous(Stream::Current) << this->sceneRect().height();

        horizontalPlotLine->setLine(xAxis * -0.1, 0.0, xAxis, 0.0);
        verticalPlotLine->setLine(0.0, -yAxis, 0.0, yAxis);

        if (drawnOnce == false && !this->views().isEmpty()) {
            QGraphicsView *view = ((PlotView *) this->views().first());
            //view->fitInView(plot[i], Qt::IgnoreAspectRatio);
            //view->fitInView(horizontalPlotLine, Qt::IgnoreAspectRatio);
            //view->fitInView(verticalPlotLine, Qt::IgnoreAspectRatio);
            view->fitInView(sceneRect(), Qt::IgnoreAspectRatio);
        }

        for (int i = 0; i < 3; i++) {
            stream->getPainterPath(&path[i], getPowerSystemQuantity(), i);
            plot[i]->setPath(path[i]);
            plot[i]->show();
            //update();
            //view->update();

            //view->scale(rectView.height() / rect.height(), rectView.width() / rect.width());
            //view->centerOn(centerPoint);
            //((PlotView *) this->views().first())->update();

            //((PlotView *) this->views().first())->ensureVisible(item);
            //this->invalidate(this->);

            // only fit in view the first time being plotted
        }

        drawnOnce = true;
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
