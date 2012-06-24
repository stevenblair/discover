#ifndef POWERTAB_H
#define POWERTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include "tabviewwidget.h"
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
