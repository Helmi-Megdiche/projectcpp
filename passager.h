#ifndef PASSAGER_H
#define PASSAGER_H
#include <QString>
#include <QSqlQueryModel>

#include <QtCharts>
#include <QChartView>
#include <QLegend>
#include <QPieSeries>
#include <QPieSlice>



class Passager
{
public:
    Passager();
    Passager(QString,QString,int,QString,QString,int,int,QString);
    int getnumpass();
    int getbillet();
    int getbag();
    QString getnom();
    QString getprenom();
    QString getdest();
    QString getclasse();
    QString getnumvol();
    void setnumpass(int);
    void setbillet(int);
    void setbag(int);
    void setnom(QString);
    void setprenom(QString);
    void setdest(QString);
    void setclasse(QString);
    void setnumvol(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int numpass);

    bool modifier();


private:
    int numpass,billet,bag;
    QString nom,prenom,dest,classe,numvol ;
};

#endif // PASSAGER_H
