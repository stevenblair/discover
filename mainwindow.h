#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
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
    QComboBox *interfaceComboBox;
    QLabel *networkInterfaceLabel;
};

#endif // MAINWINDOW_H
