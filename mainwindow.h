#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsView>
#include "streamtablemodel.h"
#include "phasor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    StreamTableModel *getStreamTableModel();
    QTableView *getStreamTableView();

public slots:
    void addInterface(int value, QString name);

private:
    QLabel *networkInterfaceLabel;
    QComboBox *interfaceComboBox;

    StreamTableModel *tableModel;
    QTableView *tableView;

    QGraphicsScene *currentPhasorScene;
    QGraphicsScene *voltagePhasorScene;
    QGraphicsView *currentPhasorView;
    QGraphicsView *voltagePhasorView;
};

#endif // MAINWINDOW_H
