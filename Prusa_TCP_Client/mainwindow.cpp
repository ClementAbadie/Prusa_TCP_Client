#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainWindows(new Ui::MainWindow)
{
    mainWindows->setupUi(this);

    dui_Options.setupUi(&dialog_Options);

    connect(m_TcpSocket, &QTcpSocket::connected,                this, &MainWindow::onConnected);
    connect(m_TcpSocket, &QTcpSocket::disconnected,             this, &MainWindow::onDisconnected);
    connect(m_TcpSocket, &QTcpSocket::readyRead,                this, &MainWindow::readyRead);

    connect(m_TcpSocket_distant, &QTcpSocket::connected,        this, &MainWindow::onConnected_distant);
    connect(m_TcpSocket_distant, &QTcpSocket::disconnected,     this, &MainWindow::onDisconnected_distant);
    connect(m_TcpSocket_distant, &QTcpSocket::readyRead,        this, &MainWindow::readyRead);

    connect(m_TcpSocket_local, &QTcpSocket::connected,          this, &MainWindow::onConnected_local);
    connect(m_TcpSocket_local, &QTcpSocket::disconnected,       this, &MainWindow::onDisconnected_local);
    connect(m_TcpSocket_local, &QTcpSocket::readyRead,          this, &MainWindow::readyRead);

    connect(tcp_timer, SIGNAL(timeout()), this, SLOT(tcp_timeout()));
    connect(tmp_timer, SIGNAL(timeout()), this, SLOT(tmp_timeout()));

    dui_Options.comboBox_Server_IP_Local->addItem("192.168.0.5");
    dui_Options.comboBox_Server_IP_Local->addItem("192.168.0.150");
    dui_Options.comboBox_Server_IP_Local->addItem("192.168.0.190");
    dui_Options.comboBox_Server_IP_Local->addItem("192.168.0.25");


    dui_Options.comboBox_Server_Port->addItem("51717");
    dui_Options.comboBox_Server_Port->addItem("56250");
    dui_Options.comboBox_Server_Port->addItem("35136");


    MainWindow::initSettings();

    Connect_to_Servers();





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


    // some more stuff to setup dialog

    dialog_Options.show();

    if (dialog_Options.exec() == QDialog::Accepted)
    {
        // store dialog content somewhere

    }

    mainWindows->Web_WebCam_Restart->setEnabled(dui_Options.radioButton_webcam_pi->isChecked());
    mainWindows->Web_WebCam_Stop->setEnabled(dui_Options.radioButton_webcam_pi->isChecked());

    qDebug() << "END";
}

void MainWindow::tcp_timeout(){
    qDebug() << "Timeout ! Aborted.";

    //mainWindows->Server_MSG->setText("Server not found !");
    mainWindows->statusBar->showMessage("Server not found !",STATUS_BAR_MSG_TIMEOUT);

    if(!m_TcpSocket_connected_distant){
        m_TcpSocket_distant->disconnectFromHost();
        m_TcpSocket_distant->close();
        m_TcpSocket_distant->abort();
    }
    if(!m_TcpSocket_connected_local){
        m_TcpSocket_local->disconnectFromHost();
        m_TcpSocket_local->close();
        m_TcpSocket_local->abort();
    }

    tcp_timer->stop();

}

void MainWindow::tmp_timeout(){
    qDebug() << "Request temperature !";

    request_to_server_temperature();
    tmp_timer->start(tmp_timeout_time_ms_default);

}

void MainWindow::on_PushButton_Connect_to_Server_clicked()
{
    Connect_to_Servers();
}



bool MainWindow::Connect_to_Servers()
{
    //mainWindows->Server_MSG->setText("");
    mainWindows->statusBar->showMessage("");


    if(!m_TcpSocket_connected){
        int server_port = dui_Options.comboBox_Server_Port->currentText().toInt();
        QString server_ip_distant = dui_Options.comboBox_Server_IP_Distant->currentText();
        QString server_ip_local = dui_Options.comboBox_Server_IP_Local->currentText();
        {
            if (m_debug)
                qDebug() << "TcpSocket server distant :" << server_ip_distant << ":" << server_port;
            qDebug() << "TcpSocket server local :" << server_ip_local << ":" << server_port;

            //mainWindows->Server_MSG->setText("Connection...");
            mainWindows->statusBar->showMessage("Connection...");
            m_TcpSocket_distant->connectToHost(server_ip_distant,server_port);
            m_TcpSocket_local->connectToHost(server_ip_local,server_port);
            tcp_timer->start(dui_Options.spinBox_timeout_unsaved_time->value());
        }

        return true;

    }
    else
    {
        m_TcpSocket->write("exit");
        m_TcpSocket->close();

        m_TcpSocket_distant->disconnectFromHost();
        m_TcpSocket_distant->close();
        m_TcpSocket_distant->abort();

        m_TcpSocket_local->disconnectFromHost();
        m_TcpSocket_local->close();
        m_TcpSocket_local->abort();
        return false;
    }

}

bool MainWindow::Connect_to_Server()
{
    //mainWindows->Server_MSG->setText("");
    mainWindows->statusBar->showMessage("");
    //    qDebug() << "TcpSocket server :" << server_ip << ":" << server_port;
    if(!m_TcpSocket_connected)
    {
        QString server_ip = dui_Options.comboBox_Server_IP_Distant->currentText();
        int server_port = dui_Options.comboBox_Server_Port->currentText().toInt();

        {
            if (m_debug)
                qDebug() << "TcpSocket server :" << server_ip << ":" << server_port;

            //mainWindows->Server_MSG->setText("Connection...");
            mainWindows->statusBar->showMessage("Connection...");
            m_TcpSocket->connectToHost(server_ip,server_port);

            tcp_timer->start(dui_Options.spinBox_timeout_unsaved_time->value());

        }

        return true;
    }
    else
    {
        qDebug() << "TcpSocket close.";
        m_TcpSocket->write("exit");
        m_TcpSocket->close();
        return false;
    }

}

void MainWindow::onConnected_distant()
{
    m_TcpSocket_connected_distant = true;
    tcp_timer->stop();

    if (m_debug)
        qDebug() << "TcpSocket_distant connected";

//    mainWindows->statusBar->showMessage("Connected ! (Distant)");
        mainWindows->PushButton_Connect_to_Server->setText("Disconnect (Distant)");
    m_TcpSocket = m_TcpSocket_distant;
    MainWindow::onConnected();
}

void MainWindow::onConnected_local()
{
    m_TcpSocket_connected_local = true;
    tcp_timer->stop();

    if (m_debug)
        qDebug() << "TcpSocket_local connected";
//    mainWindows->statusBar->showMessage("Connected ! (Local)");
        mainWindows->PushButton_Connect_to_Server->setText("Disconnect (Local)");
    m_TcpSocket = m_TcpSocket_local;
    MainWindow::onConnected();
}

//! [onConnected]
void MainWindow::onConnected()
{
    tcp_timer->stop();
//    mainWindows->PushButton_Connect_to_Server->setText("Disconnect");
    m_TcpSocket_connected = true;


    //TEMPERATURE TIMER
    request_to_server_temperature();
    tmp_timer->start();

    //ENABLE BUTTONS

    mainWindows->Prusa_ON->setEnabled(true);
    mainWindows->Prusa_OFF->setEnabled(true);
    mainWindows->Server_Stop->setEnabled(true);
    mainWindows->Server_ReStart->setEnabled(true);
    mainWindows->Web_WebCam_Restart->setEnabled(dui_Options.radioButton_webcam_pi->isChecked());
    mainWindows->Web_WebCam_Stop->setEnabled(dui_Options.radioButton_webcam_pi->isChecked());
}
//! [onConnected]


void MainWindow::onDisconnected_distant()
{

    m_TcpSocket_connected_distant = false;
    if (m_debug)
        qDebug() << "TcpSocket_distant Disconnected";
    if(!m_TcpSocket_connected_local)MainWindow::onDisconnected();

}

void MainWindow::onDisconnected_local()
{

    m_TcpSocket_connected_local = false;
    if (m_debug)
        qDebug() << "TcpSocket_distant Disconnected";
    if(!m_TcpSocket_connected_distant)MainWindow::onDisconnected();

}

//! [onDisconnected]
void MainWindow::onDisconnected()
{
    mainWindows->PushButton_Connect_to_Server->setText("Connection");
    //mainWindows->statusBar->showMessage("Connection");
    m_TcpSocket_connected = false;

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
    mainWindows->Server_tmp->setText("");
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
    if (m_debug)
        qDebug() << "Ready read !";

    //mainWindows->Server_MSG->setText(m_TcpSocket.readAll());

    QString server_msg = tr(m_TcpSocket->readAll());


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
    m_TcpSocket->write("M1");
}

void MainWindow::on_Prusa_OFF_clicked()
{
    m_TcpSocket->write("M2");
}

void MainWindow::on_Server_Stop_clicked()
{
    m_TcpSocket->write("M9");
}


void MainWindow::on_Server_ReStart_clicked()
{
    m_TcpSocket->write("M10");
}

void MainWindow::request_to_server_temperature()
{
    m_TcpSocket->write("M100");
}



void MainWindow::on_Web_WebCam_Stop_clicked()
{

    if(dui_Options.radioButton_webcam_android->isChecked()){

    }
    else{

        m_TcpSocket->write("M200");
    }

}

void MainWindow::on_Web_WebCam_Restart_clicked()
{

    if(dui_Options.radioButton_webcam_android->isChecked()){

    }
    else{
        QString command = "M201:" + QString::number(dui_Options.spinBox_Video_res_h->value()) + ":" + QString::number(dui_Options.spinBox_Video_res_v->value()) + ":" + QString::number(dui_Options.spinBox_Video_framerate->value());
        m_TcpSocket->write(command.toStdString().c_str());

        qDebug() << "command.toStdString().c_str() : " << command.toStdString().c_str();
    }


}

void MainWindow::web_Open_Server_View()
{
    QString server_ip;
    if(m_TcpSocket_connected_distant) server_ip = dui_Options.comboBox_Server_IP_Distant->currentText();
    if(m_TcpSocket_connected_local) server_ip = dui_Options.comboBox_Server_IP_Local->currentText();
    QString web_server_url = "http://" + server_ip + ":" + WEB_SERVER_PORT;

    if (m_debug)
        qDebug() << "web_server_url" << web_server_url;

    QDesktopServices::openUrl(QUrl(web_server_url, QUrl::TolerantMode));
}

void MainWindow::web_Open_WebCam_View()
{

    QString server_ip;
    QString web_server_url;

    if(m_TcpSocket_connected_distant) server_ip = dui_Options.comboBox_Server_IP_Distant->currentText();
    else server_ip = dui_Options.comboBox_Server_IP_Local->currentText();

    if(dui_Options.radioButton_webcam_android->isChecked()){

        web_server_url = "https://" + server_ip + ":" + QString::number(WEB_WEBCAM_PORT)+ "/flash.html";
    }
    else{
        web_server_url = "http://" + server_ip + ":" + QString::number(WEB_WEBCAM_PORT) + "/stream";
    }

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


void MainWindow::resetSettings()
{

    qDebug() << "Reseting settings...";

    QSettings settings(settings_file_name, QSettings::IniFormat);

//    settings.setValue("client_tcp_timeout_time_ms", tcp_timeout_time_ms_default);
//    settings.setValue("client_tmp_timeout_time_ms", tmp_timeout_time_ms_default);
//    settings.setValue("spinBox_Video_res_h",webcam_res_h_default);
//    settings.setValue("spinBox_Video_res_v",webcam_res_v_default);
//    settings.setValue("spinBox_Video_framerate",webcam_framerate_default);
//    settings.setValue("WEB_SERVER_PORT",WEB_SERVER_PORT);
//    settings.setValue("WEB_WEBCAM_PORT",WEB_WEBCAM_PORT);


    dui_Options.spinBox_timeout_unsaved_time->setValue(tcp_timeout_time_ms_default);
    dui_Options.spinBox_Video_res_h->setValue(webcam_res_h_default);
    dui_Options.spinBox_Video_res_v->setValue(webcam_res_v_default);
    dui_Options.spinBox_Video_framerate->setValue(webcam_framerate_default);

    dui_Options.radioButton_webcam_pi->setChecked(false);
    dui_Options.radioButton_webcam_android->setChecked(true);


    qDebug() << "Settings reseted !";
}

void MainWindow::initSettings()
{
    QCoreApplication::setOrganizationName("ClementABADIE");
    QCoreApplication::setOrganizationDomain("clementabadie.com");
    QCoreApplication::setApplicationName("PrusaClient");

    QSettings settings(settings_file_name, QSettings::IniFormat);


    qDebug() << "QSettings path : " << settings.fileName();

    dui_Options.spinBox_timeout_unsaved_time->setValue(settings.value("client_tcp_timeout_time_ms",tcp_timeout_time_ms_default).toInt());
    //    dui_Options.spinBox_timeout_unsaved_time->setValue(settings.value("client_tmp_timeout_time_ms"),tmp_timeout_time_ms_default);
    dui_Options.spinBox_Video_res_h->setValue(settings.value("spinBox_Video_res_h",webcam_res_h_default).toInt());
    dui_Options.spinBox_Video_res_v->setValue(settings.value("spinBox_Video_res_v",webcam_res_v_default).toInt());
    dui_Options.spinBox_Video_framerate->setValue(settings.value("spinBox_Video_framerate",webcam_framerate_default).toInt());

    dui_Options.radioButton_webcam_pi->setChecked(settings.value("radioButton_webcam_pi").toBool());
    dui_Options.radioButton_webcam_android->setChecked(settings.value("radioButton_webcam_android").toBool());

    dui_Options.comboBox_Server_IP_Distant->setCurrentText(settings.value("comboBox_Server_IP_Distant").toString());
    dui_Options.comboBox_Server_IP_Local->setCurrentText(settings.value("comboBox_Server_IP_Local").toString());

    dui_Options.comboBox_Server_Port->setCurrentText(settings.value("comboBox_Server_Port").toString());


}

void MainWindow::saveSettings()
{

    qDebug() << "Saving settings...";

    QSettings settings(settings_file_name, QSettings::IniFormat);


    settings.setValue("client_tcp_timeout_time_ms", dui_Options.spinBox_timeout_unsaved_time->value());
    //    settings.setValue("client_tmp_timeout_time_ms", tmp_timeout_time_ms_default);
    settings.setValue("spinBox_Video_res_h",dui_Options.spinBox_Video_res_h->value());
    settings.setValue("spinBox_Video_res_v",dui_Options.spinBox_Video_res_v->value());
    settings.setValue("spinBox_Video_framerate",dui_Options.spinBox_Video_framerate->value());
    settings.setValue("radioButton_webcam_pi",dui_Options.radioButton_webcam_pi->isChecked());
    settings.setValue("radioButton_webcam_android",dui_Options.radioButton_webcam_android->isChecked());



    settings.setValue("comboBox_Server_IP_Distant",dui_Options.comboBox_Server_IP_Distant->currentText());
    settings.setValue("comboBox_Server_IP_Local",dui_Options.comboBox_Server_IP_Local->currentText());
    settings.setValue("comboBox_Server_Port",dui_Options.comboBox_Server_Port->currentText());

    settings.setValue("comboBox_Server_IP_Distant_index",dui_Options.comboBox_Server_IP_Distant->currentIndex());
    settings.setValue("comboBox_Server_IP_Local_index",dui_Options.comboBox_Server_IP_Local->currentIndex());
    settings.setValue("comboBox_Server_Port_index",dui_Options.comboBox_Server_Port->currentIndex());
    //    settings.setValue("WEB_SERVER_PORT",WEB_SERVER_PORT);
    //    settings.setValue("WEB_WEBCAM_PORT",WEB_WEBCAM_PORT);

    qDebug() << "Done !";


}


void MainWindow::closeEvent(QCloseEvent *event)
{
    MainWindow::saveSettings();
}

void MainWindow::on_pushButton_reset_settings_clicked()
{
    MainWindow::resetSettings();
}
