#include "mainwindow.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    MainWindow w;
    if(c.createconnection())
        w.show();
    else
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Data Base connection failed. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    return a.exec();
}
