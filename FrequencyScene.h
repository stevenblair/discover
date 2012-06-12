#ifndef FREQUENCYSCENE_H
#define FREQUENCYSCENE_H

#include <QGraphicsScene>

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
    
};

#endif // FREQUENCYSCENE_H
