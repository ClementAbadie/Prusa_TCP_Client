#include "mainwindow.h"
#include <QApplication>

#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>



int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // DPI support

    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
