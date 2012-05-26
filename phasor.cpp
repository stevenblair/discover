#include "phasor.h"
#include <QDebug>

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
    qDebug() << svID;
}
