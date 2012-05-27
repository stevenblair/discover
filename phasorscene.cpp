#include "phasorscene.h"
#include "phasorline.h"

PhasorScene::PhasorScene(StreamTableModel *tableModel, QObject *parent) : QGraphicsScene(parent)
{
    this->pen = QPen();
    pen.setWidth(4);
    pen.setCapStyle(Qt::RoundCap);

    this->tableModel = tableModel;

    this->phaseA = QGraphicsScene::addLine(0.0, 0.0, 1.0, 0.0, pen);
    this->phaseB = QGraphicsScene::addLine(0.0, 0.0, 0.0, 1.0, pen);
    this->phaseC = QGraphicsScene::addLine(0.0, 0.0, 1.0, 1.0, pen);

//    phasorLine[0] = new PhasorLine();
//    phasorLine[1] = new PhasorLine();
//    phasorLine[2] = new PhasorLine();

//    this->addItem(phasorLine[0]);
//    this->addItem(phasorLine[1]);
//    this->addItem(phasorLine[2]);
}

void PhasorScene::streamSelectionChanged(Stream *stream)
{
    this->stream = stream;

    //TODO: scale mags to maximum View size; always centre on (0,0)
    phaseA->setLine(0.0, 0.0, getPhasorMag(0) * cos(getPhasorAngle(0)), -1.0 * getPhasorMag(0) * sin(getPhasorAngle(0)));
    phaseB->setLine(0.0, 0.0, getPhasorMag(1) * cos(getPhasorAngle(1)), -1.0 * getPhasorMag(1) * sin(getPhasorAngle(1)));
    phaseC->setLine(0.0, 0.0, getPhasorMag(2) * cos(getPhasorAngle(2)), -1.0 * getPhasorMag(2) * sin(getPhasorAngle(2)));

    //((QGraphicsView *) this->views().first())->update();
    //((QGraphicsView *) this->views().first())->fitInView(this->itemsBoundingRect(), Qt::KeepAspectRatio);
    ((QGraphicsView *) this->views().first())->centerOn(0.0, 0.0);
    invalidate(this->itemsBoundingRect());
}

qreal PhasorScene::getPhasorMag(int phase)
{
    return 0.0;
}

qreal PhasorScene::getPhasorAngle(int phase)
{
    return 0.0;
}

//void CurrentPhasorScene::streamSelectionChanged(QString svID)
//{
//    Stream *stream = tableModel->getPhasorData(svID);

//    if (stream != NULL && stream->isAnalysed()) {
//        phasorLine[0]->setPhasorData(stream/*->getStreamData()->Current[0], &stream->getStreamData()->Current[4]*/);
//        phasorLine[1]->setPhasorData(stream/*->getStreamData()->Current[1], &stream->getStreamData()->Current[5]*/);
//        phasorLine[2]->setPhasorData(stream/*->getStreamData()->Current[2], &stream->getStreamData()->Current[6]*/);
//    }
//}



CurrentPhasorScene::CurrentPhasorScene(StreamTableModel *tableModel, QObject *parent) : PhasorScene(tableModel, parent)
{
}

qreal CurrentPhasorScene::getPhasorMag(int phase)
{
    if (stream != NULL) {
        return stream->getStreamData()->Current[phase];
    }
    else {
        return PhasorScene::getPhasorMag(phase);
    }
}

qreal CurrentPhasorScene::getPhasorAngle(int phase)
{
    if (stream != NULL) {
        return stream->getStreamData()->Current[phase + 3];
    }
    else {
        return PhasorScene::getPhasorAngle(phase);
    }
}


//void VoltagePhasorScene::streamSelectionChanged(QString svID)
//{
//    Stream *stream = tableModel->getPhasorData(svID);

//    if (stream != NULL && stream->isAnalysed()) {
//        phasorLine[0]->setPhasorData(stream/*->getStreamData()->Voltage[0], &stream->getStreamData()->Voltage[4]*/);
//        phasorLine[1]->setPhasorData(stream/*->getStreamData()->Voltage[1], &stream->getStreamData()->Voltage[5]*/);
//        phasorLine[2]->setPhasorData(stream/*->getStreamData()->Voltage[2], &stream->getStreamData()->Voltage[6]*/);
//    }
//}

VoltagePhasorScene::VoltagePhasorScene(StreamTableModel *tableModel, QObject *parent) : PhasorScene(tableModel, parent)
{
}

qreal VoltagePhasorScene::getPhasorMag(int phase)
{
    if (stream != NULL) {
        return stream->getStreamData()->Voltage[phase];
    }
    else {
        return PhasorScene::getPhasorMag(phase);
    }
}

qreal VoltagePhasorScene::getPhasorAngle(int phase)
{
    if (stream != NULL) {
        return stream->getStreamData()->Voltage[phase + 3];
    }
    else {
        return PhasorScene::getPhasorAngle(phase);
    }
}
