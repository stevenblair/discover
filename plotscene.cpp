#include "plotscene.h"
#include <QGraphicsPathItem>
#include "plotview.h"
#include "phasorscene.h"
#include <QGraphicsView>

PlotScene::PlotScene(QObject *parent) : QGraphicsScene(parent)
{
    //path = new QPainterPath();

    QColor lineColors[3] = {QColor(180, 33, 38, PHASOR_LINE_ALPHA), QColor(240, 181, 0, PHASOR_LINE_ALPHA), QColor(36, 78, 198, PHASOR_LINE_ALPHA)};
    QColor plotLineColor = QColor(180, 180, 180);

    plotLinePen = QPen(plotLineColor);
    plotLinePen.setCosmetic(true);
    //plotLinePen.setWidth(2);
    plotLinePen.setCapStyle(Qt::RoundCap);
    plotLinePenDashed = QPen(plotLineColor);
    plotLinePenDashed.setCosmetic(true);
    plotLinePenDashed.setStyle(Qt::DashLine);

    for (int i = 0; i < 3; i++) {
        pen[i] = QPen(QColor(lineColors[i]));
        plot[i] = QGraphicsScene::addPath(path[i], pen[i]);
        plot[i]->hide();
    }

    for (int i = 0; i < NUMBER_OF_CYCLES_TO_ANALYSE + 1; i++) {
        xAxisLabels[i] = QGraphicsScene::addText("");
        xAxisLabels[i]->setPos(0.0, 0.0);
        xAxisLabels[i]->setDefaultTextColor(plotLineColor);
        xAxisLabels[i]->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        xAxisLabels[i]->hide();

        if (i > 0) {
            xAxisTicks[i - 1] = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePenDashed);
            //xAxisTicks[i - 1]->setFlag(QGraphicsItem::ItemIgnoresTransformations);
            xAxisTicks[i - 1]->hide();
        }
    }
    yAxisLabelPositive = QGraphicsScene::addText("");
    yAxisLabelPositive->setPos(0.0, 0.0);
    yAxisLabelPositive->setDefaultTextColor(plotLineColor);
    yAxisLabelPositive->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    yAxisLabelPositive->hide();
    yAxisLabelNegative = QGraphicsScene::addText("");
    yAxisLabelNegative->setPos(0.0, 0.0);
    yAxisLabelNegative->setDefaultTextColor(plotLineColor);
    yAxisLabelNegative->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    yAxisLabelNegative->hide();
    yAxisTicks[0] = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePenDashed);
    //yAxisTicks[0]->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    yAxisTicks[0]->hide();
    yAxisTicks[1] = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePenDashed);
    //yAxisTicks[1]->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    yAxisTicks[1]->hide();

    horizontalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);
    verticalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);

    drawnOnce = false;
    this->stream = NULL;
}



QRectF PlotScene::itemsBoundingRect() const {
    QList<QGraphicsItem *> items = this->items();
    QGraphicsItem *item;
    QRectF total = QRectF();

    foreach (item, items) {
        if (!(item->flags() & QGraphicsItem::ItemIgnoresTransformations)) {
            //qDebug() << item->boundingRect().width();
            total = total.united(item->boundingRect());
        }
    }

    return total;
}

QRectF PlotScene::sceneRect() const
{
    return this->itemsBoundingRect();
}

void PlotScene::streamSelectionChanged(Stream *stream)
{
    if (this->stream != NULL) {
        //disconnect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved()));  // TODO: enable this?
        disconnect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
    }

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
        qreal maxValue = stream->getMaxInstantaneous(this->getPowerSystemQuantity());
        qreal totalTime = ((qreal) NUMBER_OF_CYCLES_TO_ANALYSE) / stream->getSampleRate()->getNominalFrequency();
        qreal yAxis = maxValue * 1.2;
        qreal xAxis = totalTime * 1.1;

        //qDebug() << getPowerSystemQuantity() << xAxis << yAxis;
        //qDebug() << getPowerSystemQuantity() << stream->getMaxInstantaneous(Stream::Voltage) << stream->getMaxInstantaneous(Stream::Current) << this->sceneRect().height();

        /*plotLinePen.setWidthF(0.0002);
        verticalPlotLine->setPen(plotLinePen);
        horizontalPlotLine->setPen(plotLinePen);*/

        horizontalPlotLine->setLine(xAxis * -0.1, 0.0, xAxis, 0.0);
        verticalPlotLine->setLine(0.0, -yAxis, 0.0, yAxis);

        for (int i = 0; i < NUMBER_OF_CYCLES_TO_ANALYSE + 1; i++) {
            qreal timeValue = (qreal) i * (1.0 / stream->getSampleRate()->getNominalFrequency());
            xAxisLabels[i]->setPlainText(QString("%1 ms").arg(timeValue * 1000.0));
            xAxisLabels[i]->setPos(timeValue, 0.0);
            xAxisLabels[i]->show();

            if (i > 0) {
                xAxisTicks[i - 1]->setLine(timeValue, -yAxis, timeValue, yAxis);
                xAxisTicks[i - 1]->show();
            }
        }

        yAxisLabelPositive->setPlainText(QString("%1 kA").arg(maxValue / 1000.0, 0, 'g', 3));
        yAxisLabelNegative->setPlainText(QString("%1 kA").arg(maxValue / -1000.0, 0, 'g', 3));
        yAxisLabelPositive->setPos(0.0, -maxValue /*- yAxisLabelPositive->boundingRect().height()*/);
        yAxisLabelNegative->setPos(0.0, maxValue);
        yAxisLabelPositive->show();
        yAxisLabelNegative->show();
        yAxisTicks[0]->setLine(0.0, -maxValue, totalTime, -maxValue);
        yAxisTicks[0]->show();
        yAxisTicks[1]->setLine(0.0, maxValue, totalTime, maxValue);
        yAxisTicks[1]->show();

        if (drawnOnce == false && !this->views().isEmpty()) {
            QGraphicsView *view = ((PlotView *) this->views().first());
            //view->fitInView(plot[i], Qt::IgnoreAspectRatio);
            //view->fitInView(horizontalPlotLine, Qt::IgnoreAspectRatio);
            //view->fitInView(verticalPlotLine, Qt::IgnoreAspectRatio);

            //qDebug() << "total itemsBoundingRectWithoutText():" << itemsBoundingRect().width();
            //qDebug() << "total itemsBoundingRect():" << itemsBoundingRect().width();

            view->fitInView(itemsBoundingRect(), Qt::IgnoreAspectRatio);
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
