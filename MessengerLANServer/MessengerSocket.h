#ifndef MESSENGERSOCKET_H
#define MESSENGERSOCKET_H
#include <QTcpSocket>
namespace DuarteCorporation
{
class MessengerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MessengerSocket(qintptr handle, QObject *parent =nullptr);
signals:
  void DuReadyRead(MessengerSocket *);
  void DuStateChanged(MessengerSocket *,int);
};
}
#endif // MESSENGERSOCKET_H
