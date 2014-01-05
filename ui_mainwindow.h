/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 5. Jan 15:18:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QPushButton *buttonCalculate;
    QWidget *tab_2;
    QGraphicsView *graphicsView;
    QPushButton *buttonSave;
    QWidget *tab_3;
    QTextEdit *textEditSms;
    QPushButton *buttonBrowse;
    QLineEdit *lineEditSms;
    QLabel *label;
    QTextBrowser *textBrowserSms;
    QPushButton *buttonSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(665, 478);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 641, 421));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 461, 381));
        buttonCalculate = new QPushButton(tab);
        buttonCalculate->setObjectName(QString::fromUtf8("buttonCalculate"));
        buttonCalculate->setGeometry(QRect(550, 10, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(9, 9, 611, 351));
        buttonSave = new QPushButton(tab_2);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        buttonSave->setGeometry(QRect(10, 370, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        textEditSms = new QTextEdit(tab_3);
        textEditSms->setObjectName(QString::fromUtf8("textEditSms"));
        textEditSms->setGeometry(QRect(10, 210, 231, 41));
        buttonBrowse = new QPushButton(tab_3);
        buttonBrowse->setObjectName(QString::fromUtf8("buttonBrowse"));
        buttonBrowse->setGeometry(QRect(170, 30, 75, 23));
        lineEditSms = new QLineEdit(tab_3);
        lineEditSms->setObjectName(QString::fromUtf8("lineEditSms"));
        lineEditSms->setGeometry(QRect(10, 30, 151, 20));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 16));
        textBrowserSms = new QTextBrowser(tab_3);
        textBrowserSms->setObjectName(QString::fromUtf8("textBrowserSms"));
        textBrowserSms->setGeometry(QRect(10, 70, 231, 131));
        buttonSend = new QPushButton(tab_3);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setGeometry(QRect(10, 260, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        buttonSend->setFont(font);
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "height", 0, QApplication::UnicodeUTF8));
        buttonCalculate->setText(QApplication::translate("MainWindow", "Calculate", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Paramters", 0, QApplication::UnicodeUTF8));
        buttonSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        buttonBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Config file path", 0, QApplication::UnicodeUTF8));
        buttonSend->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "SMS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
