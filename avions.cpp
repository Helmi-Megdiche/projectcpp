#include "avions.h"

AVIONS::AVIONS()
{
    ID_AVION="";
    TYPE="";
    CAPACITE="";
    ETAT="";
    DATEACHAT="";
}

AVIONS::AVIONS(QString ID_AVION ,QString TYPE,QString CAPACITE,QString ETAT,QString DATEACHAT)
{
 this->ID_AVION=ID_AVION;
 this->TYPE=TYPE;
 this->CAPACITE=CAPACITE;
 this->ETAT=ETAT;
 this->DATEACHAT=DATEACHAT;
}
bool AVIONS::ajouter()
{
   // Connection c;

    QSqlQuery query;

    query.prepare("INSERT INTO AVIONS(ID_AVION ,TYPE,CAPACITE,ETAT,DATEACHAT)""VALUES(:ID_AVION,:TYPE,:CAPACITE,:ETAT,:DATEACHAT)");
    query.bindValue(":ID_AVION",ID_AVION);
    query.bindValue(":TYPE",TYPE);
    query.bindValue(":CAPACITE",CAPACITE);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":DATEACHAT",DATEACHAT);
    return query.exec();
}
QSqlQueryModel * AVIONS::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from AVIONS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));
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
query.prepare("update  AVIONS set TYPE=:TYPE,CAPACITE=:CAPACITE,ETAT=:ETAT,DATEACHAT=:DATEACHAT where ID_AVION=:ID_AVION");
query.bindValue(":ID_AVION",up);
query.bindValue(":TYPE",TYPE);
query.bindValue("CAPACITE",CAPACITE);
query.bindValue(":ETAT",ETAT);
query.bindValue(":DATEACHAT",DATEACHAT);
return query.exec();
}

QSqlQueryModel *AVIONS::trierID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS ORDER BY ID_AVION");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));
 return model;
}

QSqlQueryModel *AVIONS::trierCAP()
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS ORDER BY CAPACITE");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::trierETAT()
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS ORDER BY ETAT");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::trierDATE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS ORDER BY DATEACHAT");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::rechercherID(QString ID_AVION)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS WHERE ID_AVION='"+ID_AVION+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::rechercherTYPE(QString TYPE)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS WHERE TYPE='"+TYPE+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::rechercherCAP (QString CAPACITE)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS WHERE CAPACITE='"+CAPACITE+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::rechercherETAT(QString ETAT)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS WHERE ETAT='"+ETAT+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::rechercherDATE (QString DATEACHAT)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from AVIONS WHERE DATEACHAT='"+DATEACHAT+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AVION"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("CAPACITE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEACHAT"));

 return model;
}
QSqlQueryModel *AVIONS::affichervol(QString date_text)
{
    QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from VOLS WHERE DATEVOL='"+date_text+"'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_VOLS"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESTINATION"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEMPSDEDEPART"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEMPSARRIVAGE"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEVOL"));

 return model;
}

