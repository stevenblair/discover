#ifndef FREQUENCYTAB_H
#define FREQUENCYTAB_H

//#include <QWidget>
#include "tabviewwidget.h"

class FrequencyTab : public TabViewWidget
{
    Q_OBJECT
public:
    explicit FrequencyTab(QWidget *parent = 0);
    void update();
    void removeView();

signals:

public slots:

private:
    QList<QGraphicsView*> views;
};

#endif // FREQUENCYTAB_H
