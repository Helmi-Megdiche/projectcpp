#ifndef AVIONS_H
#define AVIONS_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class AVIONS
{
    QString ID_AVION ,TYPE, CAPACITE ,ETAT,DATEACHAT ;
public:
    AVIONS();
    AVIONS(QString,QString,QString,QString,QString);
    QString getID_AVION();
    QString getTYPE();
    QString getCAPACITE();
    QString getETAT();
    QString getDATEACHAT();
    void setID_AVION(QString);
    void setTYPE(QString);
    void setCAPACITE(QString);
    void setETAT(QString);
    void setDATEACHAT(QString);

    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer(QString);
    bool modifierav();
    QSqlQueryModel * trierID();
    QSqlQueryModel * trierCAP();
    QSqlQueryModel * trierETAT();
    QSqlQueryModel * trierDATE();
    QSqlQueryModel * rechercherID(QString);
    QSqlQueryModel * rechercherTYPE(QString);
    QSqlQueryModel * rechercherCAP(QString);
    QSqlQueryModel * rechercherETAT(QString);
    QSqlQueryModel * rechercherDATE(QString);
    QSqlQueryModel * affichervol(QString);

};

#endif // AVIONS_H
