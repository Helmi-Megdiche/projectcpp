#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class personnel
{
    QString ID_personnel ,Prenom, Nom ,Num_Tel ;
public:
    personnel();
    personnel(QString,QString,QString,QString);
    QString getID_personnel();
    QString getPrenom();
    QString getNom();
    QString getNum_Tel();

    void setID_personnel(QString);
    void setPrenom(QString);
    void setNom(QString);
    void setNum_Tel(QString);


    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer(QString);
    bool modifierav();

};

#endif // PERSONNEL_H
