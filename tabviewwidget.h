#ifndef TABVIEWWIDGET_H
#define TABVIEWWIDGET_H

#include <QWidget>
#include <QList>
#include <QGraphicsView>
#include "streamtablerow.h"

class TabViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabViewWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void setRow(StreamTableRow *row);
    
private:
    QList<QGraphicsView> views;
};

#endif // TABVIEWWIDGET_H
