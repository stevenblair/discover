#include "phasor.h"
#include "phasorline.h"

PhasorScene::PhasorScene(StreamTableModel *tableModel, QObject *parent) : QGraphicsScene(parent)
{
    this->tableModel = tableModel;

    phasorLine[0] = new PhasorLine(5.0, 2.0);
    phasorLine[1] = new PhasorLine(1.0, 1.0);
    phasorLine[2] = new PhasorLine(1.5, 3.1);

    this->addItem(phasorLine[0]);
    this->addItem(phasorLine[1]);
    this->addItem(phasorLine[2]);
}

void PhasorScene::streamSelectionChanged(QString svID)
{
    Stream *stream = tableModel->getPhasorData(svID);

    if (stream != NULL && stream->isAnalysed()) {
        phasorLine[0]->setPhasorData(10.0, -60.0);     // TODO: use actual data from stream
        phasorLine[1]->setPhasorData(-10.0, 60.0);
        phasorLine[2]->setPhasorData(10.5, 30.0);
    }
}
