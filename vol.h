#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlQueryModel>
class vol
{
public:
vol();
vol (int, QString,QString,QString,int,QString) ;
int getnum();
QString getdestination();
QString getdepart();
QString getarrivage();
int getid_pilote();
QString getdate_vol();

void setnum(int);
void setdestination(QString) ;
void setdepart(QString) ;
void setarrivage(QString);
void setid_pilote(int);
void setdate_vol(QString);
bool ajouter();
bool supprimer(int,QString,int);
QSqlQueryModel* afficher();


private:
int num,id_pilote;
QString destination,depart,arrivage,date_vol;

};

#endif // VOL_H
