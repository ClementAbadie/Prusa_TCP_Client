#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QTimer>


#include "ui_mainwindow.h"
#include "ui_authorinfos.h"
#include "ui_server_options.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

Q_SIGNALS:
    void closed();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PushButton_Connect_to_Server_clicked();
    void on_actionAbout_triggered();

    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(QString message);
    void readyRead();


    void on_Prusa_ON_clicked();

    void on_Server_Stop_clicked();

    void on_Prusa_OFF_clicked();

    void on_Server_ReStart_clicked();

    void tcp_timeout();


    void on_actionOptions_triggered();



private:
    Ui::MainWindow *mainWindows;


    Ui_Dialog_Server_Options *dui_Options;
    QDialog dialog_Options;

    Ui_Dialog_About dui;
    QDialog dialog;

    QTcpSocket m_TcpSocket;
    bool m_TcpSocket_connected = false;
    bool m_debug = true;

    QTimer *tcp_timer = new QTimer(this);

    int tcp_timeout_time_ms = 1000;

    void Connect_to_Server();
};

#endif // MAINWINDOW_H
