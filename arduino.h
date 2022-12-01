#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
class Arduino
{
public: //méthodes de la classe Arduino
Arduino();
int connect_arduino(); // permet de connecter le PC 4 Arduino
int close_arduino(); // permet de femer la connexion
int write_to_arduino( QByteArray ); // envoyer des données vers arduino
QByteArray read_from_arduino(); //recevoir des données de la carte Arduino
QSerialPort* getserial(); // accesseur
QString getarduino_port_name();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,..) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data; // contenant les données lues a partir d'Arduino


};
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


#endif // ARDUINO_H
