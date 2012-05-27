#ifndef PHASOR_H
#define PHASOR_H

#include <QGraphicsScene>
#include <qmath.h>
#include <QGraphicsView>
#include "streamtablemodel.h"

class PhasorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    PhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    //virtual void streamSelectionChanged(QString svID);
    void streamSelectionChanged(Stream *stream);

protected:
    //PhasorLine *phasorLine[3];
    StreamTableModel *tableModel;
    Stream *stream;

    virtual qreal getPhasorMag(int phase);
    virtual qreal getPhasorAngle(int phase);

private:
    //TODO: add lines and circles for plot
    QPen pen;
    QGraphicsLineItem *phaseA;      // TODO: refactor to array
    QGraphicsLineItem *phaseB;
    QGraphicsLineItem *phaseC;
};

class CurrentPhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    CurrentPhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(int phase);
    qreal getPhasorAngle(int phase);

};

class VoltagePhasorScene : public PhasorScene
{
    Q_OBJECT
public:
    VoltagePhasorScene(StreamTableModel *tableModel, QObject *parent = 0);

public slots:
    //void streamSelectionChanged(QString svID);

protected:

    qreal getPhasorMag(int phase);
    qreal getPhasorAngle(int phase);

};

#endif // PHASOR_H
