#ifndef TABVIEWWIDGET_H
#define TABVIEWWIDGET_H

#include <QWidget>
#include <QList>
#include <QGraphicsView>
#include <QModelIndex>
#include "streamtablerow.h"
#include "streamtablemodel.h"


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
