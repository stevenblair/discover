#ifndef TABVIEWWIDGET_H
#define TABVIEWWIDGET_H

#include <QWidget>
#include <QList>
#include <QGraphicsView>
#include <QModelIndex>
#include "streamtablerow.h"

class TabViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabViewWidget(QWidget *parent = 0);

    void setSelectedRowIndex(QModelIndex &index);
    
signals:
    
public slots:
    void setRow(StreamTableRow *row);

protected:
    QList<QGraphicsView*> views;
    QPersistentModelIndex index;

private:

};

#endif // TABVIEWWIDGET_H
