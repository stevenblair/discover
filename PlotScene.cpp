/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2013 Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "PlotScene.h"
#include <QGraphicsPathItem>
#include "PlotView.h"
#include "PhasorScene.h"
#include "SampleRate.h"
#include <QGraphicsView>

PlotScene::PlotScene(QObject *parent) : QGraphicsScene(parent)
{
    //path = new QPainterPath();
    xUnits = QString("ms");

    QColor lineColors[pathCount] = {QColor(180, 33, 38, PHASOR_LINE_ALPHA), QColor(240, 181, 0, PHASOR_LINE_ALPHA), QColor(36, 78, 198, PHASOR_LINE_ALPHA)};
    QColor plotLineColor = QColor(180, 180, 180);

    plotLinePen = QPen(plotLineColor);
    plotLinePen.setCosmetic(true);
    plotLinePen.setCapStyle(Qt::RoundCap);
    plotLinePenDashed = QPen(plotLineColor);
    plotLinePenDashed.setCosmetic(true);
    plotLinePenDashed.setStyle(Qt::DashLine);

    for (int i = 0; i < pathCount; i++) {
        pen[i] = QPen(QColor(lineColors[i]));
        //pen[i].setWidthF(0.3);
        pen[i].setCosmetic(true);
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
    //this->stream = NULL;
}

void PlotScene::streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index)
{
    if (!this->index.isValid() || this->index.row() != index->row()) {
        drawnOnce = false;
    }

    this->streamTableModel = streamTableModel;
    this->index = QPersistentModelIndex(*index);    // create copy of QPersistentModelIndex

    QPointer<StreamTableRow> stream;

    if (this->streamTableModel != NULL && /*this->index != NULL &&*/ this->index.isValid()) {
        stream = this->streamTableModel->getRowFromIndex(&this->index);
    }
    else {
        return;
    }

    if (stream.isNull()) {
        return;
    }

    // pre-initialise paths with the correct number of elements
    quint32 iterations = stream->getSampledData()->size();

    for (int i = 0; i < pathCount; i++) {
        if (path[i].length() <= 1) {
            for (quint32 t = 0; t < iterations; t++) {
                path[i].lineTo(0.001 * t, 0.001 * t);
            }
        }
    }

    draw();
}

void PlotScene::streamRemoved()
{
    for (int i = 0; i < pathCount; i++) {
        plot[i]->hide();
    }
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


Stream::PowerSystemQuantity PlotScene::getPowerSystemQuantity()
{
    return Stream::Voltage;
}

void PlotScene::draw() {
    //qDebug() << "in PlotScene::draw()";
    QPointer<StreamTableRow> stream;

    if (this->streamTableModel != NULL && /*this->index != NULL &&*/ this->index.isValid()) {
        stream = this->streamTableModel->getRowFromIndex(&this->index);
    }
    else {
        return;
    }

    if (stream.isNull()) {
        return;
    }

    //TODO: use below to get pixel size of viewport; use to scale all heights and widths?
    //QGraphicsView *view = ((PlotView *) this->views().first());
    //qDebug() << view->viewport()->size().width() << view->viewport()->size().height();

    qreal maxValue = stream->getMaxInstantaneous(this->getPowerSystemQuantity());
    qreal totalTime = 1000.0 * ((qreal) NUMBER_OF_CYCLES_TO_ANALYSE) / stream->getSampleRate()->getNominalFrequency();
    qreal yAxis = maxValue * (1.0 + Y_AXIS_OVERSHOOT);
    qreal xAxis = totalTime * (1.0 + X_AXIS_OVERSHOOT);

    //qDebug() << getPowerSystemQuantity() << xAxis << yAxis;
    //qDebug() << getPowerSystemQuantity() << stream->getMaxInstantaneous(Stream::Voltage) << stream->getMaxInstantaneous(Stream::Current) << this->sceneRect().height();

    /*plotLinePen.setWidthF(0.0002);
    verticalPlotLine->setPen(plotLinePen);
    horizontalPlotLine->setPen(plotLinePen);*/

    horizontalPlotLine->setLine(xAxis * -X_AXIS_OVERSHOOT, 0.0, xAxis, 0.0);
    verticalPlotLine->setLine(0.0, -yAxis, 0.0, yAxis);

    for (int i = 0; i < NUMBER_OF_CYCLES_TO_ANALYSE + 1; i++) {
        qreal timeValue = (qreal) i * (1.0 / stream->getSampleRate()->getNominalFrequency());
        qreal timeValueMillisconds = 1000.0 * timeValue;
        xAxisLabels[i]->setPlainText(QString("%1 %2").arg(timeValue * 1000.0, 0, 'g', 3).arg(getXUnits()));
        xAxisLabels[i]->setPos(timeValueMillisconds, 0.0);
        xAxisLabels[i]->show();

        if (i > 0) {
            xAxisTicks[i - 1]->setLine(timeValueMillisconds, -yAxis, timeValueMillisconds, yAxis);
            xAxisTicks[i - 1]->show();
        }
    }

    //qDebug() << this->stream->getStreamData()->Voltage[6];

    yAxisLabelPositive->setPlainText(QString("%1 %2").arg(maxValue / 1000.0, 0, 'g', 3).arg(getYUnits()));
    yAxisLabelNegative->setPlainText(QString("%1 %2").arg(maxValue / -1000.0, 0, 'g', 3).arg(getYUnits()));
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

    for (int i = 0; i < pathCount; i++) {
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




VoltagePlotScene::VoltagePlotScene(QObject *parent) : PlotScene(parent)
{
    yUnits = QString("kV");
}

Stream::PowerSystemQuantity VoltagePlotScene::getPowerSystemQuantity()
{
    return Stream::Voltage;
}



CurrentPlotScene::CurrentPlotScene(QObject *parent) : PlotScene(parent)
{
    yUnits = QString("kA");
}

Stream::PowerSystemQuantity CurrentPlotScene::getPowerSystemQuantity()
{
    return Stream::Current;
}
