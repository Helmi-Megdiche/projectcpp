#include "MessengerServer.h"
#include "MessengerSocket.h"
#include <QDebug>
namespace DuarteCorporation
{
MessengerServer::MessengerServer(QObject *parent)
    :QTcpServer(parent)
{

}

bool MessengerServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any,port);
}

void MessengerServer::incomingConnection(qintptr handle)
{
    qDebug() << "Personnel connecté avec handle:" << handle;
 auto socket = new MessengerSocket(handle,this);
 msockets <<socket ;
 for (auto i :msockets) {
     QTextStream T(i);
     T <<"Server :il a connecté" << handle;
     i->flush();
 }
 connect(socket, &MessengerSocket::DuReadyRead,[&](MessengerSocket *S)
 {
     qDebug() << "DuReadyRead";
     QTextStream T(S);
     auto text =T.readAll();
    for (auto i :msockets){
        QTextStream K(i);
        K << text;
        i->flush();
    }
 });
 connect(socket,&MessengerSocket::DuStateChanged,[&](MessengerSocket *S,int ST) {
      qDebug() << "Personnel changé avec handle:"<<S->socketDescriptor();
     if(ST==QTcpSocket::UnconnectedState){
          qDebug() << "Personnel déconnecté avec handle:" <<S->socketDescriptor();
         msockets.removeOne(S);
         for(auto i:msockets){
             QTextStream K(i);
             K << "Server: Les personnels d'avion" << S->socketDescriptor() << "le personnel est deconnecté";
             i->flush();
         }
     }
 });
}
}
