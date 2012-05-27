#include "phasorscene.h"
#include "phasorline.h"

PhasorScene::PhasorScene(StreamTableModel *tableModel, QObject *parent) : QGraphicsScene(parent)
{
    this->tableModel = tableModel;  //TODO: remove?

    QColor lineColors[3] = {QColor(180, 33, 38, 230), QColor(222, 215, 20, 230), QColor(36, 78, 198, 230)};

    for (int i = 0; i < 3; i++) {
        pen[i] = QPen();
        pen[i].setColor(lineColors[i]);
        pen[i].setWidth(4);
        pen[i].setCapStyle(Qt::RoundCap);
        this->phaseLine[i] = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, pen[i]);
    }
}

void PhasorScene::streamSelectionChanged(Stream *stream)
{
    this->stream = stream;

    //TODO: scale mags to maximum View size; always centre on (0,0)
    for (int i = 0; i < 3; i++) {
        phaseLine[i]->setLine(0.0, 0.0, getPhasorMag(i) * cos(getPhasorAngle(i)), -1.0 * getPhasorMag(i) * sin(getPhasorAngle(i)));
    }

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
