#include "FrequencyScene.h"

FrequencyScene::FrequencyScene(QObject *parent) : QGraphicsScene(parent)
{
}

void FrequencyScene::streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index)
{
    this->streamTableModel = streamTableModel;
    this->index = index;

    //qDebug() << "in streamTableModelSelectionChanged()" << this->index->row() << this->streamTableModel;

    draw();
}

void FrequencyScene::streamRemoved()
{
    // TODO
}
