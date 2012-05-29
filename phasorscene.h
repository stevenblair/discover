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
    void streamChanged();
    void streamRemoved();

protected:
    StreamTableModel *tableModel;
    Stream *stream;

    virtual qreal getPhasorMag(int phase);
    virtual qreal getPhasorAngle(int phase);

private:
    void draw();
    virtual QString getToolTipText(int phase);

    //TODO: add lines, circles and text labels for plot
    QPen pen[3];
    QPen plotLinePen;
    QPen plotLineCiclePen;
    QGraphicsLineItem *phaseLine[3];
    QGraphicsEllipseItem *outerPlotLine;
    QGraphicsEllipseItem *innerPlotLine;
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
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

private:

    QString getToolTipText(int phase);
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

private:

    QString getToolTipText(int phase);
};

#endif // PHASOR_H
