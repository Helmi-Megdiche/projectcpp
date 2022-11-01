#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include "QMessageBox"
#include<QIntValidator>
#include"connection.h"
#include<QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->num->setValidator(new QIntValidator(0, 9999, this));
    ui->id->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_vols->setModel(v.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int num=ui->num->text().toInt();
    QString destination=ui->dest->text();
    QString depart=ui->dep->text() ;
    QString arrivage=ui->arr->text() ;
    int id_pilote=ui->id->text().toInt();
    QString date_vol=ui->date->text() ;

    vol v(num,destination,depart,arrivage,id_pilote,date_vol) ;
    Connection c;
    c.createconnect();

    bool test = v.ajouter();
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
            ui->tab_vols->setModel(v.afficher());
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                     QObject::tr("Ajout non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_pb_supprimer_clicked()
{

    vol v1;
    v1.setnum(ui->num_supp->text().toInt());
    v1.setid_pilote(ui->id_supp->text().toInt());
    v1.setdestination(ui->dest_supp->text());
    bool test=v1.supprimer(v1.getnum(),v1.getdestination(),v1.getid_pilote());

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppression effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
          ui->tab_vols->setModel(v.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("suppression non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);

}
