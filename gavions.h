#ifndef GAVIONS_H
#define GAVIONS_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "notification.h"
#include <blocknote.h>
#include "avions.h"
#include "arduino.h"
namespace Ui {
class gavions;
}
class QTcpSocket;


class gavions : public QDialog
{
    Q_OBJECT

public:
    explicit gavions(QWidget *parent = nullptr);
    ~gavions();

private:
    Ui::gavions *ui;
    AVIONS a;
    QString tri,recherche;
    notification N;
    QTcpSocket *msocket;
    blocknote *blocknotee;
    arduino A;
    QByteArray data;
    QString serialBuffer;
private slots:
     void on_pushButton_Ajouter_clicked();
     void showtime();
     void on_pushButton_clicked();
     void on_pb_supprimer_clicked();
     void on_modifier_clicked();
     void on_comboBox_activated(const QString &arg1);
     void on_comboBox_2_activated(const QString &arg1);
     void on_pushButton_2_clicked();
     void on_tab_av_activated(const QModelIndex &index);
     void on_pushButton_4_clicked();
     void on_calendarWidget_activated(const QDate &date);
     void on_pushButton_9_clicked();
     void on_pushButton_stat_clicked();
     void on_send_clicked();
     void on_bind_clicked();
     void on_pushButton_10_clicked();
     void update_label();
     void on_pushButton_11_clicked();
};

#endif // PERSONNEL_H
