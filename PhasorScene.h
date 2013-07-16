/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Steven Blair
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

#ifndef PHASOR_H
#define PHASOR_H

#include <QGraphicsScene>
#include <qmath.h>
#include <QGraphicsView>
#include "StreamTableModel.h"

#define PHASOR_VIEW_MAX_PHASOR_SIZE 80.0
#define PHASOR_VIEW_MAX_SIZE        (PHASOR_VIEW_MAX_PHASOR_SIZE + 25.0)    // defines max distance from centre in any direction
#define PHASOR_VIEW_WIDTH           (2.0 * PHASOR_VIEW_MAX_SIZE)

#define PHASOR_LINE_ALPHA           210

class PhasorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    PhasorScene(QObject *parent = 0);
    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();

public slots:
    //void streamSelectionChanged(Stream *stream);
    //void streamChanged();
    //void streamRemoved();

protected:
    //Stream *stream;
    StreamTableModel *streamTableModel;
    QPersistentModelIndex *index;

    virtual qreal getPhasorMag(StreamTableRow *stream, int phase);
    virtual qreal getPhasorAngle(StreamTableRow *stream, int phase);
    virtual QString getPhaseLabel(StreamTableRow * stream, int phase);
    QString phaseNumberToText(StreamTableRow *stream, int phase);
    virtual QString getUnits();

private:
    void draw();
    virtual QString getToolTipText(StreamTableRow *stream, int phase);

    QPen pen[3];
    QPen plotLinePen;
    QPen plotLineCiclePen;
    QGraphicsLineItem *phaseLine[3];
    QGraphicsTextItem *phaseLabel[3];
    QGraphicsEllipseItem *outerPlotLine;
    QGraphicsEllipseItem *innerPlotLine;
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QGraphicsTextItem *zeroDegText;
    QGraphicsTextItem *nintyDegText;
    QGraphicsTextItem *oneEightyDegText;
    QGraphicsTextItem *minusNinetyDegText;
    QGraphicsTextItem *onePuText;
};





class CurrentPhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    CurrentPhasorScene(QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(StreamTableRow *stream, int phase);
    qreal getPhasorAngle(StreamTableRow *stream, int phase);
    QString getPhaseLabel(StreamTableRow *stream, int phase);
    QString getUnits();

private:

    QString getToolTipText(StreamTableRow *stream, int phase);
};





class VoltagePhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    VoltagePhasorScene(QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(StreamTableRow *stream, int phase);
    qreal getPhasorAngle(StreamTableRow *stream, int phase);
    QString getPhaseLabel(StreamTableRow *stream, int phase);
    QString getUnits();

private:

    QString getToolTipText(StreamTableRow *stream, int phase);
};

#endif // PHASOR_H
