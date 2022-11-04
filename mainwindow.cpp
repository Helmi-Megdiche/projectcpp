#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avions.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QFileDialog>
#include<QTextDocument>
#include <QDate>
#include <QDateEdit>
#include <QSystemTrayIcon>
#include<QPainter>
#include <QIntValidator>
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Connection c1;
    c1.createconnect();




    ui->lineEdit_ETAT->setValidator(new QIntValidator(0, 1, this));
    ui->tab_av->setModel(a.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    QString ID_AVION=ui->lineEdit_ID_AVION->text();


    QString ETAT=ui->lineEdit_ETAT->text();
    QString CAPACITE=ui->lineEdit_CAPACITE->text();
    QString TYPE=ui->lineEdit_TYPE->text();

    AVIONS a(ID_AVION,TYPE,CAPACITE,ETAT);
    Connection c;
    c.createconnect();


     bool test1=a.ajouter();

    if(test1)
    {
        QMessageBox::information (nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué .\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical (nullptr,QObject::tr("not ok"),
                                    QObject::tr("ajout échoué.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_av->setModel(a.afficher());

}

void MainWindow::on_pb_supprimer_clicked()
{
    Connection c4;
    c4.createconnect();
    QString ID_AVION=ui->lineEdit_ID_AVION_3->text();


    bool test2=a.supprimer(ID_AVION);

    if(test2)
    {
        QMessageBox::information (nullptr,QObject::tr("ok"),
                QObject::tr("suppression effectuée .\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical (nullptr,QObject::tr("not ok"),
                                    QObject::tr("suppression échoué.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    QSqlQuery query;

      QString type=ui->lineEdit_type->text();
      QString capacite=ui->lineEdit_capacite->text();
  QString etat =ui->lineEdit_etat->text();
  QString idavion=ui->lineEdit_ID_AVION_2->text();

        query.prepare("UPDATE AVIONS SET TYPE='"+type+"',CAPACITE='"+capacite+"',ETAT='"+etat+"'WHERE ID_AVION=:ID_AVION");
        query.bindValue(":ID_AVION",idavion);

         if(query.exec())
          {
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("UPDATE successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_av->setModel(a.afficher());

          }
          else
          {
             QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("UPDATE failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

          }




}
