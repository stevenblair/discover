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
    static const QColor waveformColors[8];

    explicit FrequencyScene(QObject *parent = 0);
    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();
    void setWaveformState(int waveform, bool newState) {
        if (waveform >= 0 && waveform < 8) {
            activeWaveform[waveform] = newState;
            draw();
        }
    }
    bool getWaveformState(int waveform) {
        if (waveform >= 0 && waveform < 8) {
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
    bool activeWaveform[8];

private:
    void draw();

    QPainterPath path[8];
    QPen pen[8];
    QGraphicsPathItem *pathItem[8];
    QGraphicsLineItem *horizontalPlotLine;
    QGraphicsLineItem *verticalPlotLine;
    
};

#endif // FREQUENCYSCENE_H
