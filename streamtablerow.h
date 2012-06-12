#ifndef STREAMTABLEROW_H
#define STREAMTABLEROW_H

class Stream;

#include <QObject>
#include "stream.h"
#include "samplerate.h"
#include "measure/measure.h"

#define SIGNIFICANT_DIGITS_DIPLAYED 3
//#define MAX_SAMPLES                 (256 * NUMBER_OF_CYCLES_TO_ANALYSE)

class StreamTableRow : public QObject
{
    Q_OBJECT
public:
    StreamTableRow(QObject *parent = 0);
    explicit StreamTableRow(Stream *stream, QObject *parent = 0);

    void setup(Stream *stream);
    void appendFreqPoint(quint32 i, qreal x, qreal y) {
        if (i >= 0 && i < 8) {
            this->freq[i].append(QPointF(x, y));
        }
    }

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

    bool isAnalysed() {
        return this->analysed;
    }

    ExternalOutputs_measure *getData() {
        return &measure_Y;
    }
signals:
    
public slots:

private:
    bool status;
    QString svID;
    QString sourceMAC;
    QString destMAC;
    SampleRate sampleRate;

    bool analysed;
    ExternalOutputs_measure measure_Y;
    QPainterPath paths[8];
    //qreal sampledData[8][MAX_SAMPLES];
    QList<Sample> sampledData;
    QList<QPointF> freq[8];
    
};

#endif // STREAMTABLEROW_H
