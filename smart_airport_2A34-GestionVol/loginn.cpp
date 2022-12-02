#include "loginn.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>

loginn::loginn()
{
    id=""; password=""; mail="";
}
loginn::loginn(QString id,QString password,QString mail)
{this->id=id; this->password=password; this->mail=mail;}
QString loginn::getid(){return id;}
QString getid_signup();
QString loginn::getpassword(){return password;}
QString loginn::getmail(){return mail;}

void loginn::setid(QString id){this->id=id;}
void loginn::setpassword(QString password){this->password=password;}
void loginn::setmail(QString mail){this->mail=mail;}

bool loginn::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VOLL (id, password, mail) "
              "VALUES (:id, :password, :mail)");
    query.bindValue(":id", id);
    query.bindValue(":password", password);
    query.bindValue(":mail", mail);
    return query.exec();
}

