#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(""));
    data = new CGetData();
    CConfig *conf = new CConfig();
    listConf = conf->getConfig("./Config.conf");
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
    resultData param = data->data.at(0);
    QString prev, curr;

    curr = QString(param.time.toString());
    if(!ui->tableWidget->item(0,0)->text().isEmpty())
    {
        prev = ui->tableWidget->item(0,0)->text();
    }

    if(QString::compare(prev, curr) || prev.isEmpty())
    {
        on_buttonSend_clicked();
    }
    ui->tableWidget->clearContents();
    for(int i(0); i < data->data.size(); i++)
    {
        param = data->data.at(i);
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
    scene = new QGraphicsScene(this);
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
    }
    for(int i(0); i < data->data.size() - 1; i+=10)
    {
        scene->addLine( i,   - 4, i,   + 4, axis);
    }
    scene->addLine(0,  0, scene->width(), 0, axis);
}

void MainWindow::on_buttonSend_clicked()
{
    CSendSms *sms = new CSendSms();

    QString sendingString = this->ui->textEditSms->toPlainText();

    if(!listConf.isEmpty())
    {
        if(sendingString.isEmpty())
        {
            sendingString = "DARTs data was updated";
        }
        int errorCode = sms->sendSms(listConf.at(1), sendingString, listConf.at(0));
        ui->textBrowserSms->append("Sending...");
        if(errorCode == 100)
        {
            ui->textBrowserSms->append("Successfully");
        }
        else
        {
            ui->textBrowserSms->append("Error");
        }
        this->ui->textEditSms->clear();
    }
}

void MainWindow::on_buttonBrowse_clicked()
{
    confPath = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("CONF Files (*.conf)"));
    if(!confPath.isEmpty())
    {
        ui->lineEditSms->setText(confPath);
        CConfig *conf = new CConfig();
        listConf = conf->getConfig(confPath);
    }
}

void MainWindow::on_buttonSave_clicked()
{
    CImgToPdf *pdfFile = new CImgToPdf(this->scene);
}
