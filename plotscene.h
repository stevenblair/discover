#ifndef PLOTSCENE_H
#define PLOTSCENE_H

#include <QGraphicsScene>
#include "stream.h"

class PlotScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PlotScene(QObject *parent = 0);

signals:

public slots:
    void streamSelectionChanged(Stream *stream);
    void streamChanged();

protected:
    virtual Stream::PowerSystemQuantity getPowerSystemQuantity();

private:
    Stream *stream;

    QPen pen[3];
    QPen plotLinePen;
    QPainterPath path[3];
    QGraphicsPathItem *plot[3];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;

    void draw();

};





class VoltagePlotScene : public PlotScene
{
    Q_OBJECT
public:
    explicit VoltagePlotScene(QObject *parent = 0);

signals:

public slots:

protected:
    Stream::PowerSystemQuantity getPowerSystemQuantity();

};




class CurrentPlotScene : public PlotScene
{
    Q_OBJECT
public:
    explicit CurrentPlotScene(QObject *parent = 0);

signals:

public slots:

protected:
    Stream::PowerSystemQuantity getPowerSystemQuantity();

};

#endif // PLOTSCENE_H
