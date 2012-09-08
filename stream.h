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

#ifndef STREAM_H
#define STREAM_H

class StreamTableRow;

#include <QtCore>
#include <QObject>
#include <QFutureWatcher>
#include <QGraphicsScene>
#include <QPainter>
#include "Sample.h"
#include "Samplerate.h"
extern "C" {
#include "rapid61850/iec61850.h"
}
#include "measure/measure.h"
#include "measure/rtwtypes.h"
#include "measure/measure_parameters.h"
#include "StreamTableRow.h"


#define RECALCULATE_ANALYSIS_TIME   3000    // milliseconds
#define NUMBER_OF_CYCLES_TO_ANALYSE 8      // must be at least 2 cycles
#define SIGNIFICANT_DIGITS_DIPLAYED 3

class Stream : public QObject
{
    Q_OBJECT

public:
    enum PowerSystemQuantity {Voltage = 0, Current = 1};

    explicit Stream(QString svID, QString sourceMAC = 0, QObject *parent = 0);
    ~Stream();

    void addSample(struct LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);

    QString getSvID();
    QString getSourceMAC();
    quint32 getNumberOfSamplesCaptured();
    QPainterPath *getPainterPath(QPainterPath *path, PowerSystemQuantity powerSystemQuantity, int phase);

    bool isAnalysed();
    bool isAlive();
    void setAnalysed(bool analysed);
    ExternalOutputs_measure *getStreamData();
    qreal getMaxInstantaneous(PowerSystemQuantity powerSystemQuantity);
    SampleRate *getSampleRate();
    Sample *getSampleAt(quint32 i);

    void disable() {disabled = true;}

signals:
    void updateModel(bool resizeColumns);
    void updateView();
    void removeView();
    void setStreamTableRow(StreamTableRow *row);
    void stopTimer();
    void stopWatcher();

public slots:
    void handleAnalysisFinished();
    void timeout();

private:
    void analyse();
    void updateStreamTableModel();
    void scheduleAnalysis();

    //TODO: add QPainterPath which is explicitly shared with UI thread?

    bool disabled;
    bool capturing;

    QString svID;
    QString sourceMAC;
    QString destMAC;

    quint32 capturedSamples;
    Sample samples[MAX_SAMPLES];
    bool analysed;
    bool alive;
    bool checkAlive;

    SampleRate sampleRate;

    QTimer *timer;

    measureModelClass analysisInstance;
    qreal maxInstantaneousVoltage;
    qreal maxInstantaneousCurrent;
    QFuture<void> future;
    QFutureWatcher<void> watcher;

    StreamTableRow *row;
};

#endif // STREAM_H
