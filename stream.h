#ifndef STREAM_H
#define STREAM_H
#include <QObject>
#include "sample.h"
#include "rapid61850/iec61850.h"

#define MAX_SAMPLES 15360         // 256 max samples/cycle * 2 cycles


class Stream
{
public:
    explicit Stream(QString svID, QString sourceMAC);

    void addSample(struct LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt);

    QString getSvID();
    QString getSourceMAC();
    QString getFreq();
    QString getVoltage();
    QString getCurrent();
    QString getSamplesPerCycle();

    bool isAnalysed();

private:
    QString svID;
    QString sourceMAC;
    QString destMAC;

    quint32 capturedSamples;
    Sample samples[MAX_SAMPLES];
    bool analysed;

    // TODO: these are placeholders, until full analysis is done
    QString freqSummary;
    QString voltageSummary;
    QString currentSummary;
};

#endif // STREAM_H
