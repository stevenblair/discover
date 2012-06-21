#ifndef PLOTSCENE_H
#define PLOTSCENE_H

#include <QGraphicsScene>
#include "stream.h"
#include "streamtablemodel.h"

#define X_AXIS_OVERSHOOT    0.06
#define Y_AXIS_OVERSHOOT    0.2

class PlotScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PlotScene(QObject *parent = 0);
    QRectF itemsBoundingRect() const;
    QRectF sceneRect() const;

    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();
signals:

public slots:
    //void streamSelectionChanged(Stream *stream);
    //void streamChanged();

protected:
    virtual Stream::PowerSystemQuantity getPowerSystemQuantity();
    QString getXUnits() {return xUnits;}
    QString getYUnits() {return yUnits;}

    QString xUnits;
    QString yUnits;

    StreamTableModel *streamTableModel;
    QPersistentModelIndex *index;

    //QRectF itemsBoundingRectWithoutText();
    //QRectF itemsBoundingRect() const;

private:
    //Stream *stream;

    QPen pen[3];
    QPen plotLinePen;
    QPen plotLinePenDashed;
    QPainterPath path[3];
    QGraphicsPathItem *plot[3];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QGraphicsTextItem *xAxisLabels[NUMBER_OF_CYCLES_TO_ANALYSE + 1];
    QGraphicsTextItem *yAxisLabelPositive;
    QGraphicsTextItem *yAxisLabelNegative;
    QGraphicsLineItem *xAxisTicks[NUMBER_OF_CYCLES_TO_ANALYSE];     // don't need a tick at (0.0, 0.0)
    QGraphicsLineItem *yAxisTicks[2];

    bool drawnOnce;
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
