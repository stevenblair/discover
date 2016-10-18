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

#ifndef PHASORPLOTTAB_H
#define PHASORPLOTTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include "TabViewWidget.h"
#include "PhasorScene.h"
#include "PhasorView.h"
#include "PlotScene.h"
#include "PlotView.h"
#include <QPushButton>

class PhasorPlotTab : public TabViewWidget
{
    Q_OBJECT
public:
    explicit PhasorPlotTab(QWidget *parent = 0);
    void update();
    void removeView();
    
signals:
    
public slots:

private slots:
    void saveOscillograms();

private:
    QList<QGraphicsView*> views;

    CurrentPhasorScene *currentPhasorScene;
    VoltagePhasorScene *voltagePhasorScene;
    CurrentPlotScene *currentPlotScene;
    VoltagePlotScene *voltagePlotScene;
    PhasorView *currentPhasorView;
    PhasorView *voltagePhasorView;
    PlotView *currentPlotView;
    PlotView *voltagePlotView;

    QPushButton * saveOscButton;
};

#endif // PHASORPLOTTAB_H
