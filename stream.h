#ifndef STREAM_H
#define STREAM_H
#include <QObject>
#include "sample.h"
#include "rapid61850/iec61850.h"

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
    void sampleRateDetermined(QString svID);

public slots:

private:
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
};

#endif // STREAM_H
