#include "avions.h"
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

AVIONS::AVIONS()
{
    ID_AVION="";
    TYPE="";
    CAPACITE="";
    ETAT="";
}

AVIONS::AVIONS(QString ID_AVION ,QString TYPE,QString CAPACITE,QString ETAT)
{
 this->ID_AVION=ID_AVION;
 this->TYPE=TYPE;
 this->CAPACITE=CAPACITE;
 this->ETAT=ETAT;

}
bool AVIONS::ajouter()
{
   // Connection c;

    QSqlQuery query;

    query.prepare("INSERT INTO AVIONS(ID_AVION ,TYPE,CAPACITE,ETAT)""VALUES(:ID_AVION,:TYPE,:CAPACITE,:ETAT)");
    query.bindValue(":ID_AVION",ID_AVION);
    query.bindValue(":TYPE",TYPE);
    query.bindValue(":CAPACITE",CAPACITE);
    query.bindValue(":ETAT",ETAT);

    return query.exec();
}
QSqlQueryModel * AVIONS::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from AVIONS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ETAT"));

return model;

}
bool AVIONS::supprimer(QString ID_AVION)
{
QSqlQuery query;
query.prepare("Delete from AVIONS where ID_AVION=:ID_AVION");
query.bindValue(":ID_AVION",ID_AVION);
return  query.exec();
}
bool AVIONS::modifierav()

{
QSqlQuery query;
QString up=QString(ID_AVION);

//preparation de la requette

query.prepare("update  AVIONS set TYPE=:TYPE,CAPACITE=:CAPACITE,ETAT=:ETAT where ID_AVION=:ID_AVION");
//creation des variables liée

query.bindValue(":ID_AVION",up);
query.bindValue(":TYPE",TYPE);
query.bindValue("CAPACITE",CAPACITE);
query.bindValue(":ETAT",ETAT);

return query.exec();//retourner la resultat d execution

}

