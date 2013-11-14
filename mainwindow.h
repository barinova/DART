#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cgetdata.h"
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_buttonCalculate_clicked();
    void getData(QNetworkReply *reply);
private:
    CGetData *data;
    Ui::MainWindow *ui;
    void dataToTable();
    void getGraph();

};

#endif // MAINWINDOW_H
