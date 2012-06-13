#ifndef FREQUENCYSCENE_H
#define FREQUENCYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "streamtablemodel.h"

class FrequencyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit FrequencyScene(QObject *parent = 0);
    void streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index);
    void streamRemoved();
signals:
    
public slots:

protected:
    StreamTableModel *streamTableModel;
    QPersistentModelIndex *index;

private:
    void draw();
    
};

#endif // FREQUENCYSCENE_H
