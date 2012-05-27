#include "phasorscene.h"
#include "phasorline.h"
#include "mainwindow.h"
#include <QDebug>

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

    qreal maxMag = qMax(getPhasorMag(0), qMax(getPhasorMag(1), getPhasorMag(2)));
    qreal scaleFactor = ((qreal) PHASOR_VIEW_MAX_PHASOR_SIZE) / maxMag;

    //TODO: scale mags to maximum View size; always centre on (0,0)
    for (int i = 0; i < 3; i++) {
        qreal mag = scaleFactor * getPhasorMag(i);
        qreal angle = getPhasorAngle(i);

        qDebug() << getPhasorMag(i) << maxMag << scaleFactor << mag;

        phaseLine[i]->setLine(0.0, 0.0, mag * cos(angle), -1.0 * mag * sin(angle));
    }

    //((QGraphicsView *) this->views().first())->update();
    //((QGraphicsView *) this->views().first())->fitInView(this->itemsBoundingRect(), Qt::KeepAspectRatio);
    //((QGraphicsView *) this->views().first())->scale(0.5, 0.5);
    ((QGraphicsView *) this->views().first())->centerOn(0.0, 0.0);
    //((QGraphicsView *) this->views().first())->fitInView(QRect(0, 0, 300, 300));

    const QRectF rect = QRectF(-PHASOR_VIEW_MAX_SIZE, -PHASOR_VIEW_MAX_SIZE, PHASOR_VIEW_WIDTH, PHASOR_VIEW_WIDTH);
    //((QGraphicsView *) this->views().first())->fitInView(rect, Qt::KeepAspectRatio);
    ((QGraphicsView *) this->views().first())->setSceneRect(rect);

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
