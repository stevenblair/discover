/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2012 Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "FrequencyScene.h"
#include <qmath.h>
#include <QTextBlockFormat>
#include <QTextCursor>

#define VOLTAGE_LINE_ALPHA  255
#define CURRENT_LINE_ALPHA  180
#define MIN_Y_VALUE         0.0//1       // -log10(0.1)
#define LINE_WIDTH          8
#define LINE_SPACING        1.0

const QString FrequencyScene::PhaseLables[3] = {QString("A"), QString("B"), QString("C")};

const QColor FrequencyScene::waveformColors[3] = {QColor(180, 33, 38, VOLTAGE_LINE_ALPHA),
                                                  QColor(240, 181, 0, VOLTAGE_LINE_ALPHA),
                                                  QColor(36, 78, 198, VOLTAGE_LINE_ALPHA)};


FrequencyScene::FrequencyScene(QObject *parent) : QGraphicsScene(parent)
{
    QColor plotLineColor = QColor(180, 180, 180);

    plotLinePenDashed = QPen(plotLineColor);
    plotLinePenDashed.setCosmetic(true);
    plotLinePenDashed.setStyle(Qt::DashLine);

    for (int i = 0; i < 3; i++) {
        activeWaveform[i] = true;
//        // enable only the first waveform by default
//        if (i == 0) {
//            activeWaveform[i] = true;
//        }
//        else {
//            activeWaveform[i] = false;
//        }

        pen[i] = QPen(waveformColors[i]);
        pen[i].setCapStyle(Qt::FlatCap);
        pen[i].setWidth(LINE_WIDTH);
    }

    QPen plotLinePen = QPen(plotLineColor);
    plotLinePen.setCosmetic(true);
    //plotLinePen.setWidth(5);
    //plotLinePen.setCapStyle(Qt::RoundCap);

    horizontalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);
    //horizontalPlotLine->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    verticalPlotLine = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, plotLinePen);
    //verticalPlotLine->setFlag(QGraphicsItem::ItemIgnoresTransformations);

    connect(this, SIGNAL(callRedrawFrequencyScene()), this, SLOT(redrawFrequencyScene()));
}

void FrequencyScene::streamTableModelSelectionChanged(StreamTableModel *streamTableModel, QPersistentModelIndex *index)
{
    this->streamTableModel = streamTableModel;
    this->index = index;

    //qDebug() << "in FrequencyScene::streamTableModelSelectionChanged()" << this->index->row() << this->streamTableModel;

    emit callRedrawFrequencyScene();
}

void FrequencyScene::streamRemoved()
{
    for (int i = 0; i < 3; i++) {
        if (!harmonicLine[i].isEmpty()) {
            QListIterator<QGraphicsLineItem *> lines (harmonicLine[i]);
            while (lines.hasNext()) {
                QGraphicsLineItem *line = lines.next();
                line->hide();
            }
        }
    }
}

void FrequencyScene::redrawFrequencyScene()
{
    draw();
}


qreal FrequencyScene::getFundamental(QPointer<StreamTableRow> stream, int phase)
{
    if (stream != NULL) {
        return stream->getData()->VoltageFundMagVoltsRMS3[phase];
    }

    return 0.0;
}

qreal FrequencyScene::getHarmonic(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->VoltageHarmonicsAnalysed[harmonicIndex];
    }

    return 0.0;
}

qreal FrequencyScene::getHarmonicMag(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->VoltageAmplitudesRelativeToFundamental[harmonicIndex];
    }

    return 0.0;
}

qreal FrequencyScene::getHarmonicAng(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->VoltageAmplitudesRelativeToFundamental[harmonicIndex];
    }

    return 0.0;
}


CurrentFrequencyScene::CurrentFrequencyScene(QObject *parent) : FrequencyScene(parent)
{
}

qreal CurrentFrequencyScene::getFundamental(QPointer<StreamTableRow> stream, int phase)
{
    if (stream != NULL) {
        return stream->getData()->Current[phase];
    }

    return 0.0;
}

qreal CurrentFrequencyScene::getHarmonic(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->CurrentHarmonicsAnalysed[harmonicIndex];
    }

    return 0.0;
}

qreal CurrentFrequencyScene::getHarmonicMag(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->CurrentAmplitudesRelativeToFundamental[harmonicIndex];
    }

    return 0.0;
}

qreal CurrentFrequencyScene::getHarmonicAng(QPointer<StreamTableRow> stream, int harmonicIndex)
{
    if (stream != NULL) {
        return stream->getData()->CurrentPhasesRelativeToFundamental[harmonicIndex];
    }

    return 0.0;
}

void FrequencyScene::draw() {
    QPointer<StreamTableRow> stream;
    QColor plotLineColor = QColor(180, 180, 180);

    if (this->streamTableModel != NULL && this->index != NULL && this->index->isValid()) {
        stream = this->streamTableModel->getRowFromIndex(this->index);
    }
    else {
        return;
    }

    if (stream.isNull()) {
        return;
    }

    const quint32 totalHarmonics = stream->getData()->TotalHarmonicsAnalysedIncludingFundamental;

    if (!xLabels.isEmpty()) {
        QListIterator<QGraphicsTextItem *> labels (xLabels);
        while (labels.hasNext()) {
            QGraphicsTextItem *label = labels.next();
            xLabels.removeOne(label);
            this->removeItem(label);
            delete label;
        }
        xLabels.clear();
    }

    if (!xAxisTicks.isEmpty()) {
        QListIterator<QGraphicsLineItem *> ticks (xAxisTicks);
        while (ticks.hasNext()) {
            QGraphicsLineItem *tick = ticks.next();
            xAxisTicks.removeOne(tick);
            this->removeItem(tick);
            delete tick;
        }
        xAxisTicks.clear();
    }

    for (quint32 n = 0; n < totalHarmonics; n++) {
        //QFont font = QFont();
        //font.setPixelSize(8);

        qreal x = 0.0;

        if (n == 0) {
            // fundamental, or 1st harmonic
            x = 1.0 * stream->getData()->Frequency;
        }
        else {
            // all other harmonics
            int harmonicIndex = (totalHarmonics - 1) + n - 1;
            x = getHarmonic(stream, harmonicIndex) * stream->getData()->Frequency;
        }

        QGraphicsLineItem *tickLine = QGraphicsScene::addLine(x, 0.0, x, -ONE_PU_HEIGHT, plotLinePenDashed);
        xAxisTicks.append(tickLine);

        if (n == 0 || n % 3 == 2) {
            QGraphicsTextItem *label = new QGraphicsTextItem;
            label->setDefaultTextColor(plotLineColor);
            label->setFlag(QGraphicsItem::ItemIgnoresTransformations);
            this->addItem(label);
            label->hide();
            xLabels.append(label);

            label->setPlainText(QString("%1 Hz").arg(x, 0, 'f', 1));
            label->setToolTip(QString("%1 Hz (%2 harmonic number)").arg(x, 0, 'f', 1).arg(n + 1, 0, 'f', 0));

            // centre the text
            QTextBlockFormat format;
            format.setAlignment(Qt::AlignHCenter);
            QTextCursor cursor = label->textCursor();
            cursor.select(QTextCursor::Document);
            cursor.mergeBlockFormat(format);
            cursor.clearSelection();
            label->setTextCursor(cursor);

            // find width of text and set position
            QPointF topLeft = this->views().first()->mapToScene(
                    (int) label->boundingRect().topLeft().x(),
                    (int) label->boundingRect().topLeft().y() );
            QPointF bottomRight = this->views().first()->mapToScene(
                    (int) label->boundingRect().bottomRight().x(),
                    (int) label->boundingRect().bottomRight().y() );
            double width = bottomRight.x() - topLeft.x();
            QPoint offset;
            offset.setX((int) (-width / 2.0));
            offset.setY(0);
            label->setPos(x + offset.x(), 0 + offset.y());

            if (!label->isVisible()) {
                label->show();
            }
        }
    }

    //TODO: only delete existing lines if index has changed
    for (int i = 0; i < 3; i++) {
        if (!harmonicLine[i].isEmpty()) {
            QListIterator<QGraphicsLineItem *> lines (harmonicLine[i]);
            while (lines.hasNext()) {
                QGraphicsLineItem *line = lines.next();
                harmonicLine[i].removeOne(line);
                this->removeItem(line);
                delete line;
            }
            harmonicLine[i].clear();
        }

        for (quint32 n = 0; n < totalHarmonics; n++) {
            QGraphicsLineItem *line = QGraphicsScene::addLine(0.0, 0.0, 0.0, 0.0, pen[i]);
            line->hide();
            harmonicLine[i].append(line);
        }
    }

    qreal maxFreqValue = getHarmonic(stream, totalHarmonics - 2) * stream->getData()->Frequency;//(stream->getFreqPoint(0, stream->getNumberOfFreqPoints(0) - 1).x());
    qreal maxMagnitudeValue = -(1.0 * ONE_PU_HEIGHT/*stream->getFreqPoint(0, stream->getNumberOfFreqPoints(0) - 1).y()*/);

    horizontalPlotLine->setLine(0.0, MIN_Y_VALUE, maxFreqValue, MIN_Y_VALUE);
    verticalPlotLine->setLine(0.0, MIN_Y_VALUE, 0.0, maxMagnitudeValue);


    // TODO: create map from label to line, or to x-value?
    for (quint32 n = 0; n < totalHarmonics; n++) {

    }

    QGraphicsView *view = this->views().first();
    //qDebug() << this->views().size() << this->views().first();
    view->fitInView(this->sceneRect(), Qt::IgnoreAspectRatio);

    // define 1 pu as the max fundamental magnitude
    qreal maxFundamental = qMax(getFundamental(stream, 0), qMax(getFundamental(stream, 1), getFundamental(stream, 2)));

    for (int signal = 0; signal < 3; signal++) {
        if (this->getWaveformState(signal) == true) {
            for (quint32 n = 0; n < totalHarmonics; n++) {
                QGraphicsLineItem *line = harmonicLine[signal].at(n);

                if (line != NULL) {
                    qreal x;
                    qreal y;
                    qreal phaseDeg = 0.0;
                    qreal absoluteScale = getFundamental(stream, signal) / maxFundamental;

                    if (n == 0) {
                        // fundamental, or 1st harmonic
                        x = 1.0 * stream->getData()->PhaseFrequency[signal];
                        //y = stream->getData()->VoltageFundMagVoltsRMS3[signal] * qSqrt(2.0) / stream->getMaxInstantaneous(Stream::Voltage); // TODO: get max magnitude from model

                        // set fundamental relative to 1 pu reference
                        y = absoluteScale;
                    }
                    else {
                        // all other harmonics
                        int harmonicIndex = (signal * (totalHarmonics - 1)) + n - 1;

                        x = getHarmonic(stream, harmonicIndex) * stream->getData()->PhaseFrequency[signal];
                        y = absoluteScale * getHarmonicMag(stream, harmonicIndex);//stream->getData()->VoltageAmplitudesRelativeToFundamental[harmonicIndex];
                        phaseDeg = 180.0 * getHarmonicAng(stream, harmonicIndex) / M_PI;
                    }

                    qreal x_adjusted = x;

                    if (signal == 0) {
                        x_adjusted -= LINE_WIDTH * LINE_SPACING;
                    }
                    else if (signal == 2) {
                        x_adjusted += LINE_WIDTH * LINE_SPACING;
                    }

                    if (y > DISPLAY_HARMONIC_CUTOFF) {
                        line->setLine(x_adjusted, 0.0, x_adjusted, -ONE_PU_HEIGHT * y);
                        line->setToolTip(QString("Phase %1: %2 pu %3 %4°, at %5 Hz")
                                         .arg(FrequencyScene::PhaseLables[signal])
                                         .arg(y, 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED)
                                         .arg(QString::fromUtf8("\u2220"))
                                         .arg(phaseDeg, 0, 'f', 0)
                                         .arg(x, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED_FREQ));
                        line->show();
                    }
                }
            }
        }
        else {
            for (quint32 n = 0; n < totalHarmonics; n++) {
                QGraphicsLineItem *line = harmonicLine[signal].at(n);

                if (line != NULL) {
                    line->hide();
                }
            }
        }
    }

    view->fitInView(this->sceneRect(), Qt::IgnoreAspectRatio);


    for (quint32 n = 0; n < totalHarmonics; n++) {
//        QGraphicsLineItem *line = harmonicLine[0].at(n);

//        if (line != NULL) {
//            QFont font = QFont();
//            font.setPixelSize(10);
//            QGraphicsTextItem *text = new QGraphicsTextItem;
//            text->setFont(font);
//            text->setPos(line->x(), 0.02);
//            text->setPlainText(QString("%1").arg(-line->y()));
//            text->setFlag(QGraphicsItem::ItemIgnoresTransformations);
//            this->addItem(text);
//        }
    }

    //qDebug() << stream->getFreqPoint(0, stream->getNumberOfFreqPoints(0) - 1).x();
}
