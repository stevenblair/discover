#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGraphicsView>
#include <QTableWidget>
#include "ProxyItemView.h"
#include "streamtablemodel.h"
#include "commsthread.h"
#include "PhasorPlotTab.h"

extern CommsThread commsThread;

#define TABLE_VIEW_MINIMUM_HEIGHT   150

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
    ProxyItemView *phasorPlotView;

    QTabWidget *tabWidget;
    PhasorPlotTab *phasorPlotWidget;
    /*

    CurrentPhasorScene *currentPhasorScene;
    VoltagePhasorScene *voltagePhasorScene;
    CurrentPlotScene *currentPlotScene;
    VoltagePlotScene *voltagePlotScene;
    PhasorView *currentPhasorView;
    PhasorView *voltagePhasorView;
    PlotView *currentPlotView;
    PlotView *voltagePlotView;*/
};

#endif // MAINWINDOW_H
