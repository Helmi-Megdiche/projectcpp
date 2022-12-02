#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}
void notification::notification_ajoutAvion()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des avions ","Nouveau Avion ajouté ",QSystemTrayIcon::Information,15000);
}
void notification::notification_supprimerAvion()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des avions ","Avion Supprimé ",QSystemTrayIcon::Information,15000);
}
void notification::notification_modifierAvion()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des avions ","Avion modifié ",QSystemTrayIcon::Information,15000);
}
 void notification:: notification_vol1()
 {

     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

     notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
     notifyIcon->show();
     notifyIcon->showMessage("Gestion des vols ","On peut assurer les vols ",QSystemTrayIcon::Information,15000);
 }
 void notification:: notification_vol2()
 {

     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

     notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
     notifyIcon->show();
     notifyIcon->showMessage("Gestion des vols ","On peut assurer les vols mais avec risque ",QSystemTrayIcon::Information,15000);
 }
 void notification:: notification_vol3()
 {

     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

     notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
     notifyIcon->show();
     notifyIcon->showMessage("Gestion des vols ","On ne peut pas assurer les vols ",QSystemTrayIcon::Information,15000);
 }
void notification:: notification_pdf()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/sboui/OneDrive/Bureau/projetfinal/ICONE/logo.ico"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des avions ","Fiche technique téléchargée ",QSystemTrayIcon::Information,15000);
}

