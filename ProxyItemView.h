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

#ifndef PHASORPLOTVIEW_H
#define PHASORPLOTVIEW_H

#include <QAbstractItemView>
#include "TabViewWidget.h"

/**
  * This class provides the view functionality for tabs containing custom QGraphicsView/QGraphicsScene widgets,
  * to ensure that they remain consistent with the model. Each QGraphicsScene object is a "slave" of an instance
  * of this class.
  *
  * A new instance must be created for each tab. The TabViewWidget object which is "watched" must implement the
  * appropriate functions to interface with this class.
  *
  * Instances of this class should NOT be added to the UI.
  */
class ProxyItemView : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit ProxyItemView(TabViewWidget *widget, QAbstractItemModel *model, QWidget *parent = 0);

    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
    QModelIndex indexAt(const QPoint &point) const;

    virtual void setModel(QAbstractItemModel *model);

public slots:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void rowsInserted(const QModelIndex &parent, int start, int end);
    void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end);

protected:

    bool edit(const QModelIndex &index, EditTrigger trigger, QEvent *event);
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers);

    int horizontalOffset() const;
    int verticalOffset() const;

    bool isIndexHidden(const QModelIndex &index) const;

    void setSelection(const QRect&, QItemSelectionModel::SelectionFlags command);
    //void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void scrollContentsBy(int dx, int dy);

    QRegion visualRegionForSelection(const QItemSelection &selection) const;

private:
    TabViewWidget *widget;

};

#endif // PHASORPLOTVIEW_H
