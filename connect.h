#ifndef CONNECT_H
#define CONNECT_H
#include<QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
 QSqlDatabase db;
public:
    connection();
    bool createconnect();
    void closeconnect();
};

#endif // CONNECT_H
