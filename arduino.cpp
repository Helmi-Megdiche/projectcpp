#include "arduino.h"
#include <QDebug>
#include <QSqlQuery>


Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}
QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}
QSerialPort* Arduino::getserial()
{
    return  serial;
}

int Arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
        {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
               {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)
                    {
                arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();
                    }
               }
         }
    qDebug() << "arduino_port_name is :" <<arduino_port_name;
    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name) ;

        if (serial->open(QSerialPort::ReadWrite))
         {
            serial->setBaudRate(QSerialPort::Baud9600); // dÃ©bit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8); //Longueur des donnÃ©es : 8 bits,
            serial->setParity(QSerialPort::NoParity); //1 bit de paritÃ© optionnel|
            serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
            serial->setFlowControl(QSerialPort::NoFlowControl) ;

            return 0;
         }
              return 1;

     }
                return -1;
}

int Arduino::close_arduino()
{

    if(serial->isOpen())
    {
          serial->close();
          return 0;
    }
    return 1;

}

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
}

int Arduino::write_to_arduino( QByteArray d)
{
    if(serial->isWritable())
    {
    serial->write(d); // envoyer des donnÃ©es vers Arduino
    }
    else
    {
    qDebug() << "Couldn't write to serial!";
    }
}


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
