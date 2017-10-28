#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainWindows(new Ui::MainWindow)
{
    mainWindows->setupUi(this);

    connect(&m_TcpSocket, &QTcpSocket::connected,       this, &MainWindow::onConnected);
    connect(&m_TcpSocket, &QTcpSocket::disconnected,    this, &MainWindow::onDisconnected);
    connect(&m_TcpSocket, &QTcpSocket::readyRead,       this, &MainWindow::readyRead);

    connect(tcp_timer, SIGNAL(timeout()), this, SLOT(tcp_timeout()));


    mainWindows->comboBox_Server_IP->addItem("192.168.0.5");
    mainWindows->comboBox_Server_IP->addItem("prusabadie.ddns.net");
    mainWindows->comboBox_Server_IP->addItem("192.168.0.150");
    mainWindows->comboBox_Server_IP->addItem("192.168.0.190");
    mainWindows->comboBox_Server_IP->addItem("192.168.0.25");


    mainWindows->comboBox_Server_Port->addItem("51717");
    mainWindows->comboBox_Server_Port->addItem("56250");
    mainWindows->comboBox_Server_Port->addItem("35136");

    Connect_to_Server();

}


MainWindow::~MainWindow()
{
    delete mainWindows;
}




void MainWindow::on_actionAbout_triggered()
{


    dui.setupUi(&dialog);
    // some more stuff to setup dialog
    dui.label_version->setText(_VERSION_);
    dialog.show();

    if (dialog.exec() == QDialog::Accepted)
    {
        // store dialog content somewhere

    }
    qDebug() << "END";
}

void MainWindow::on_actionOptions_triggered()
{

    Ui_Dialog_Server_Options dui;
    QDialog dialog;
    dui.setupUi(&dialog);
    // some more stuff to setup dialog

    dui.spinBox_timeout_unsaved_time->setValue(tcp_timeout_time_ms);
    dui.spinBox_Video_res_h->setValue(webcam_res_h);
    dui.spinBox_Video_res_v->setValue(webcam_res_v);
    dui.spinBox_Video_framerate->setValue(webcam_framerate);

    dialog.show();

    if (dialog.exec() == QDialog::Accepted)
    {
        // store dialog content somewhere

    }

    tcp_timeout_time_ms = dui.spinBox_timeout_unsaved_time->value();
    webcam_res_h = dui.spinBox_Video_res_h->value();
    webcam_res_v = dui.spinBox_Video_res_v->value();
    webcam_framerate = dui.spinBox_Video_framerate->value();

    qDebug() << "END";
}

void MainWindow::tcp_timeout(){
    qDebug() << "Timeout ! Aborted.";

    //mainWindows->Server_MSG->setText("Server not found !");
    mainWindows->statusBar->showMessage("Server not found !",STATUS_BAR_MSG_TIMEOUT);
    m_TcpSocket.disconnectFromHost();
    m_TcpSocket.close();
    m_TcpSocket.abort();
    tcp_timer->stop();

}

void MainWindow::tmp_timeout(){
    qDebug() << "Request temperature !";

    request_to_server_temperature();
    tmp_timer->start(tmp_timeout_time_ms);

}

void MainWindow::on_PushButton_Connect_to_Server_clicked()
{
    Connect_to_Server();
}

void MainWindow::Connect_to_Server()
{
    //mainWindows->Server_MSG->setText("");
    mainWindows->statusBar->showMessage("");
    if(!m_TcpSocket_connected)
    {
        QString server_ip = mainWindows->comboBox_Server_IP->currentText();
        int server_port = mainWindows->comboBox_Server_Port->currentText().toInt();

        {
            if (m_debug)
                qDebug() << "TcpSocket server:" << server_ip << ":" << server_port;

            //mainWindows->Server_MSG->setText("Connection...");
            mainWindows->statusBar->showMessage("Connection...");
            m_TcpSocket.connectToHost(server_ip,server_port);

            tcp_timer->start(tcp_timeout_time_ms);

        }
    }
    else
    {
        m_TcpSocket.write("exit");
        m_TcpSocket.close();
    }
}


//! [onConnected]
void MainWindow::onConnected()
{
    tcp_timer->stop();
    mainWindows->PushButton_Connect_to_Server->setText("Disconnect");
    //    mainWindows->statusBar->showMessage("Disconnect");
    m_TcpSocket_connected = true;

    if (m_debug)
        qDebug() << "TcpSocket connected";

    //TEMPERATURE TIMER

    connect(tmp_timer, SIGNAL(timeout()), this, SLOT(tmp_timeout()));
    tmp_timer->start();

    //ENABLE BUTTONS

    mainWindows->Prusa_ON->setEnabled(true);
    mainWindows->Prusa_OFF->setEnabled(true);
    mainWindows->Server_Stop->setEnabled(true);
    mainWindows->Server_ReStart->setEnabled(true);
    mainWindows->Web_WebCam_Restart->setEnabled(true);
    mainWindows->Web_WebCam_Stop->setEnabled(true);
}
//! [onConnected]


//! [onDisconnected]
void MainWindow::onDisconnected()
{
    mainWindows->PushButton_Connect_to_Server->setText("Connection");
    //mainWindows->statusBar->showMessage("Connection");
    m_TcpSocket_connected = false;

    if (m_debug)
        qDebug() << "TcpSocket Disconnected";

    //TEMPERATURE TIMER

    tmp_timer->stop();

    //DISABLE BUTTONS

    mainWindows->Prusa_ON->setEnabled(false);
    mainWindows->Prusa_OFF->setEnabled(false);
    mainWindows->Server_Stop->setEnabled(false);
    mainWindows->Server_ReStart->setEnabled(false);
    mainWindows->Web_WebCam_Restart->setEnabled(false);
    mainWindows->Web_WebCam_Stop->setEnabled(false);
    //mainWindows->Server_MSG->setText("");
    mainWindows->statusBar->showMessage("");
}
//! [onDisconnected]


//! [onTextMessageReceived]
void MainWindow::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received:" << message;
    //m_TcpSocket.close();
}
//! [onTextMessageReceived]


void MainWindow::readyRead()
{

    //mainWindows->Server_MSG->setText(m_TcpSocket.readAll());

    QString server_msg = tr(m_TcpSocket.readAll());


    if(server_msg.startsWith("M100:"))
    {
            server_msg.remove(0,5);
            //server_msg.remove(QRegExp("[\\n\\t\\r]"));
            mainWindows->Server_tmp->setText(server_msg + " °C");
    }
    else
    {
        mainWindows->statusBar->showMessage(server_msg);
    }



}

void MainWindow::on_Prusa_ON_clicked()
{
    m_TcpSocket.write("M1");
}

void MainWindow::on_Prusa_OFF_clicked()
{
    m_TcpSocket.write("M2");
}

void MainWindow::on_Server_Stop_clicked()
{
    m_TcpSocket.write("M9");
}


void MainWindow::on_Server_ReStart_clicked()
{
    m_TcpSocket.write("M10");
}

void MainWindow::request_to_server_temperature()
{
    m_TcpSocket.write("M100");
}



void MainWindow::on_Web_WebCam_Stop_clicked()
{
    m_TcpSocket.write("M200");
}

void MainWindow::on_Web_WebCam_Restart_clicked()
{
    QString command = "M201:" + QString::number(webcam_res_h) + ":" + QString::number(webcam_res_v) + ":" + QString::number(webcam_framerate);
    m_TcpSocket.write(command.toStdString().c_str());

    qDebug() << "command.toStdString().c_str() : " << command.toStdString().c_str();
}

void MainWindow::web_Open_Server_View()
{
    QString server_ip = mainWindows->comboBox_Server_IP->currentText();
    QString web_server_url = "http://" + server_ip + ":" + WEB_SERVER_PORT;

    if (m_debug)
        qDebug() << "web_server_url" << web_server_url;

    QDesktopServices::openUrl(QUrl(web_server_url, QUrl::TolerantMode));
}

void MainWindow::web_Open_WebCam_View()
{
    QString server_ip = mainWindows->comboBox_Server_IP->currentText();
    QString web_server_url = "http://" + server_ip + ":" + WEB_WEBCAM_PORT + "/stream";

    if (m_debug)
        qDebug() << "web_server_url" << web_server_url;

    QDesktopServices::openUrl(QUrl(web_server_url, QUrl::TolerantMode));
}

void MainWindow::on_Server_Web_Open_clicked()
{
    web_Open_Server_View();
}

void MainWindow::on_Web_WebCam_View_clicked()
{
    web_Open_WebCam_View();
}


void MainWindow::on_Server_Rep_Host_clicked()
{
    //TODO : Clean code :

    QDir repetier_dir_full("C:/Program Files/Repetier-Host");
    QString file = repetier_dir_full.absolutePath() + "/RepetierHost.exe";

    QProcess *process = new QProcess(this);

    if (m_debug)
        qDebug() << "repetier path" << file;

    process->startDetached(file, QStringList() << "");
}






