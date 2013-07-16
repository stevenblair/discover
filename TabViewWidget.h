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

#ifndef TABVIEWWIDGET_H
#define TABVIEWWIDGET_H

#include <QWidget>
#include <QList>
#include <QGraphicsView>
#include <QModelIndex>
#include "StreamTableRow.h"
#include "StreamTableModel.h"


/**
  * A generic tab container widget for a single tab.
  *
  * Subclasses define the actual components to display in the tab, and must implement the update() function
  * to refresh the view, using the pointer to the StreamTableModel and the QPersistentModelIndex.
  */
class TabViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabViewWidget(QWidget *parent = 0);

    virtual void setSelectedRowIndex(QModelIndex &index);
    void setModel(StreamTableModel *model);
    QPersistentModelIndex *getIndex() {
        return &this->index;
    }
    virtual void update() = 0;
    virtual void removeView() = 0;

signals:
    
public slots:
    //void setRow(StreamTableRow *row);

protected:

    StreamTableModel *model;
    QPersistentModelIndex index;

private:

};

#endif // TABVIEWWIDGET_H
