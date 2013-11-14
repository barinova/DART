#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = new CGetData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getData(QNetworkReply *reply)
{
    data->data.clear();
    data->getInfoFromURL(reply);
    dataToTable();
    getGraph();
}


void MainWindow::dataToTable()
{
    ui->tableWidget->clearContents();
    for(int i(0); i < data->data.size(); i++)
    {
        resultData param = data->data.at(i);
        if(i > ui->tableWidget->rowCount() - 1)
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(param.time.toString())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(param.HEIGHT)));
    }
}

void MainWindow::on_buttonCalculate_clicked()
{
    data->networkConnection(this);
}

void MainWindow::getGraph()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    resultData first, second, begin;
    QPen pen, axis;
    float minHeight(0);
    ui->graphicsView->setScene(scene);
    pen.setColor(Qt::red);
    pen.setWidth(2);
    axis.setColor(Qt::gray);
    axis.setWidth(1);
    begin = data->data.at(0);
    for(int i(0); i < data->data.size() - 1; i++)
    {
        first = data->data.at(i);
        second = data->data.at(i+1);
        scene->addLine( i, - (first.HEIGHT - begin.HEIGHT) * 100, (i + 1), - (second.HEIGHT - begin.HEIGHT) * 100, pen);
        if(minHeight > first.HEIGHT - begin.HEIGHT)
            minHeight = first.HEIGHT - begin.HEIGHT;
        if(first.HEIGHT > second.HEIGHT - begin.HEIGHT)
            minHeight = second.HEIGHT - begin.HEIGHT;
    }
    for(int i(0); i < data->data.size() - 1; i+=10)
    {
        scene->addLine( i,  - minHeight * 600 - 4, i,  - minHeight * 600 + 4, axis);
    }
    scene->addLine(0,  - minHeight * 600, scene->width(),  - minHeight * 600, axis);
}
