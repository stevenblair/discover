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
    void streamSelectionChanged(Stream *stream);

protected:
    StreamTableModel *tableModel;
    Stream *stream;

    virtual qreal getPhasorMag(int phase);
    virtual qreal getPhasorAngle(int phase);

private:
    //TODO: add lines, circles and text labels for plot
    QPen pen[3];
    QGraphicsLineItem *phaseLine[3];
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
