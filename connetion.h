#ifndef CONNETION_H
#define CONNETION_H
#include <QSqlDatabase>

class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeconnection();
    ~connection(){};
};

#endif // CONNETION_H
