
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include "gavions.h"
#include <QSqlDatabase>
#include"connect.h"
#include "gpersonnel.h"
#include <QMessageBox>
#include "gvol.h"
#include "gpassager.h"
#include "gboutique.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection c;
    c.createconnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QSqlQuery qry;

    qry.prepare("Select * from PERSONNELS where NOM=:NOM");
       qry.bindValue(":NOM",username);
       qry.exec();
       while (qry.next())

       {
           if ( qry.value(1).toString()==username && qry.value(0).toString()==password && qry.value(5).toString()=="GAVIONS" )
           {

               gavions gav;
               gav.exec() ;
           }
           else
                     if(qry.value(1).toString()==username && qry.value(0).toString()==password &&qry.value(5).toString()=="Administrateur")
                     {

                         gpersonnel gp;
                         gp.exec();}
                     else
                               if(qry.value(1).toString()==username && qry.value(0).toString()==password &&qry.value(5).toString()=="GVOLS")
                               {

                                   gvol gv;

                                   gv.exec();}
                               else
                                         if(qry.value(1).toString()==username && qry.value(0).toString()==password &&qry.value(5).toString()=="GPASSAGERS")
                                         {

                                             gpassager gp;

                                             gp.exec();}
                                         else
                                                   if(qry.value(1).toString()==username && qry.value(0).toString()==password &&qry.value(5).toString()=="GBOUTIQUES")
                                                   {

                                                       gboutique gb;

                                                       gb.exec();}
           else
                   QMessageBox::warning(this, "Connexion Impossible", "Identifiant ou mot de passe incorrect ! ") ;
       }
}


