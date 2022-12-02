#ifndef ARD_H
#define ARD_H

#include <QString>
class ard
{
public:
ard();
ard (QString,QString,QString,int) ;

QString getida();
QString getnoma();
QString getprenoma();
int getsoldea();
void setida(QString) ;
void setnoma(QString);
void setprenoma(QString);
void setsoldea(int);

bool ajouter_arduino();
bool modifier_arduino();

private:

QString ida,noma,prenoma;
int soldea;

};


#endif // ARD_H
