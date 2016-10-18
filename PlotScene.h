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

#ifndef PLOTSCENE_H
#define PLOTSCENE_H

#include <QGraphicsScene>
#include "Stream.h"
#include "StreamTableModel.h"

#define X_AXIS_OVERSHOOT    0.06
#define Y_AXIS_OVERSHOOT    0.2

class PlotScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PlotScene(QObject *parent = 0);
    QRectF itemsBoundingRect() const;
    QRectF sceneRect() const;

    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();

    void setDrawnStatus(bool status) {
        this->drawnOnce = status;
    }

    int getPathCount() { return pathCount; }
    const QPainterPath * getPath() const { return path; }

signals:

public slots:

protected:
    virtual Stream::PowerSystemQuantity getPowerSystemQuantity();
    QString getXUnits() {return xUnits;}
    QString getYUnits() {return yUnits;}

    QString xUnits;
    QString yUnits;

    StreamTableModel *streamTableModel;
    QPersistentModelIndex index;

private:
    QPen pen[pathCount];
    QPen plotLinePen;
    QPen plotLinePenDashed;
    QPainterPath path[pathCount];
    QGraphicsPathItem *plot[pathCount];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QGraphicsTextItem *xAxisLabels[NUMBER_OF_CYCLES_TO_ANALYSE + 1];
    QGraphicsTextItem *yAxisLabelPositive;
    QGraphicsTextItem *yAxisLabelNegative;
    QGraphicsLineItem *xAxisTicks[NUMBER_OF_CYCLES_TO_ANALYSE];     // don't need a tick at (0.0, 0.0)
    QGraphicsLineItem *yAxisTicks[2];

    bool drawnOnce;
    void draw();

    static const int pathCount = 3;
};



class VoltagePlotScene : public PlotScene
{
    Q_OBJECT
public:
    explicit VoltagePlotScene(QObject *parent = 0);

signals:

public slots:

protected:
    Stream::PowerSystemQuantity getPowerSystemQuantity();

};


class CurrentPlotScene : public PlotScene
{
    Q_OBJECT
public:
    explicit CurrentPlotScene(QObject *parent = 0);

signals:

public slots:

protected:
    Stream::PowerSystemQuantity getPowerSystemQuantity();

};

#endif // PLOTSCENE_H
