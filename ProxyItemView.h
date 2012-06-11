#ifndef PHASORPLOTVIEW_H
#define PHASORPLOTVIEW_H

#include <QAbstractItemView>
#include "tabviewwidget.h"

class ProxyItemView : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit ProxyItemView(TabViewWidget *widget, QWidget *parent = 0);

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
