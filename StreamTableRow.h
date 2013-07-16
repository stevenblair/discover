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

#ifndef STREAMTABLEROW_H
#define STREAMTABLEROW_H

class Stream;

#include <QObject>
#include "Stream.h"
#include "SampleRate.h"
#include "measure/measure.h"

#define SIGNIFICANT_DIGITS_DIPLAYED      3
#define SIGNIFICANT_DIGITS_DIPLAYED_FREQ 4
#define SIGNIFICANT_DIGITS_DIPLAYED_THD  2

class StreamTableRow : public QObject
{
    Q_OBJECT
public:
    StreamTableRow(QObject *parent = 0);
    explicit StreamTableRow(Stream *stream, QObject *parent = 0);
    ~StreamTableRow() {}

    void setup(Stream *stream);
    void appendFreqPoint(quint32 i, qreal x, qreal y) {
        if (i < TOTAL_SIGNALS) {
            this->freq[i].append(QPointF(x, y));
        }
    }
    quint32 getNumberOfFreqPoints(quint32 signal) {
        return this->freq[signal].size();
    }

    QPointF getFreqPoint(quint32 signal, quint32 i) {
        return this->freq[signal].at(i);
    }

    bool isAlive() {return this->status;}
    QString getSvID() {return this->svID;}
    QString getSourceMAC() {return this->sourceMAC;}
    QString getFreq()
    {
        if (analysed) {
            return QString("%1 Hz").arg(measure_Y.Frequency, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED_FREQ);
        }
        else {
            return QString("--");
        }
    }

    QString getVoltage()
    {
        if (analysed) {
            return QString("%1 kV").arg((qSqrt(3) / qSqrt(2)) * measure_Y.VoltagePosSeqMagPu / 1000.0, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getPower()
    {
        if (analysed) {
            qreal power = measure_Y.VA;
            QString units;
            if (power > 1000.0 && power < 1000000.0) {
                power = power / 1000.0;
                units = QString("kVA");
            }
            else if (power >= 1000000.0) {
                power = power / 1000000.0;
                units = QString("MVA");
            }

            return QString("%1 %2, p.f. %3").arg(power, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED).arg(units).arg(measure_Y.PowerFactor, 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getVoltageTHD()
    {
        if (analysed) {
            return QString("%1 %").arg((measure_Y.VoltageTHDPercent3[0] + measure_Y.VoltageTHDPercent3[1] + measure_Y.VoltageTHDPercent3[2]) / 3.0, 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED_THD);
        }
        else {
            return QString("--");
        }
    }

    QString getCurrentTHD()
    {
        if (analysed) {
            // TODO change to positve seq current?
            return QString("%1 %").arg((measure_Y.Current[6] + measure_Y.Current[7] + measure_Y.Current[8]) / 3.0, 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED_THD);
        }
        else {
            return QString("--");
        }
    }

    QString getCurrent()
    {
        if (analysed) {
            return QString("%1 kA").arg((measure_Y.Current[0] + measure_Y.Current[1] + measure_Y.Current[2]) / 3000.0, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getSamplesPerCycle()
    {
        if (sampleRate.isKnown()) {
            return QString("%1").arg(sampleRate.getSamplesPerCycle());
        }
        else {
            return QString("--");
        }
    }

    bool isAnalysed() {
        return this->analysed;
    }

    ExternalOutputs_measure *getData() {
        return &measure_Y;
    }

    qreal getMaxInstantaneous(int powerSystemQuantity) {
        if (powerSystemQuantity == 0) {
            return maxInstantaneousVoltage;
        }
        else if (powerSystemQuantity == 1) {
            return maxInstantaneousCurrent;
        }
        return 0.0;
    }

    SampleRate* getSampleRate() {
        return &this->sampleRate;
    }

    QList<Sample>* getSampledData() {
        return &this->sampledData;
    }

    QPainterPath *getPainterPath(QPainterPath *path, int powerSystemQuantity, int phase);
signals:
    
public slots:

private:
    bool status;
    QString svID;
    QString sourceMAC;
    QString destMAC;
    SampleRate sampleRate;

    bool analysed;
    ExternalOutputs_measure measure_Y;
    QPainterPath paths[TOTAL_SIGNALS];
    QList<Sample> sampledData;
    QList<QPointF> freq[TOTAL_SIGNALS];
    qreal maxInstantaneousVoltage;
    qreal maxInstantaneousCurrent;
    
};

#endif // STREAMTABLEROW_H
