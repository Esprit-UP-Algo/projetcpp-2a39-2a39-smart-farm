#include "mainwindow.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    MainWindow w;
    bool cnx = c.createconnection(); // créer une connexion avec la base de données
    if(cnx) // success
        w.show();
    else // echec
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Data Base connection failed. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    return a.exec();
}
