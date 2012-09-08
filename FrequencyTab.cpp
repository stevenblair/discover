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

#include "FrequencyTab.h"


const QString FrequencyTab::checkBoxLabels[8] = {QString("Va"), QString("Vb"), QString("Vc"), QString("Vn"), QString("Ia"), QString("Ib"), QString("Ic"), QString("In")};

FrequencyTab::FrequencyTab(QWidget *parent) : TabViewWidget(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QHBoxLayout *checkBoxLayout = new QHBoxLayout();

    frequencyScene = new FrequencyScene();
    frequencyView = new QGraphicsView();
    frequencyView->setScene(frequencyScene);

    frequencyView->setRenderHint(QPainter::Antialiasing);    // TODO: move into subclass?


    checkBoxMapper = new QSignalMapper(this);

    for (int i = 0; i < 8; i++) {
        activeWaveformCheckBox[i] = new QCheckBox(checkBoxLabels[i]);
        QFont font("", 9, QFont::Bold);
        activeWaveformCheckBox[i]->setFont(font);
        QPalette palette;
        palette.setColor(QPalette::WindowText, FrequencyScene::waveformColors[i]);
        activeWaveformCheckBox[i]->setPalette(palette);
        activeWaveformCheckBox[i]->setChecked(frequencyScene->getWaveformState(i));
        connect(activeWaveformCheckBox[i], SIGNAL(toggled(bool)), checkBoxMapper, SLOT(map()));
        checkBoxMapper->setMapping(activeWaveformCheckBox[i], i);
        checkBoxLayout->addWidget(activeWaveformCheckBox[i]);
    }

    connect(checkBoxMapper, SIGNAL(mapped(int)), this, SIGNAL(checkBoxToggled(int)));
    connect(this, SIGNAL(checkBoxToggled(int)), this, SLOT(setActiveWavefrom(int)));


    verticalLayout->addLayout(checkBoxLayout);
    verticalLayout->addWidget(frequencyView, 0, 0);

    this->views.append(frequencyView);

    connect(this, SIGNAL(redrawFrequencyScene()), this->frequencyScene, SLOT(redrawFrequencyScene()));
}

void FrequencyTab::update()
{
    frequencyScene->streamTableModelSelectionChanged(this->model, &this->index);
}

void FrequencyTab::removeView()
{
    frequencyScene->streamRemoved();
}

void FrequencyTab::setActiveWavefrom(int id)
{
    if (id >= 0 && id < 8) {
        //qDebug() << id << activeWaveformCheckBox[id]->isChecked();
        frequencyScene->setWaveformState(id, activeWaveformCheckBox[id]->isChecked());
        emit redrawFrequencyScene();
    }
}
