#include "login.h"
#include "ui_login.h"
#include "loginn.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include "vol.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->id->setPlaceholderText("Entrer votre id");
    ui->mdp->setPlaceholderText("Entrer votre mot de passe");
    ui->id_3->setPlaceholderText("Entrer votre id");
    ui->mdp_3->setPlaceholderText("Entrer votre mot de passe");
    ui->mail->setPlaceholderText("Entrer votre mail");


    ui->id->setMaxLength(8);
}

login::~login()
{
    delete ui;
}

void login::on_inscrire_clicked()
{
    QString id=ui->id_3->text();
    QString password=ui->mdp_3->text();
    QString mail=ui->mail->text();
loginn L(id, password, mail);

bool test=L.ajouter();
if(test)
{
//ui->statut1->setText("Ajout effectué");
ui->id->clear();
ui->mdp->clear();
//ui->signup_mail->clear();
}
//else
//ui->statut1->setText("Ajout non effectué");
}

void login::on_connexion_clicked()
{
    QString id=ui->id->text();
    QString  password=ui->mdp->text();
    QSqlQuery qry;
    if(qry.exec("select * from VOLL where ID='"+id +"' and PASSWORD='"+password+"'"))
    {
       int count=0;
        while (qry.next()){
               count++;
           }
        if(count==1)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué \n" "Click cancel to exit."),QMessageBox::Cancel);            M= new MainWindow(this);
            M->show();
            ui->id->clear();
            ui->mdp->clear();
        }
       else{
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
}
}
/*
void Login::on_b_recuperation_clicked()
{
    QString id=ui->login_id->text();
    QString  mail=ui->r_mail->text();
    QSqlQuery qry;
    if(qry.exec("select * from juge where id='"+id +"' and password='"+mail+"'")) {
       int count=0;
        while (qry.next()){
               count++;
           }
        if(count==1) {
            ui->statut->setText("Le mot de passe a été\nenvoyer à votre mail");
            Smtp* smtp = new Smtp("guesmi.aymen@esprit.tn","211JMT42072001","smtp.gmail.com",465);
                  connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                  smtp->sendMail("guesmi.aymen@esprit.tn", ui->r_mail->text(), ui->r_mail->text(),ui->r_mail->text());//titre
                    QMessageBox::information(nullptr, QObject::tr(" OK"),
                                        QObject::tr("mail sent Successfuly.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
        else{
            ui->statut->setText("Mail ou ID incorrecte\nLa récupération non effectuer");}
}}
*/
