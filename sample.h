#ifndef SAMPLE_H
#define SAMPLE_H

#include <QtGlobal>

class Sample
{
public:
    Sample();

    qint16 smpCount;
    qint32 voltage[4];
    quint32 voltageQuality[4];
    qint32 current[4];
    quint32 currentQuality[4];
};

#endif // SAMPLE_H
