#ifndef LOGINN_H
#define LOGINN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class loginn
{
public:
    loginn();
    loginn(QString,QString,QString);
    QString getid();
    QString getpassword();
    QString getmail();
    void setid(QString);
    void setpassword(QString);
    void setmail(QString);
    bool ajouter();

private:
    QString password,mail,id;
};

#endif // LOGINN_H
