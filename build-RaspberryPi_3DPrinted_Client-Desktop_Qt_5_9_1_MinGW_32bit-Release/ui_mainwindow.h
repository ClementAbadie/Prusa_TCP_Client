/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOptions;
    QAction *actionAbout;
    QWidget *centralWidget;
    QComboBox *comboBox_Server_IP;
    QPushButton *PushButton_Connect_to_Server;
    QComboBox *comboBox_Server_Port;
    QLabel *Server_IP_PORT_separator;
    QLabel *server_label;
    QLabel *prusa_label;
    QPushButton *Server_Stop;
    QPushButton *Prusa_OFF;
    QPushButton *Prusa_ON;
    QLabel *Server_MSG;
    QPushButton *Server_ReStart;
    QPushButton *Server_Web_Open;
    QPushButton *Server_Rep_Host;
    QMenuBar *menuBar;
    QMenu *Options;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setMaximumSize(QSize(400, 300));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox_Server_IP = new QComboBox(centralWidget);
        comboBox_Server_IP->setObjectName(QStringLiteral("comboBox_Server_IP"));
        comboBox_Server_IP->setGeometry(QRect(40, 10, 131, 22));
        comboBox_Server_IP->setEditable(true);
        PushButton_Connect_to_Server = new QPushButton(centralWidget);
        PushButton_Connect_to_Server->setObjectName(QStringLiteral("PushButton_Connect_to_Server"));
        PushButton_Connect_to_Server->setGeometry(QRect(250, 10, 75, 23));
        PushButton_Connect_to_Server->setCheckable(false);
        PushButton_Connect_to_Server->setChecked(false);
        PushButton_Connect_to_Server->setAutoDefault(true);
        PushButton_Connect_to_Server->setFlat(false);
        comboBox_Server_Port = new QComboBox(centralWidget);
        comboBox_Server_Port->setObjectName(QStringLiteral("comboBox_Server_Port"));
        comboBox_Server_Port->setGeometry(QRect(180, 10, 61, 22));
        comboBox_Server_Port->setEditable(true);
        Server_IP_PORT_separator = new QLabel(centralWidget);
        Server_IP_PORT_separator->setObjectName(QStringLiteral("Server_IP_PORT_separator"));
        Server_IP_PORT_separator->setGeometry(QRect(170, 10, 16, 21));
        server_label = new QLabel(centralWidget);
        server_label->setObjectName(QStringLiteral("server_label"));
        server_label->setGeometry(QRect(70, 90, 71, 31));
        server_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        prusa_label = new QLabel(centralWidget);
        prusa_label->setObjectName(QStringLiteral("prusa_label"));
        prusa_label->setGeometry(QRect(70, 50, 71, 31));
        prusa_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Server_Stop = new QPushButton(centralWidget);
        Server_Stop->setObjectName(QStringLiteral("Server_Stop"));
        Server_Stop->setEnabled(false);
        Server_Stop->setGeometry(QRect(240, 90, 81, 31));
        Prusa_OFF = new QPushButton(centralWidget);
        Prusa_OFF->setObjectName(QStringLiteral("Prusa_OFF"));
        Prusa_OFF->setEnabled(false);
        Prusa_OFF->setGeometry(QRect(240, 50, 81, 31));
        Prusa_ON = new QPushButton(centralWidget);
        Prusa_ON->setObjectName(QStringLiteral("Prusa_ON"));
        Prusa_ON->setEnabled(false);
        Prusa_ON->setGeometry(QRect(150, 50, 81, 31));
        Server_MSG = new QLabel(centralWidget);
        Server_MSG->setObjectName(QStringLiteral("Server_MSG"));
        Server_MSG->setGeometry(QRect(10, 230, 381, 21));
        Server_ReStart = new QPushButton(centralWidget);
        Server_ReStart->setObjectName(QStringLiteral("Server_ReStart"));
        Server_ReStart->setEnabled(false);
        Server_ReStart->setGeometry(QRect(150, 90, 81, 31));
        Server_Web_Open = new QPushButton(centralWidget);
        Server_Web_Open->setObjectName(QStringLiteral("Server_Web_Open"));
        Server_Web_Open->setEnabled(true);
        Server_Web_Open->setGeometry(QRect(150, 130, 171, 31));
        Server_Rep_Host = new QPushButton(centralWidget);
        Server_Rep_Host->setObjectName(QStringLiteral("Server_Rep_Host"));
        Server_Rep_Host->setEnabled(true);
        Server_Rep_Host->setGeometry(QRect(150, 170, 171, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        Options = new QMenu(menuBar);
        Options->setObjectName(QStringLiteral("Options"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(Options->menuAction());
        menuBar->addAction(menuAide->menuAction());
        Options->addAction(actionOptions);
        menuAide->addAction(actionAbout);

        retranslateUi(MainWindow);

        PushButton_Connect_to_Server->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Raspberry Pi - 3D Printer - Client", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", Q_NULLPTR));
        comboBox_Server_IP->setCurrentText(QApplication::translate("MainWindow", "prusabadie.ddns.net", Q_NULLPTR));
        PushButton_Connect_to_Server->setText(QApplication::translate("MainWindow", "Connection", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        PushButton_Connect_to_Server->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        comboBox_Server_Port->setCurrentText(QApplication::translate("MainWindow", "51717", Q_NULLPTR));
        Server_IP_PORT_separator->setText(QApplication::translate("MainWindow", " :", Q_NULLPTR));
        server_label->setText(QApplication::translate("MainWindow", "Server :", Q_NULLPTR));
        prusa_label->setText(QApplication::translate("MainWindow", "3D Printer :", Q_NULLPTR));
        Server_Stop->setText(QApplication::translate("MainWindow", "SHUT DOWN", Q_NULLPTR));
        Prusa_OFF->setText(QApplication::translate("MainWindow", "Turn OFF", Q_NULLPTR));
        Prusa_ON->setText(QApplication::translate("MainWindow", "Turn ON", Q_NULLPTR));
        Server_MSG->setText(QString());
        Server_ReStart->setText(QApplication::translate("MainWindow", "RESTART", Q_NULLPTR));
        Server_Web_Open->setText(QApplication::translate("MainWindow", "Open Web Server", Q_NULLPTR));
        Server_Rep_Host->setText(QApplication::translate("MainWindow", "Open Repetier Host", Q_NULLPTR));
        Options->setTitle(QApplication::translate("MainWindow", "Server", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
