#ifndef FREQUENCYSCENE_H
#define FREQUENCYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPathItem>
#include "streamtablemodel.h"

class FrequencyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    static const QColor waveformColors[TOTAL_SIGNALS];

    explicit FrequencyScene(QObject *parent = 0);
    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();
    void setWaveformState(int waveform, bool newState) {
        if (waveform >= 0 && waveform < TOTAL_SIGNALS) {
            activeWaveform[waveform] = newState;
            draw();
        }
    }
    bool getWaveformState(int waveform) {
        if (waveform >= 0 && waveform < TOTAL_SIGNALS) {
            return activeWaveform[waveform];
        }
        return false;
    }

signals:
    void callRedrawFrequencyScene();
    
public slots:
    void redrawFrequencyScene();

protected:
    StreamTableModel *streamTableModel;
    QPersistentModelIndex *index;
    bool activeWaveform[TOTAL_SIGNALS];

private:
    void draw();

    QPainterPath path[TOTAL_SIGNALS];
    QPen pen[TOTAL_SIGNALS];
    QGraphicsPathItem *pathItem[TOTAL_SIGNALS];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    QList<QGraphicsLineItem *> harmonicLine[TOTAL_SIGNALS];
    
};

#endif // FREQUENCYSCENE_H
