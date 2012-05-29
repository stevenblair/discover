#ifndef STREAM_H
#define STREAM_H
#include <QtCore>
#include <QObject>
#include <QFutureWatcher>
#include <QGraphicsScene>
#include "sample.h"
#include "rapid61850/iec61850.h"
#include "measure/measure.h"
#include "measure/rtwtypes.h"
#include "measure/measure_parameters.h"


#define SAMPLES_50HZ_80_PER_CYCLE   4000
#define SAMPLES_60HZ_80_PER_CYCLE   4800
#define SAMPLES_50HZ_256_PER_CYCLE  12800
#define SAMPLES_60HZ_256_PER_CYCLE  15360                       // 256 samples/cycle * 60 cycles
#define MAX_SAMPLES                 SAMPLES_60HZ_256_PER_CYCLE

#define RECALCULATE_ANALYSIS_TIME   5000                        // milliseconds

#define SIGNIFICANT_DIGITS_DIPLAYED 3

enum StreamSampleRate {RateUnknown, Rate80samples50Hz, Rate80samples60Hz, Rate256samples50Hz, Rate256samples60Hz, RateInvalid};

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

    StreamSampleRate sampleRate;

    QTimer *timer;

    measureModelClass analysisInstance;
    QFuture<void> future;
    QFutureWatcher<void> watcher;
};

#endif // STREAM_H
