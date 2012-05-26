#include "phasorscene.h"
#include "phasorline.h"

PhasorScene::PhasorScene(StreamTableModel *tableModel, QObject *parent) : QGraphicsScene(parent)
{
    this->tableModel = tableModel;

    phasorLine[0] = new PhasorLine();
    phasorLine[1] = new PhasorLine();
    phasorLine[2] = new PhasorLine();

    this->addItem(phasorLine[0]);
    this->addItem(phasorLine[1]);
    this->addItem(phasorLine[2]);
}

void PhasorScene::streamSelectionChanged(QString svID)
{

}

void CurrentPhasorScene::streamSelectionChanged(QString svID)
{
    Stream *stream = tableModel->getPhasorData(svID);

    if (stream != NULL && stream->isAnalysed()) {
        phasorLine[0]->setPhasorData(stream/*->getStreamData()->Current[0], &stream->getStreamData()->Current[4]*/);
        phasorLine[1]->setPhasorData(stream/*->getStreamData()->Current[1], &stream->getStreamData()->Current[5]*/);
        phasorLine[2]->setPhasorData(stream/*->getStreamData()->Current[2], &stream->getStreamData()->Current[6]*/);
    }
}

CurrentPhasorScene::CurrentPhasorScene(StreamTableModel *tableModel, QObject *parent) : PhasorScene(tableModel, parent)
{
}


void VoltagePhasorScene::streamSelectionChanged(QString svID)
{
    Stream *stream = tableModel->getPhasorData(svID);

    if (stream != NULL && stream->isAnalysed()) {
        phasorLine[0]->setPhasorData(stream/*->getStreamData()->Voltage[0], &stream->getStreamData()->Voltage[4]*/);
        phasorLine[1]->setPhasorData(stream/*->getStreamData()->Voltage[1], &stream->getStreamData()->Voltage[5]*/);
        phasorLine[2]->setPhasorData(stream/*->getStreamData()->Voltage[2], &stream->getStreamData()->Voltage[6]*/);
    }
}

VoltagePhasorScene::VoltagePhasorScene(StreamTableModel *tableModel, QObject *parent) : PhasorScene(tableModel, parent)
{
}
