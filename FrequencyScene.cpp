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

void FrequencyScene::draw() {
    qDebug() << "in FrequencyScene::draw()";
    StreamTableRow *stream;

    if (this->streamTableModel != NULL && this->index != NULL && this->index->isValid()) {
        stream = this->streamTableModel->getRowFromIndex(this->index);
    }
    else {
        return;
    }

    QPainterPath path;

    for (int i = 0; i < stream->getNumberOfFreqPoints(0); i++) {
        path.lineTo(stream->getFreqPoint(0, i));
    }
    QGraphicsPathItem *pathItem = QGraphicsScene::addPath(path);
    QGraphicsView *view = this->views().first();
    view->fitInView(this->sceneRect(), Qt::IgnoreAspectRatio);
}
