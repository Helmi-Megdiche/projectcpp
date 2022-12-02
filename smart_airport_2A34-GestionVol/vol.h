#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTimer>
#include <QDate>

class vol
{
public:
vol();
vol (int, QString,QString,QString,QString,QDate) ;
int getnum();
QString getdestination();
QString getdepart();
QString getarrivage();
QString getid_pilote();
QDate getdate_vol();

void setnum(int);
void setdestination(QString) ;
void setdepart(QString) ;
void setarrivage(QString);
void setid_pilote(QString);
void setdate_vol(QDate);
bool ajouter();
bool supprimer(int);
QSqlQueryModel* afficher();
bool modifier();
QSqlQueryModel *recherche(QString);

private:
int num;
QString destination,id_pilote;
QDate date_vol;
QString depart,arrivage;

};
class chatbot
{
public:
    chatbot();
    chatbot(QString, QString, QString);
    QSqlQuery afficherChat(QString);
   QSqlQuery  envoyerchat();

private:
 QString nickname,Conversation,message_sent;
};

#endif // VOL_H
