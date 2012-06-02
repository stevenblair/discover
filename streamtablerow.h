#ifndef STREAMTABLEROW_H
#define STREAMTABLEROW_H

class Stream;

#include <QObject>
#include "stream.h"
#include "samplerate.h"
#include "measure/measure.h"

class StreamTableRow : public QObject
{
    Q_OBJECT
public:
    explicit StreamTableRow(QObject *parent = 0);
    explicit StreamTableRow(Stream *stream, QObject *parent = 0);
    
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
    
};

#endif // STREAMTABLEROW_H
