#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QDir>

#include "ui_mainwindow.h"
#include "ui_authorinfos.h"
#include "ui_server_options.h"


#define _VERSION_ "1.4"

#define WEB_SERVER_PORT "3344"

#define WEB_WEBCAM_PORT "9090"

#define STATUS_BAR_MSG_TIMEOUT 3000

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
    void tcp_timeout();
    void tmp_timeout();

    void on_Prusa_ON_clicked();
    void on_Prusa_OFF_clicked();
    void on_Server_Stop_clicked();
    void on_Server_ReStart_clicked();

    void request_to_server_temperature();

    void on_actionOptions_triggered();

    void web_Open_WebCam_View();
    void web_Open_Server_View();

    void on_Server_Web_Open_clicked();
    void on_Server_Rep_Host_clicked();
    void on_Web_WebCam_View_clicked();

    void on_Web_WebCam_Restart_clicked();

    void on_Web_WebCam_Stop_clicked();

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

    QTimer *tmp_timer = new QTimer(this);
    int tmp_timeout_time_ms = 10000;

    int webcam_res_h = 1600;
    int webcam_res_v = 900;
    int webcam_framerate = 20;

    void Connect_to_Server();
};

#endif // MAINWINDOW_H
