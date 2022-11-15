#include "personnel.h"
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

personnel::personnel()
{
    ID_personnel="";
    Prenom="";
    Nom="";
    Num_Tel="";
}

personnel::personnel(QString ID_personnel ,QString Prenom,QString Nom,QString Num_Tel)
{
 this->ID_personnel=ID_personnel;
 this->Prenom=Prenom;
 this->Nom=Nom;
 this->Num_Tel=Num_Tel;

}
bool personnel::ajouter()
{
   // Connection c;

    QSqlQuery query;

    query.prepare("INSERT INTO PERSONEL(ID_personnel ,Prenom,Nom,Num_Tel)""VALUES(:ID_PERSONNEL,:PRENOM,:NOM,:NUM_TEL)");
    query.bindValue(":ID_PERSONNEL",ID_personnel);
    query.bindValue(":PRENOM",Prenom);
    query.bindValue(":NOM",Nom);
    query.bindValue(":NUM_TEL",Num_Tel);

    return query.exec();
}
QSqlQueryModel * personnel::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from PERSONEL");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PERSONNEL"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_TEL"));

return model;

}
bool personnel::supprimer(QString ID_personnel)
{
QSqlQuery query;
query.prepare("Delete from PERSONEL where ID_PERSONNEL=:ID_PERSONNEL");
query.bindValue(":ID_PERSONNEL",ID_personnel);
return  query.exec();


}
bool personnel::modifierav()

{
QSqlQuery query;

//preparation de la requette

query.prepare("UPDATE  PERSONEL SET NUM_TEL=:NUM_TEL,NOM=:NOM,PRENOM=:PRENOM"
              "WHERE ID_PERSONNEL='"+ID_personnel+"' ");
//creation des variables liée

query.bindValue(":ID_PERSONNEL",ID_personnel);
query.bindValue(":PRENOM",Prenom);
query.bindValue("NOM",Nom);
query.bindValue(":NUM_TEL",Num_Tel);

return query.exec();//retourner la resultat d execution

}

QSqlQueryModel * personnel::chercher(QString ar)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * from PERSONEL where ID_PERSONNEL like '%"+ar+"%'");
    return model;
}







