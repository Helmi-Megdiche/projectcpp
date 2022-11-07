#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
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

    QPixmap pix1("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background->setPixmap(pix1);

    QPixmap pix2("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Logo/Logo1.jpg") ;
    ui->logo1->setPixmap(pix2);

    ui->num_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->num_tel2->setValidator(new QIntValidator(0, 99999999, this));


    Connection c1;
    c1.createconnect();




   // ui->lineEdit_ETAT->setValidator(new QIntValidator(0, 1, this));
    ui->tab_av->setModel(a.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    QString ID_personnel=ui->lineEdit_ID_AVION->text();


    QString Num_Tel=ui->num_tel2->text();
    QString Nom=ui->lineEdit_CAPACITE->text();
    QString Prenom=ui->lineEdit_TYPE->text();

    personnel a(ID_personnel,Prenom,Nom,Num_Tel);
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
     QString etat =ui->num_tel->text();
      QString idavion=ui->lineEdit_ID_AVION_2->text();

        query.prepare("UPDATE PERSONEL SET Prenom='"+type+"',Nom='"+capacite+"',Num_Tel='"+etat+"'WHERE ID_personnel=:ID_personnel");
        query.bindValue(":ID_personnel",idavion);

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




void MainWindow::on_linecomboBox_currentIndexChanged(const QString &x)
{
    QString val = ui->linecomboBox->currentText();
    if (val == "ID_personnel (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY ID_PERSONNEL ASC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Nom (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY Nom ASC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Prenom (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY PRENOM ASC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Num_Tel (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NUM_TEL ASC");
        ui->tab_av->setModel(model);
    }
    else if (val == "ID_personnel (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY ID_PERSONNEL DESC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Nom (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NOM DESC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Prenom (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY PRENOM DESC");
        ui->tab_av->setModel(model);
    }
    else if (val == "Num_Tel (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NUM_TEL DESC");
        ui->tab_av->setModel(model);
    }
}

