#include "connection.h"

connection::connection()
{

}

bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Dhia");
    db.setPassword("esprit18");

    if(db.open())
        test=true;

    return test;
}

void connection::closeconnection()
{
    db.close();
}
