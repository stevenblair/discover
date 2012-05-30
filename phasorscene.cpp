#include "phasorscene.h"
#include "phasorline.h"
#include "phasorview.h"
#include <QDebug>

PhasorScene::PhasorScene(StreamTableModel *tableModel, QObject *parent) : QGraphicsScene(parent)
{
    this->tableModel = tableModel;  //TODO: remove?
    setSceneRect(PHASOR_VIEW_WIDTH / -2.0, PHASOR_VIEW_WIDTH / -2.0, PHASOR_VIEW_WIDTH, PHASOR_VIEW_WIDTH);

    QColor lineColors[3] = {QColor(180, 33, 38, PHASOR_LINE_ALPHA), QColor(240, 181, 0, PHASOR_LINE_ALPHA), QColor(36, 78, 198, PHASOR_LINE_ALPHA)};
    QColor plotLineColor = QColor(180, 180, 180);

    plotLinePen = QPen(plotLineColor);
    plotLineCiclePen = QPen(plotLineColor);
    plotLineCiclePen.setStyle(Qt::DashLine);
    outerPlotLine = this->addEllipse(-PHASOR_VIEW_MAX_PHASOR_SIZE, -PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE, plotLineCiclePen);
    outerPlotLine = this->addEllipse(-PHASOR_VIEW_MAX_PHASOR_SIZE / 2, -PHASOR_VIEW_MAX_PHASOR_SIZE / 2, PHASOR_VIEW_MAX_PHASOR_SIZE, PHASOR_VIEW_MAX_PHASOR_SIZE, plotLineCiclePen);
    horizontalPlotLine = QGraphicsScene::addLine(-PHASOR_VIEW_MAX_SIZE, 0.0, PHASOR_VIEW_MAX_SIZE, 0.0, plotLinePen);
    verticalPlotLine = QGraphicsScene::addLine(0.0, -PHASOR_VIEW_MAX_SIZE, 0.0, PHASOR_VIEW_MAX_SIZE, plotLinePen);
    zeroDegText = QGraphicsScene::addText(QString("0°"));
    zeroDegText->setPos(PHASOR_VIEW_MAX_PHASOR_SIZE, 0.0);
    zeroDegText->setDefaultTextColor(plotLineColor);
    nintyDegText = QGraphicsScene::addText(QString("90°"));
    nintyDegText->setPos(0.0, -PHASOR_VIEW_MAX_PHASOR_SIZE/* - twoSeventyDegText->boundingRect().height()*/);
    nintyDegText->setDefaultTextColor(plotLineColor);
    oneEightyDegText = QGraphicsScene::addText(QString("180°"));
    oneEightyDegText->setPos(-PHASOR_VIEW_MAX_PHASOR_SIZE/* - oneEightyDegText->boundingRect().width()*/, 0.0);
    oneEightyDegText->setDefaultTextColor(plotLineColor);
    minusNinetyDegText = QGraphicsScene::addText(QString("-90°"));
    minusNinetyDegText->setPos(0.0, PHASOR_VIEW_MAX_PHASOR_SIZE);
    minusNinetyDegText->setDefaultTextColor(plotLineColor);

    onePuText = QGraphicsScene::addText(QString("mag"));
    onePuText->setPos(PHASOR_VIEW_MAX_PHASOR_SIZE * 0.4, -PHASOR_VIEW_MAX_PHASOR_SIZE * 0.92 - onePuText->boundingRect().height());
    onePuText->setDefaultTextColor(plotLineColor);
    onePuText->hide();

    QFont font;
    font.setBold(true);
    font.setPointSize(9);

    for (int i = 0; i < 3; i++) {
        pen[i] = QPen(lineColors[i]);
        pen[i].setWidth(5);
        pen[i].setCapStyle(Qt::RoundCap);
        phaseLine[i] = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, pen[i]);
        phaseLine[i]->hide();
        phaseLabel[i] = QGraphicsScene::addText(getPhaseLabel(i));
        phaseLabel[i]->setFont(font);
        phaseLabel[i]->setDefaultTextColor(lineColors[i]);
        phaseLabel[i]->hide();
        //connect(phaseLine[i], hoverEnterEvent(QGraphicsSceneEvent *);     // need to sub-class to get this?
    }
}

void PhasorScene::streamSelectionChanged(Stream *stream)
{
    if (this->stream != NULL) {
        disconnect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved()));
        disconnect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
    }

    this->stream = stream;

    if (this->stream != NULL) {
        connect(this->stream, SIGNAL(removeView()), this, SLOT(streamRemoved()));
        connect(this->stream, SIGNAL(updateView()), this, SLOT(streamChanged()));
        draw();
        //update(QRect(-PHASOR_VIEW_MAX_PHASOR_SIZE, -PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE));
    }

//    if (this->stream != NULL) {
//        // TODO: connect to stream for updates; first disconnect any updates from an old stream

//        qreal maxMag = qMax(getPhasorMag(0), qMax(getPhasorMag(1), getPhasorMag(2)));
//        qreal scaleFactor = ((qreal) PHASOR_VIEW_MAX_PHASOR_SIZE) / maxMag;

//        //TODO: scale mags to maximum View size; always centre on (0,0)
//        for (int i = 0; i < 3; i++) {
//            qreal mag = scaleFactor * getPhasorMag(i);
//            qreal angle = getPhasorAngle(i);

//            //qDebug() << getPhasorMag(i) << maxMag << scaleFactor << mag << "coords:" << 0.0 << 0.0 << mag * cos(angle) << -1.0 * mag * sin(angle);

//            phaseLine[i]->setLine(0.0, 0.0, mag * cos(angle), -1.0 * mag * sin(angle));
//        }

//        //((QGraphicsView *) this->views().first())->update();
//        //((QGraphicsView *) this->views().first())->fitInView(this->itemsBoundingRect(), Qt::KeepAspectRatio);
//        //((QGraphicsView *) this->views().first())->scale(0.5, 0.5);
//        //((QGraphicsView *) this->views().first())->centerOn(0.0, 0.0);
//        //((QGraphicsView *) this->views().first())->fitInView(QRect(0, 0, 300, 300));

//        /*const QRectF rect = QRectF(-1 * PHASOR_VIEW_MAX_SIZE - 5, -1 * PHASOR_VIEW_MAX_SIZE - 5, PHASOR_VIEW_WIDTH, PHASOR_VIEW_WIDTH);
//        ((QGraphicsView *) this->views().first())->fitInView(rect, Qt::KeepAspectRatio);
//        ((QGraphicsView *) this->views().first())->setSceneRect(rect);

//        invalidate(this->itemsBoundingRect());*/
    //    }
}

void PhasorScene::streamChanged()
{
    draw();
    //update(QRect(-PHASOR_VIEW_MAX_PHASOR_SIZE, -PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE));
}

void PhasorScene::streamRemoved()
{
    this->stream = NULL;
    for (int i = 0; i < 3; i++) {
        phaseLine[i]->setLine(0.0, 0.0, 0.0, 0.0);
        phaseLine[i]->hide();
        phaseLabel[i]->hide();
        onePuText->hide();
    }
    //update(QRect(-PHASOR_VIEW_MAX_PHASOR_SIZE, -PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE, 2 * PHASOR_VIEW_MAX_PHASOR_SIZE));
}

void PhasorScene::draw() {
    if (this->stream != NULL && stream->isAnalysed()) {
        // TODO: connect to stream for updates; first disconnect any updates from an old stream

        qreal maxMag = qMax(getPhasorMag(0), qMax(getPhasorMag(1), getPhasorMag(2)));
        qreal scaleFactor = ((qreal) PHASOR_VIEW_MAX_PHASOR_SIZE) / maxMag;

        onePuText->setPlainText(QString("%1 %2").arg(maxMag / 1000.0, 0, 'g', 3).arg(getUnits()));
        onePuText->show();

        //TODO: scale mags to maximum View size; always centre on (0,0)
        for (int i = 0; i < 3; i++) {
            qreal mag = scaleFactor * getPhasorMag(i);
            qreal angle = getPhasorAngle(i);

            //qDebug() << getPhasorMag(i) << maxMag << scaleFactor << mag << "coords:" << 0.0 << 0.0 << mag * cos(angle) << -1.0 * mag * sin(angle);

            phaseLine[i]->setLine(0.0, 0.0, mag * cos(angle), -1.0 * mag * sin(angle));
            phaseLine[i]->setToolTip(this->getToolTipText(i));
            phaseLine[i]->show();

            QPointF labelPoint;
            if (angle > 0.0 && angle <= M_PI_2) {
                labelPoint = phaseLine[i]->boundingRect().topRight();
                labelPoint.setY(labelPoint.y() - phaseLabel[i]->boundingRect().height());
            }
            else if (angle > M_PI_2 && angle <= M_PI) {
                labelPoint = phaseLine[i]->boundingRect().topLeft();
                labelPoint.setX(labelPoint.x() - phaseLabel[i]->boundingRect().width());
                labelPoint.setY(labelPoint.y() - phaseLabel[i]->boundingRect().height());
            }
            else if (angle <= 0.0 && angle > -M_PI_2) {
                labelPoint = phaseLine[i]->boundingRect().bottomRight();
            }
            else if (angle <= -M_PI_2 && angle > -M_PI) {
                labelPoint = phaseLine[i]->boundingRect().bottomLeft();
                labelPoint.setX(labelPoint.x() - phaseLabel[i]->boundingRect().width());
            }
            phaseLabel[i]->setPlainText(getPhaseLabel(i));
            phaseLabel[i]->setPos(labelPoint);
            phaseLabel[i]->show();
        }
        PhasorView *view = ((PhasorView *)this->views().first());
        QMatrix matrix;
        matrix.scale(1.0, 1.0);
        view->setMatrix(matrix);
    }
}

QString PhasorScene::getToolTipText(int phase)
{
    Q_UNUSED(phase);
    return QString();
}

qreal PhasorScene::getPhasorMag(int phase)
{
    return 0.0;
}

qreal PhasorScene::getPhasorAngle(int phase)
{
    return 0.0;
}

QString PhasorScene::getPhaseLabel(int phase)
{
    return QString();
}

QString PhasorScene::getUnits()
{
    return QString();
}

QString PhasorScene::phaseNumberToText(int phase) {
    if (phase == 0) {
        return QString("a");
    }
    else if (phase == 1) {
        return QString("b");
    }
    else if (phase == 2) {
        return QString("c");
    }
    return QString("");
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

QString CurrentPhasorScene::getPhaseLabel(int phase)
{
    return QString("I" + phaseNumberToText(phase));
}

QString CurrentPhasorScene::getUnits()
{
    return QString("kA");
}

QString CurrentPhasorScene::getToolTipText(int phase)
{
    return QString("I%1: %2 %3 %4° %5").arg(phaseNumberToText(phase)).arg(getPhasorMag(phase), 0, 'f', 1).arg(QString::fromUtf8("\u2220")).arg(getPhasorAngle(phase) * 180.0 / M_PI, 0, 'f', 1).arg(getUnits());
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

QString VoltagePhasorScene::getPhaseLabel(int phase)
{
    return QString("V" + phaseNumberToText(phase));
}

QString VoltagePhasorScene::getUnits()
{
    return QString("kV");
}

QString VoltagePhasorScene::getToolTipText(int phase)
{
    return QString("V%1: %2 %3 %4° %5").arg(phaseNumberToText(phase)).arg(getPhasorMag(phase), 0, 'f', 1).arg(QString::fromUtf8("\u2220")).arg(getPhasorAngle(phase) * 180.0 / M_PI, 0, 'f', 1).arg(getUnits());
}
