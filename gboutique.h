#ifndef GBOUTIQUE_H
#define GBOUTIQUE_H
#include <QDialog>
#include "boutique.h"
#include <QObject>
#include <QDate>
#include <QCharRef>
QT_BEGIN_NAMESPACE
namespace Ui { class gboutique; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class gboutique : public QDialog
{
    Q_OBJECT

public:
    gboutique(QWidget *parent = nullptr);
    ~gboutique();

private:
    Ui::gboutique *ui;
    QStringList files;
    BOUTIQUE a;
    QSystemTrayIcon *mSystemTrayIcon;

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_clicked();
    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
    void on_pushButton_2_clicked();
    void on_modifier_2_clicked();
    void sendMail();
    void mailSent(QString);
   void browse();
   void on_sendBtn_clicked();
   void on_browseBtn_clicked();
};
#endif // MAINWINDOW_H
