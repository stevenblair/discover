#ifndef STREAMTABLEROW_H
#define STREAMTABLEROW_H

class Stream;

#include <QObject>
#include "stream.h"
#include "samplerate.h"
#include "measure/measure.h"

#define SIGNIFICANT_DIGITS_DIPLAYED 3

class StreamTableRow : public QObject
{
    Q_OBJECT
public:
    explicit StreamTableRow(Stream *stream, QObject *parent = 0);

    bool isAlive() {return this->status;}
    QString getSvID() {return this->svID;}
    QString getSourceMAC() {return this->sourceMAC;}
    QString getFreq()
    {
        if (analysed) {
            return QString("%1 Hz").arg(measure_Y.Frequency, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getVoltage()
    {
        if (analysed) {
            return QString("%1 kV").arg(sqrt(3) * (measure_Y.Voltage[0] + measure_Y.Voltage[1] + measure_Y.Voltage[2]) / 3000.0, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getPower()
    {
        if (analysed) {
            return QString("%1 kVA, p.f. %2").arg(measure_Y.Power[0] / 1000.0, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED).arg(measure_Y.Power[3], 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED);
        }
        else {
            return QString("--");
        }
    }

    QString getCurrent()
    {
        if (analysed) {
            return QString("%1 kA").arg(sqrt(3) * (measure_Y.Current[0] + measure_Y.Current[1] + measure_Y.Current[2]) / 3000.0, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED);
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
    
signals:
    
public slots:

private:
    //Stream *stream;
    bool status;
    QString svID;
    QString sourceMAC;
    QString destMAC;
    SampleRate sampleRate;

    bool analysed;
    ExternalOutputs_measure measure_Y;
    
};

#endif // STREAMTABLEROW_H
