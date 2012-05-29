#ifndef STREAM_H
#define STREAM_H
#include <QtCore>
#include <QObject>
#include <QFutureWatcher>
#include <QGraphicsScene>
#include "sample.h"
#include "samplerate.h"
#include "rapid61850/iec61850.h"
#include "measure/measure.h"
#include "measure/rtwtypes.h"
#include "measure/measure_parameters.h"


#define RECALCULATE_ANALYSIS_TIME   5000    // milliseconds
#define NUMBER_OF_CYCLES_TO_ANALYSE 4       // must be at least 2 cycles
#define SIGNIFICANT_DIGITS_DIPLAYED 3

class Stream : public QObject
{
    Q_OBJECT

public:
    explicit Stream(QString svID, QString sourceMAC = 0, QObject *parent = 0);
    ~Stream();

    void addSample(struct LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);

    QString getSvID();
    QString getSourceMAC();
    QString getFreq();
    QString getVoltage();
    QString getCurrent();
    QString getSamplesPerCycle();

    quint32 getNumberOfSamplesCaptured();

    bool isAnalysed();
    bool isAlive();
    void setAnalysed(bool analysed);
    ExternalOutputs_measure *getStreamData();

signals:
    void updateModel(bool resizeColumns);
    void updateView();
    void removeView();

public slots:
    void handleAnalysisFinished();
    void scheduleAnalysis();
    void timeout();

private:
    void analyse();

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
    QFuture<void> future;
    QFutureWatcher<void> watcher;
};

#endif // STREAM_H
