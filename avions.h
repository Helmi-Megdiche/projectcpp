#ifndef AVIONS_H
#define AVIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class AVIONS
{
    QString ID_AVION ,TYPE, CAPACITE ,ETAT ;
public:
    AVIONS();
    AVIONS(QString,QString,QString,QString);
    QString getID_AVION();
    QString getTYPE();
    QString getCAPACITE();
    QString getETAT();

    void setID_AVION(QString);
    void setTYPE(QString);
    void setCAPACITE(QString);
    void setETAT(QString);


    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer(QString);
    bool modifierav();

};

#endif // AVIONS_H
