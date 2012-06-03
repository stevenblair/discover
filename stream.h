#ifndef STREAM_H
#define STREAM_H

class StreamTableRow;

#include <QtCore>
#include <QObject>
#include <QFutureWatcher>
#include <QGraphicsScene>
#include <QPainter>
#include "sample.h"
#include "samplerate.h"
extern "C" {
#include "rapid61850/iec61850.h"
}
#include "measure/measure.h"
#include "measure/rtwtypes.h"
#include "measure/measure_parameters.h"
#include "streamtablerow.h"


#define RECALCULATE_ANALYSIS_TIME   3000    // milliseconds
#define NUMBER_OF_CYCLES_TO_ANALYSE 3       // must be at least 2 cycles
#define SIGNIFICANT_DIGITS_DIPLAYED 3

class Stream : public QObject
{
    Q_OBJECT

public:
    enum PowerSystemQuantity {Voltage, Current};

    explicit Stream(QString svID, QString sourceMAC = 0, QObject *parent = 0);
    ~Stream();

    void addSample(struct LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);

    QString getSvID();
    QString getSourceMAC();
//    QString getFreq();
//    QString getVoltage();
//    QString getCurrent();
//    QString getSamplesPerCycle();
//    QString getPower();
    quint32 getNumberOfSamplesCaptured();
    QPainterPath *getPainterPath(QPainterPath *path, PowerSystemQuantity powerSystemQuantity, int phase);

    bool isAnalysed();
    bool isAlive();
    void setAnalysed(bool analysed);
    ExternalOutputs_measure *getStreamData();
    qreal getMaxInstantaneous(PowerSystemQuantity powerSystemQuantity);
    SampleRate *getSampleRate();

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
    void scheduleAnalysis();
    void timeout();

private:
    void analyse();
    void updateStreamTableModel();

    //TODO: add QPainterPath which is explicitly shared with UI thread?

    bool disabled;

    QString svID;
    QString sourceMAC;
    QString destMAC;

    quint32 capturedSamples;
    quint32 samplesPerSecond;
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
};

#endif // STREAM_H
