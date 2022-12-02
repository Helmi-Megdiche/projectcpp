#include "boutique.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

BOUTIQUE::BOUTIQUE()
{
    ID_BOUTIQUE="";
    SURFACE="";
    PRIX="";
    DATEF="";
}

BOUTIQUE::BOUTIQUE(QString ID_BOUTIQUE ,QString SURFACE,QString PRIX,QString DATEF)
{
 this->ID_BOUTIQUE=ID_BOUTIQUE;
 this->SURFACE=SURFACE;
 this->PRIX=PRIX;
 this->DATEF=DATEF;

}
bool BOUTIQUE::ajouter()
{
   // Connection c;

    QSqlQuery query;

    query.prepare("INSERT INTO BOUTIQUE(ID_BOUTIQUE ,SURFACE,PRIX,DATEF)""VALUES(:ID_BOUTIQUE,:SURFACE,:PRIX,:DATEF)");
    query.bindValue(":ID_BOUTIQUE",ID_BOUTIQUE);
    query.bindValue(":SURFACE",SURFACE);
    query.bindValue(":PRIX",PRIX);
    query.bindValue(":DATEF",DATEF);

    return query.exec();
}
QSqlQueryModel * BOUTIQUE::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from BOUTIQUE");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BOUTIQUE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("SURFACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEF"));

return model;
}

QSqlQueryModel * BOUTIQUE::afficherTri()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from BOUTIQUE order by ID_BOUTIQUE");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BOUTIQUE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("SURFACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEF"));

return model;



}

QSqlQueryModel * BOUTIQUE::Recherche( QString ID_BOUTIQUE)
{
   QSqlQuery query;
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from BOUTIQUE  where ID_BOUTIQUE='"+ID_BOUTIQUE+"'");
query.bindValue(":ID_BOUTIQUE",ID_BOUTIQUE);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_BOUTIQUE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("SURFACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEF"));


return model;



}
bool BOUTIQUE::supprimer(QString ID_BOUTIQUE)
{
QSqlQuery query;
query.prepare("Delete from BOUTIQUE where ID_BOUTIQUE  like '"+ID_BOUTIQUE+"'");
query.bindValue(":ID_BOUTIQUE",ID_BOUTIQUE);
return  query.exec();
}
bool BOUTIQUE::modifierav()

{
QSqlQuery query;
QString up=QString(ID_BOUTIQUE);

//preparation de la requette

query.prepare("update  BOUTIQUE set SURFACE=:SURFACE,PRIX=:PRIX,DATEF=:DATEF where ID_BOUTIQUE=:ID_BOUTIQUE");
//creation des variables liée

query.bindValue(":ID_BOUTIQUE",up);
query.bindValue(":SURFACE",SURFACE);
query.bindValue("PRIX",PRIX);
query.bindValue(":DATEF",DATEF);

return query.exec();//retourner la resultat d execution

}
/*bool BOUTIQUE::ForStat();
{
QSqlQuery query;
QString up=QString(ID_BOUTIQUE);

//preparation de la requette

query.prepare("select * from BOUTIQUE");
//creation des variables liée

query.bindValue(":ID_BOUTIQUE",up);
query.bindValue(":SURFACE",SURFACE);
query.bindValue("PRIX",PRIX);
query.bindValue(":DATEF",DATEF);

query.exec();

a=
return
*/




