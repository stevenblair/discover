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

#define VOLTAGE_LINE_ALPHA  255
#define CURRENT_LINE_ALPHA  180
#define MIN_Y_VALUE         0.0//1       // -log10(0.1)
#define LINE_WIDTH          8

const QString FrequencyScene::PhaseLables[3] = {QString("A"), QString("B"), QString("C")};

const QColor FrequencyScene::waveformColors[TOTAL_SIGNALS] = {QColor(180, 33, 38, VOLTAGE_LINE_ALPHA),
                                                              QColor(240, 181, 0, VOLTAGE_LINE_ALPHA),
                                                              QColor(36, 78, 198, VOLTAGE_LINE_ALPHA),
                                                              QColor(180, 180, 180, VOLTAGE_LINE_ALPHA),
                                                              QColor(180, 33, 38, CURRENT_LINE_ALPHA),
                                                              QColor(240, 181, 0, CURRENT_LINE_ALPHA),
                                                              QColor(36, 78, 198, CURRENT_LINE_ALPHA),
                                                              QColor(180, 180, 180, CURRENT_LINE_ALPHA)};


FrequencyScene::FrequencyScene(QObject *parent) : QGraphicsScene(parent)
{
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

    QColor plotLineColor = QColor(180, 180, 180);

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
    for (int i = 0; i < TOTAL_SIGNALS; i++) {
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


CurrentFrequencyScene::CurrentFrequencyScene(QObject *parent) : FrequencyScene(parent)
{
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

void FrequencyScene::draw() {
    //qDebug() << "in FrequencyScene::draw()";
    QPointer<StreamTableRow> stream;

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

    for (quint32 n = 0; n < totalHarmonics; n++) {
        //QFont font = QFont();
        //font.setPixelSize(8);
        if (n % 2 == 0) {
            QGraphicsTextItem *label = new QGraphicsTextItem;
            label->setFlag(QGraphicsItem::ItemIgnoresTransformations);
            this->addItem(label);
            label->hide();
            xLabels.append(label);

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

            label->setPlainText(QString("%1").arg(x, 0, 'f', 1));
            //qDebug() << label->boundingRect().width() << label->boundingRect().right() - label->boundingRect().left();
            // TODO: fix scale of offset
            label->setPos(x - (label->boundingRect().width() / 2.0), 0.0);
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

    for (int signal = 0; signal < 3; signal++) {
        if (this->getWaveformState(signal) == true) {
            for (quint32 n = 0; n < totalHarmonics; n++) {
                QGraphicsLineItem *line = harmonicLine[signal].at(n);

                if (line != NULL) {
                    qreal x;
                    qreal y;

                    if (n == 0) {
                        // fundamental, or 1st harmonic
                        x = 1.0 * stream->getData()->PhaseFrequency[signal];
                        //y = stream->getData()->VoltageFundMagVoltsRMS3[signal] * qSqrt(2.0) / stream->getMaxInstantaneous(Stream::Voltage); // TODO: get max magnitude from model

                        // fundamental is always the 1 pu reference
                        y = 1.0;
                    }
                    else {
                        // all other harmonics
                        int harmonicIndex = (signal * (totalHarmonics - 1)) + n - 1;

                        x = getHarmonic(stream, harmonicIndex) * stream->getData()->PhaseFrequency[signal];
                        y = getHarmonicMag(stream, harmonicIndex);//stream->getData()->VoltageAmplitudesRelativeToFundamental[harmonicIndex];
                    }

                    qreal x_adjusted = x;

                    if (signal == 0) {
                        x_adjusted -= LINE_WIDTH * 1.2;
                    }
                    else if (signal == 2) {
                        x_adjusted += LINE_WIDTH * 1.2;
                    }

                    if (y > DISPLAY_HARMONIC_CUTOFF) {
                        line->setLine(x_adjusted, 0.0, x_adjusted, -ONE_PU_HEIGHT * y);
                        line->setToolTip(QString("Phase %1: %2 p.u. at %3 Hz").arg(FrequencyScene::PhaseLables[signal]).arg(y, 0, 'f', SIGNIFICANT_DIGITS_DIPLAYED).arg(x, 0, 'g', SIGNIFICANT_DIGITS_DIPLAYED_FREQ));
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
