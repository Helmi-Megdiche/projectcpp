#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A34");
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("yassine159753??");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;
     return  test;
}
