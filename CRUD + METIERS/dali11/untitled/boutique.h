#ifndef AVIONS_H
#define AVIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class BOUTIQUE
{
    QString ID_BOUTIQUE ,SURFACE, PRIX ,DATEF ;
public:
    BOUTIQUE();
    BOUTIQUE(QString,QString,QString,QString);
    QString getID_BOUTIQUE();
    QString getSURFACE();
    QString getPRIX();
    QString getDATEF();

    void setID_BOUTIQUE(QString);
    void setSURFACE(QString);
    void setPRIX(QString);
    void setDATEF(QString);


    bool ajouter();
    QSqlQueryModel * afficher ();
   QSqlQueryModel *   afficherTri();
    QSqlQueryModel *   Recherche(QString );
    bool supprimer(QString);
    bool modifierav();

};

#endif // AVIONS_H
