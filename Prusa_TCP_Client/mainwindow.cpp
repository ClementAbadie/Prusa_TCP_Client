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
    mainWindows->comboBox_Server_IP->addItem("192.168.0.150");
    mainWindows->comboBox_Server_IP->addItem("192.168.0.190");


    mainWindows->comboBox_Server_Port->addItem("51717");
    mainWindows->comboBox_Server_Port->addItem("56250");

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

    dialog.show();

    if (dialog.exec() == QDialog::Accepted)
    {
        // store dialog content somewhere

    }

    tcp_timeout_time_ms = dui.spinBox_timeout_unsaved_time->value();
    qDebug() << "END";
}

void MainWindow::tcp_timeout(){
    qDebug() << "Timeout ! Aborted.";

    mainWindows->Server_MSG->setText("Server not found !");
    m_TcpSocket.disconnectFromHost();
    m_TcpSocket.close();
    m_TcpSocket.abort();
    tcp_timer->stop();

}

void MainWindow::on_PushButton_Connect_to_Server_clicked()
{
    Connect_to_Server();
}

void MainWindow::Connect_to_Server()
{
    mainWindows->Server_MSG->setText("");
    if(!m_TcpSocket_connected)
    {
        QString server_ip = mainWindows->comboBox_Server_IP->currentText();
        int server_port = mainWindows->comboBox_Server_Port->currentText().toInt();

        {
            if (m_debug)
                qDebug() << "TcpSocket server:" << server_ip << ":" << server_port;

            mainWindows->Server_MSG->setText("Connection...");
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
    m_TcpSocket_connected = true;

    if (m_debug)
        qDebug() << "TcpSocket connected";

    //ENABLE BUTTONS

    mainWindows->Prusa_ON->setEnabled(true);
    mainWindows->Prusa_OFF->setEnabled(true);
    mainWindows->Server_Stop->setEnabled(true);
    mainWindows->Server_ReStart->setEnabled(true);
}
//! [onConnected]


//! [onDisconnected]
void MainWindow::onDisconnected()
{
    mainWindows->PushButton_Connect_to_Server->setText("Connection");
    m_TcpSocket_connected = false;

    if (m_debug)
        qDebug() << "TcpSocket Disconnected";

    //DISABLE BUTTONS

    mainWindows->Prusa_ON->setEnabled(false);
    mainWindows->Prusa_OFF->setEnabled(false);
    mainWindows->Server_Stop->setEnabled(false);
    mainWindows->Server_ReStart->setEnabled(false);
    mainWindows->Server_MSG->setText("");
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

    mainWindows->Server_MSG->setText(m_TcpSocket.readAll());

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




