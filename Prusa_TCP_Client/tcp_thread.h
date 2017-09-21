#ifndef TCP_THREAD_H
#define TCP_THREAD_H

#include <QThread>


#include <QThread>
#include <QTcpSocket>

//! [0]
class TCP_Thread : public QThread
{
    Q_OBJECT

public:
    TCP_Thread(QString _server_IP, int _server_port, QObject *parent);
    TCP_Thread(QString _server_IP, int _server_port, QObject *parent);
    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
};
//! [0]

#endif // TCP_THREAD_H
