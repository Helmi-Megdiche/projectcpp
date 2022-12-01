#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include "personnel.h"
#include <QSqlDatabase>
#include"connect.h"
#include "admin.h"
#include <QMessageBox>
#include "personnel.h"
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
           if ( qry.value(1).toString()==username && qry.value(0).toString()==password && qry.value(5).toString()!="Administrateur" )
           {

               personnel p;
               p.exec() ;
           }
           else
                     if(qry.value(1).toString()==username && qry.value(0).toString()==password &&qry.value(5).toString()=="Administrateur")
                     {

                         admin a;
                         a.exec();}
           else
                   QMessageBox::warning(this, "Connexion Impossible", "Identifiant ou mot de passe incorrect ! ") ;
       }
}


