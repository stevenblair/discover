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

#ifndef FREQUENCYSCENE_H
#define FREQUENCYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPathItem>
#include "StreamTableModel.h"

#define ONE_PU_HEIGHT               200
#define DISPLAY_HARMONIC_CUTOFF     (1.0e-4)


class FrequencyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    static const QColor waveformColors[3];

    explicit FrequencyScene(QObject *parent = 0);
    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();
    void setWaveformState(int waveform, bool newState) {
        if (waveform >= 0 && waveform < 3) {
            activeWaveform[waveform] = newState;
            draw();
        }
    }
    bool getWaveformState(int waveform) {
        if (waveform >= 0 && waveform < 3) {
            return activeWaveform[waveform];
        }
        return false;
    }

    static const QString PhaseLables[3];

signals:
    void callRedrawFrequencyScene();
    
public slots:
    void redrawFrequencyScene();

protected:
    StreamTableModel *streamTableModel;
    QPersistentModelIndex *index;
    bool activeWaveform[3];

private:
    void draw();

    QPen pen[TOTAL_SIGNALS];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QList<QGraphicsLineItem *> harmonicLine[3];
    QList<QGraphicsTextItem *> xLabels;
    QList<QGraphicsLineItem *> xAxisTicks;
    QPen plotLinePenDashed;

    virtual qreal getFundamental(QPointer<StreamTableRow> stream, int phase);
    virtual qreal getHarmonic(QPointer<StreamTableRow> stream, int harmonicIndex);
    virtual qreal getHarmonicMag(QPointer<StreamTableRow> stream, int harmonicIndex);
};



class CurrentFrequencyScene : public FrequencyScene
{
    Q_OBJECT
public:
    CurrentFrequencyScene(QObject *parent = 0);

public slots:

protected:

private:
    qreal getFundamental(QPointer<StreamTableRow> stream, int phase);
    qreal getHarmonic(QPointer<StreamTableRow> stream, int harmonicIndex);
    qreal getHarmonicMag(QPointer<StreamTableRow> stream, int harmonicIndex);
};


#endif // FREQUENCYSCENE_H
