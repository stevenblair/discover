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

#ifndef POWERTAB_H
#define POWERTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include "TabviewWidget.h"
#include "PowerTreeModel.h"

class PowerTab : public TabViewWidget
{
    Q_OBJECT
public:
    explicit PowerTab(QWidget *parent = 0);
    void update();
    void removeView();

signals:

public slots:

private:
    PowerTreeModel *treeModel;
    QTableView *tableView;

};

#endif // POWERTAB_H
