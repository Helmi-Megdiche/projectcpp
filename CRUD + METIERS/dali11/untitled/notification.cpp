#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajoutboutique()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/medal/Desktop/wael/f.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","Nouvelle commande ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimer_boutique(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/medal/Desktop/wael/f.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","commande Supprimé",QSystemTrayIcon::Information,15000);
}

void Notification::notification_modifier_boutique(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/medal/Desktop/wael/f.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","Une commande est modifié",QSystemTrayIcon::Information,15000);

}
