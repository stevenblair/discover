#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include "sample.h"

#define MAX_SAMPLES 512         // 256 max samples/cycle * 2 cycles


class Stream : public QObject
{
    Q_OBJECT
public:
    explicit Stream(QObject *parent = 0);

    void addSample();   // TODO: pass pointer to dataset?
    
signals:
    
public slots:

private:
    QString SVID;
    QString sourceMAC;
    QString destMAC;

    quint32 capturedSamples;
    Sample samples[MAX_SAMPLES];
    bool analysed;
};

#endif // STREAM_H
