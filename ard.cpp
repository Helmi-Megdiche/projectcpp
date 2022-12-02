#include "ard.h"
#include <QSqlQuery>
#include <QDebug>

ard::ard()
{
    ida=" ";
    noma =" ";
    prenoma =" ";
    soldea=0;
}

ard::ard(QString ida,QString noma,QString prenoma,int soldea)
{
    this->ida=ida;
    this->noma=noma;
    this->prenoma=prenoma;
    this->soldea=soldea;
}

QString ard::getida(){return ida;}
QString ard::getnoma(){return noma;}
QString ard::getprenoma(){return prenoma;}
int ard::getsoldea(){return soldea;}

void ard::setida(QString ida){this->ida=ida;}
void ard::setnoma(QString noma){this->noma=noma;}
void ard::setprenoma(QString prenoma){this->prenoma=prenoma;}
void ard::setsoldea(int soldea){this->soldea=soldea;}

bool ard::ajouter_arduino()
{

    QSqlQuery query;

    query.prepare("INSERT INTO RFID (ID, NOM, PRENOM,SOLDE   )"
                  "VALUES (:ID, :NOM, :PRENOM,:SOLDE )");
    query.bindValue(":ID", ida);
    query.bindValue(":NOM", noma);
    query.bindValue(":PRENOM", prenoma);
    query.bindValue(":SOLDE", soldea);
    return query.exec();
}
bool ard :: modifier_arduino()
{
    QSqlQuery query;

    query.prepare("UPDATE RFID SET SOLDE = :SOLDE "
                        " WHERE  ID = '"+ida+"' ");
    query.bindValue(":SOLDE", soldea);

    return query.exec();
}
