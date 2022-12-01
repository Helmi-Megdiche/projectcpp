#include "vol.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
vol::vol()
{
    num =0;
    id_pilote=" ";
    destination =" ";
    depart =" ";
    arrivage =" ";
}

vol::vol(int num,QString destination,QString depart,QString arrivage,QString id_pilote,QDate date_vol)
{
    this->num=num;
    this->destination=destination;
    this->depart=depart;
    this->arrivage=arrivage;
    this->id_pilote=id_pilote;
    this->date_vol=date_vol;
}

int vol::getnum(){return num;}
QString vol::getdestination(){return destination;}
QString vol::getdepart(){return depart;}
QString vol::getarrivage(){return arrivage;}
QString vol::getid_pilote(){return id_pilote;}
QDate vol::getdate_vol(){return date_vol;}

void vol::setnum(int num){this->num=num;}
void vol::setdestination(QString destination){this->destination=destination;}
void vol::setdepart(QString depart){this->depart=depart;}
void vol::setarrivage(QString arrivage){this->arrivage=arrivage;}
void vol::setid_pilote(QString id_pilote){this->id_pilote=id_pilote;}
void vol::setdate_vol(QDate date_vol){this->date_vol=date_vol;}


bool vol::ajouter()
{

    QSqlQuery query;
    QString num_string= QString::number(num);

     query.prepare("INSERT INTO VOL (NUM, DESTINATION, TEMP_DEPART ,TEMP_ARRIVAGE ,ID_PILOTE ,DATE_VOL)"
                  "VALUES (:NUM, :DESTINATION, :TEMP_DEPART ,:TEMP_ARRIVAGE ,:ID_PILOTE ,:DATE_VOL)");
    query.bindValue(":NUM", num_string);
    query.bindValue(":DESTINATION", destination);
    query.bindValue(":TEMP_DEPART", depart);
    query.bindValue(":TEMP_ARRIVAGE", arrivage);
    query.bindValue(":ID_PILOTE", id_pilote);
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
bool vol::supprimer(int num)
{
    QSqlQuery query;
    query.prepare("delete from VOL where NUM = :NUM ");
    query.bindValue(":NUM", num);
    return query.exec();
}
bool vol :: modifier()
{
    QSqlQuery query;
    QString num_string= QString::number(num);
    query.prepare("UPDATE VOL SET NUM= :NUM, DESTINATION= :DESTINATION, TEMP_DEPART= :TEMP_DEPART,"
                  " TEMP_ARRIVAGE= :TEMP_ARRIVAGE, ID_PILOTE= :ID_PILOTE, DATE_VOL = :DATE_VOL "
                        " WHERE  NUM = '"+num_string+"' ");
    query.bindValue(":NUM", num_string);
    query.bindValue(":DESTINATION", destination);
    query.bindValue(":TEMP_DEPART", depart);
    query.bindValue(":TEMP_ARRIVAGE", arrivage);
    query.bindValue(":ID_PILOTE", id_pilote);
    query.bindValue(":DATE_VOL", date_vol);
    return query.exec();
}

QSqlQueryModel * vol ::recherche(QString re)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * from VOL where NUM like '%"+re+"%' ");
    return model;
}


chatbot::chatbot(QString nickname, QString Conversation, QString message_sent)
{
    this->nickname = nickname;
    this->Conversation = Conversation;
    this->message_sent = message_sent;

}
QSqlQuery chatbot::envoyerchat()
 {
    QSqlQuery query;
    query.prepare("insert into CHATBOT values (:NICKNAME, :CONVERSATION, CHATBOT_SEQ.nextval, :MESSAGE_SENT, sysdate); ");
    query.bindValue(":NICKNAME", nickname);
    query.bindValue(":CONVERSATION", Conversation);
    query.bindValue(":MESSAGE_SENT", message_sent);
    return query;
}

QSqlQuery chatbot::afficherChat(QString Conversation)
{
    QSqlQuery query;

    query.prepare("select  NICKNAME, MESSAGE_SENT, TO_CHAR(date_sent, 'dy HH24:MI') from CHATBOX where conversation like "+Conversation+" date_sent; ");
    return query;
}
