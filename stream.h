#ifndef STREAM_H
#define STREAM_H
#include <QtCore>
#include <QObject>
#include <QFutureWatcher>
#include "sample.h"
#include "rapid61850/iec61850.h"
//extern "C" {
#include "measure/measure.h"
#include "measure/rtwtypes.h"
#include "measure/measure_parameters.h"
//}

#define MAX_SAMPLES 15360         // 256 samples/cycle * 60 cycles

enum StreamSampleRate {RateUnknown, Rate80samples50Hz, Rate80samples60Hz, Rate256samples50Hz, Rate256samples60Hz, RateInvalid};

class Stream : public QObject
{
    Q_OBJECT

public:
    explicit Stream(QString svID, QString sourceMAC = 0, QObject *parent = 0);

    void addSample(struct LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);

    QString getSvID();
    QString getSourceMAC();
    QString getFreq();
    QString getVoltage();
    QString getCurrent();
    QString getSamplesPerCycle();

    quint32 getNumberOfSamplesCaptured();

    bool isAnalysed();
    void setAnalysed(bool analysed);

signals:
    //void sampleRateDetermined(QString svID);
    void updateModel(bool resizeColumns);

public slots:
    void handleAnalysisFinished();

private:
    void analyse();

    QString svID;
    QString sourceMAC;
    QString destMAC;

    quint32 capturedSamples;
    Sample samples[MAX_SAMPLES];
    bool analysed;

    StreamSampleRate sampleRate;

    // TODO: these are placeholders, until full analysis is done
    QString freqSummary;
    QString voltageSummary;
    QString currentSummary;

//    RT_MODEL_measure measure_M;
//    //static RT_MODEL_measure *const measure_M;/* Real-time model */
//    D_Work_measure measure_DWork;   /* Observable states */
//    ExternalInputs_measure measure_U;/* External inputs */
//    ExternalOutputs_measure measure_Y;/* External outputs */
    measureModelClass analysisInstance;
    QFuture<void> future;
    QFutureWatcher<void> watcher;
};

#endif // STREAM_H
