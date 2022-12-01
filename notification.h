#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>

class notification
{
public:
    notification();
    void notification_ajoutAvion();

     void notification_supprimerAvion();

     void notification_modifierAvion();
     void notification_pdf();
     void notification_vol1();
    void notification_vol2();
    void notification_vol3();
};

#endif // NOTIFICATION_H
