#include "vol.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
vol::vol()
{
    num =0;
    id_pilote =0;
    destination =" ";
    depart =" ";
    arrivage =" ";
    date_vol =" ";
}

vol::vol(int num,QString destination,QString depart,QString arrivage,int id_pilote,QString date_vol)
{
    this->num=num;
    this->destination=destination;
    this->depart=depart;
    this->arrivage=arrivage;
    this->id_pilote =id_pilote;
    this->date_vol=date_vol;
}

int vol::getnum(){return num;}
QString vol::getdestination(){return destination;}
QString vol::getdepart(){return depart;}
QString vol::getarrivage(){return arrivage;}
int vol::getid_pilote(){return id_pilote;}
QString vol::getdate_vol(){return date_vol;}

void vol::setnum(int num){this->num=num;}
void vol::setdestination(QString destination){this->destination=destination;}
void vol::setdepart(QString depart){this->depart=depart;}
void vol::setarrivage(QString arrivage){this->arrivage=arrivage;}
void vol::setid_pilote(int id_pilote){this->id_pilote=id_pilote;}
void vol::setdate_vol(QString date_vol){this->date_vol=date_vol;}
bool vol::ajouter()
{

    QSqlQuery query;
    QString num_string= QString::number(num);
    QString id_string= QString::number(id_pilote);


     query.prepare("INSERT INTO VOL (NUM, DESTINATION, TEMP_DEPART ,TEMP_ARRIVAGE ,ID_PILOTE ,DATE_VOL)"
                  "VALUES (:NUM, :DESTINATION, :TEMP_DEPART ,:TEMP_ARRIVAGE ,:ID_PILOTE ,:DATE_VOL)");
    query.bindValue(":NUM", num_string);
    query.bindValue(":DESTINATION", destination);
    query.bindValue(":TEMP_DEPART", depart);
    query.bindValue(":TEMP_ARRIVAGE", arrivage);
    query.bindValue(":ID_PILOTE", id_string);
    query.bindValue(":DATE_VOL", date_vol);



    return query.exec();
}
QSqlQueryModel* vol::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMP_DEPART"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEMP_ARRIVAGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_PILOTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_VOL"));


    return model;
}
bool vol::supprimer(int num,QString destination, int id_pilote)
{
    QSqlQuery query;
    query.prepare("delete from VOL where NUM = :NUM and DESTINATION =:DESTINATION and ID_PILOTE=:ID_PILOTE");
    query.bindValue(":NUM", num);
    query.bindValue(":DESTINATION",destination );
    query.bindValue(":ID_PILOTE", id_pilote );
    return query.exec();
}
