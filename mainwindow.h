#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include "cgetdata.h"
#include "csendsms.h"
#include "cconfig.h"

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
    void on_buttonSend_clicked();

    void on_buttonBrowse_clicked();

private:
    CGetData *data;
    Ui::MainWindow *ui;
    QString confPath;
    QList<QString> listConf;
    void dataToTable();
    void getGraph();

};

#endif // MAINWINDOW_H
