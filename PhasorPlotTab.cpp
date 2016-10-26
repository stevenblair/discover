/**
 * discover - a real-time monitoring and analysis tool for IEC 61850-9-2LE Sampled Values
 *
 * Copyright (c) 2013 Steven Blair
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

#include "PhasorPlotTab.h"
//#include <qgl.h>
#include <QFileDialog>

void PhasorPlotTab::update()
{
    voltagePhasorScene->streamTableModelSelectionChanged(this->model, &this->index);
    currentPhasorScene->streamTableModelSelectionChanged(this->model, &this->index);
    voltagePlotScene->streamTableModelSelectionChanged(this->model, &this->index);
    currentPlotScene->streamTableModelSelectionChanged(this->model, &this->index);

    QListIterator<QGraphicsView*> i (views);
    while (i.hasNext()) {
        const QGraphicsView *view = i.next();
        view->scene()->update();        // TODO: may need to override this (or other function or slot) in subclass?
    }
}

void PhasorPlotTab::removeView()
{
    voltagePhasorScene->streamRemoved();
    currentPhasorScene->streamRemoved();
    voltagePlotScene->streamRemoved();
    currentPlotScene->streamRemoved();
}

void PhasorPlotTab::saveOscillograms()
{
    const int currentPathCount = currentPlotScene->getPathCount();
    const QPainterPath * currentPath = currentPlotScene->getPath();

    const int voltagePathCount = voltagePlotScene->getPathCount();
    const QPainterPath * voltagePath = voltagePlotScene->getPath();

    if (currentPathCount != voltagePathCount) {
        return;
    }

    const int pathCount = currentPathCount;

    if (pathCount <= 0) {
        return;
    }

    const int elementCount = currentPath[0].elementCount();

    for (int i = 0; i < pathCount; i++) {
        if (
            currentPath[i].elementCount() != elementCount
            || voltagePath[i].elementCount() != elementCount
        ) {
            return;
        }
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("Saving oscillograms"));

    if (filename.isEmpty()) {
        return;
    }

    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    const char columnDelimiter = ';';

    QString header = tr("Time, ms");
    for (int p = 0; p < pathCount; p++) {
        header += columnDelimiter + tr("Current %L1, A").arg(p);
        header += columnDelimiter + tr("Voltage %L1, V").arg(p);
    }
    header += "\n";
    file.write(header.toUtf8());

    for (int e = 0; e < elementCount; e++) {
        const qreal time_ms  = currentPath[0].elementAt(e).x;

        qreal current[pathCount];
        qreal voltage[pathCount];

        for (int p = 0; p < pathCount; p++) {
            if (
                currentPath[p].elementAt(e).x != time_ms
                || voltagePath[p].elementAt(e).x != time_ms
            ) {
                return;
            }

            current[p] = currentPath[p].elementAt(e).y;
            voltage[p] = voltagePath[p].elementAt(e).y;
        }

        QByteArray line;

        line += QString("%L1").arg(time_ms).toLatin1();

        for (int p = 0; p < pathCount; p++) {
            line += columnDelimiter + QString("%L1").arg(current[p]).toLatin1();
            line += columnDelimiter + QString("%L1").arg(voltage[p]).toLatin1();
        }

        file.write(line + '\n');
    }
}

PhasorPlotTab::PhasorPlotTab(QWidget *parent) : TabViewWidget(parent)
{
    QGridLayout *graphLayout = new QGridLayout(this);

    currentPhasorScene = new CurrentPhasorScene();
    voltagePhasorScene = new VoltagePhasorScene();
    currentPhasorView = new PhasorView(this);
    voltagePhasorView = new PhasorView(this);
    currentPhasorView->setScene(currentPhasorScene);
    voltagePhasorView->setScene(voltagePhasorScene);

    currentPlotScene = new CurrentPlotScene();
    voltagePlotScene = new VoltagePlotScene();
    currentPlotView = new PlotView(this);
    voltagePlotView = new PlotView(this);
    currentPlotView->setScene(currentPlotScene);
    voltagePlotView->setScene(voltagePlotScene);

//    currentPhasorView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
//    voltagePhasorView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
//    currentPlotView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
//    voltagePlotView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));

    saveOscButton = new QPushButton(tr("Save oscillograms"), this);
    connect(saveOscButton, SIGNAL(clicked()), this, SLOT(saveOscillograms()));

    graphLayout->addWidget(voltagePhasorView, 0, 0, Qt::AlignLeft);
    graphLayout->addWidget(currentPhasorView, 1, 0, Qt::AlignLeft);
    graphLayout->addWidget(voltagePlotView, 0, 1, 0);
    graphLayout->addWidget(currentPlotView, 1, 1, 0);
    graphLayout->addWidget(saveOscButton, 2, 1);
    graphLayout->setColumnStretch(0, 0);
    graphLayout->setColumnStretch(1, 1);

    this->views.append(currentPhasorView);
    this->views.append(voltagePhasorView);
    this->views.append(currentPlotView);
    this->views.append(voltagePlotView);
}
