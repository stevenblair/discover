#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include "streamtablemodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    StreamTableModel *tableModel;
    QTableView *tableView;
};

#endif // MAINWINDOW_H
