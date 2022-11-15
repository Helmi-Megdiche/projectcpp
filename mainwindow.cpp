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
#include <QPrinter>
#include <QPrintDialog>
#include <QApplication>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPrinter>
#include <QPrintDialog>
#include "mail.h"



QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap pix1("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background->setPixmap(pix1);

    QPixmap pix3("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background1->setPixmap(pix3);
    QPixmap pix4("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background2->setPixmap(pix4);
    QPixmap pix5("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background3->setPixmap(pix5);
    QPixmap pix6("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background4->setPixmap(pix6);
    QPixmap pix7("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background5->setPixmap(pix7);
    QPixmap pix8("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Background/Backg.jpg") ;
    ui->background6->setPixmap(pix8);


    QPixmap pix2("C:/Users/helmi/Desktop/PROJET_HELMI/GESTION_PERSONNEL/Logo/Logo1.png") ;
    ui->logo1->setPixmap(pix2);

    ui->num_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->num_tel2->setValidator(new QIntValidator(0, 99999999, this));


    Connection c1;
    c1.createconnect();




   // ui->lineEdit_ETAT->setValidator(new QIntValidator(0, 1, this));
    ui->tab_af->setModel(a.afficher());

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
    ui->tab_af->setModel(a.afficher());

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
             ui->tab_af->setModel(a.afficher());

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
        ui->tab_af->setModel(model);
    }
    else if (val == "Nom (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY Nom ASC");
        ui->tab_af->setModel(model);
    }
    else if (val == "Prenom (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY PRENOM ASC");
        ui->tab_af->setModel(model);
    }
    else if (val == "Num_Tel (croissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NUM_TEL ASC");
        ui->tab_af->setModel(model);
    }
    else if (val == "ID_personnel (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY ID_PERSONNEL DESC");
        ui->tab_af->setModel(model);
    }
    else if (val == "Nom (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NOM DESC");
        ui->tab_af->setModel(model);
    }
    else if (val == "Prenom (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY PRENOM DESC");
        ui->tab_af->setModel(model);
    }
    else if (val == "Num_Tel (decroissant)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from PERSONEL ORDER BY NUM_TEL DESC");
        ui->tab_af->setModel(model);
    }
}


void MainWindow::on_rechercher_textChanged(const QString &arg1)//recherche
{
    ui->tableView->setModel(a.chercher(arg1));
}



void MainWindow::on_pushButton_pdf_clicked()
{

        QPrinter printer;
        printer.setPrinterName("PERSONEL");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec() == QDialog::Rejected) return;
        ui->textEdit->print(&printer);

}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from PERSONEL where ID_personnel=:val");
        qry.bindValue(":val",val);
        if (qry.exec())
        {
            while(qry.next())
            {
                QString s=(qry.value(0).toString()+"\n"+qry.value(1).toString()+"\n"+qry.value(2).toString()+"\n"+qry.value(3).toString());
                ui->textEdit->setText(s);
            }
        }
            else
            {
               QMessageBox::warning(this,"error","no information");
            }
}

void MainWindow::on_pushButton_STSAT_clicked()
{
    ui->tabWidget->show();
       ui->tabWidget->setCurrentIndex(4);
       QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8;
       qreal tot=0,cp=0,ca=0,cm=0,cd=0,ch=0,cs=0,ct=0;
       q1.prepare("Select * from PERSONEL");
       if(q1.exec())
       {
           while (q1.next())
           {
               tot++;
           }
       }
       q2.prepare("SELECT * FROM PERSONEL WHERE ID_PERSONNEL LIKE 'p%' or ID_PERSONNEL LIKE 'P%'");
       if(q2.exec())
       {
           while (q2.next())
           {
               cp++;
           }
       }
       q3.prepare("Select * from PERSONEL where ID_PERSONNEL ='s%' or ID_PERSONNEL LIKE 'S%'");
       if(q3.exec())
       {
           while (q3.next())
           {
               cs++;
           }
       }
       q4.prepare("Select * from PERSONEL where ID_PERSONNEL ='d%' or ID_PERSONNEL LIKE 'D%'");
       if(q4.exec())
       {
           while (q4.next())
           {
               cd++;
           }
       }
       q5.prepare("Select * from PERSONEL where ID_PERSONNEL ='a%' or ID_PERSONNEL LIKE 'A%'");
       if(q5.exec())
       {
           while (q5.next())
           {
               ca++;
           }
       }
       q6.prepare("Select * from Hotel where ID_PERSONNEL ='m%' or ID_PERSONNEL LIKE 'M%'");
       if(q6.exec())
       {
           while (q6.next())
           {
               cm++;
           }
       }
       q7.prepare("Select * from Hotel where ID_PERSONNEL ='h%' or ID_PERSONNEL LIKE 'H%'");
       if(q7.exec())
       {
           while (q7.next())
           {
               ch++;
           }
       }
       q8.prepare("Select * from Hotel where ID_PERSONNEL ='t%' or ID_PERSONNEL LIKE 'T%'");
       if(q8.exec())
       {
           while (q8.next())
           {
               ct++;
           }
       }
       ca=ca/tot;
       cs=cs/tot;
       cp=cp/tot;
       cm=cm/tot;
       ch=ch/tot;
       ct=ct/tot;
       cd=cd/tot;
       QPieSeries *series = new QPieSeries();
               series->append("Administration",ca);
               series->append("Securité",cs);
               series->append("Pilote",cp);
               series->append("Hotesse",ch);
               series->append("Equipe de ménage",cm);
               series->append("Agent des piste",ct);
               series->append("Agent de diane",cd);
               QPieSlice *slice0 = series->slices().at(0);
               slice0->setExploded();
               slice0->setLabelVisible();
               slice0->setPen(QPen(Qt::darkGray, 2));
               slice0->setBrush(Qt::gray);
               QPieSlice *slice1 = series->slices().at(1);
               slice1->setExploded();
               slice1->setLabelVisible();
               slice1->setPen(QPen(Qt::darkRed, 2));
               slice1->setBrush(Qt::red);
               QPieSlice *slice2 = series->slices().at(2);
               slice2->setExploded();
               slice2->setLabelVisible();
               slice2->setPen(QPen(Qt::darkYellow, 2));
               slice2->setBrush(Qt::yellow);
               QPieSlice *slice3 = series->slices().at(3);
               slice3->setExploded();
               slice3->setLabelVisible();
               slice3->setPen(QPen(Qt::darkGreen, 2));
               slice3->setBrush(Qt::green);
               QPieSlice *slice4 = series->slices().at(4);
               slice4->setExploded();
               slice4->setLabelVisible();
               slice4->setPen(QPen(Qt::blue, 2));
               slice4->setBrush(Qt::cyan);
               QChart *chart = new QChart();
               chart->addSeries(series);
               chart->setTitle("MOST PERSONNEL SAVED");
               chart->setAnimationOptions(QChart::AllAnimations);
               chart->legend()->hide();
               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               QGridLayout *layout = new QGridLayout();
               layout->addWidget(chartView);
               ui->STSAT->setLayout(layout);
}












void MainWindow::on_pushButton_7_clicked()//ajout_cong
{
    QString d0=ui->ID_cong->text();
    QString d1=ui->date_debut->text();
    QString d2=ui->date_retour->text();
    QString s="non confirmer";
    QSqlQuery qry;
    qry.prepare("INSERT INTO CONGE (ID_PERSONNEL,DATE_DEBUT,DATE_RETOUR,ETAT)"
                "VALUES (:ID_PERSONNEL,:DATE_DEBUT,:DATE_RETOUR,:ETAT)");
    qry.bindValue(":ID_PERSONNEL",d0);
    qry.bindValue(":DATE_DEBUT",d1);
    qry.bindValue(":DATE_RETOUR",d2);
    qry.bindValue(":ETAT",s);
    if(qry.exec())
    {

     QMessageBox::information(this,"edit","validee");

    }
    else
    {QMessageBox::warning(this,"edit","failed");


}

}




void MainWindow::on_pb_supp1_clicked()
{
    QSqlQuery query;
    QString ID_PERSONNEL=ui->ID_cong->text();
       query.prepare("Delete from CONGE where ID_PERSONNEL=:ID_PERSONNEL");
       query.bindValue(":ID_PERSONNEL",ID_PERSONNEL);
      if (query.exec())
      {

       QMessageBox::information(this,"edit","validee");

      }
      else
      {
          QMessageBox::warning(this,"edit","failed");

        }
}



void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    QString ID_PERSONNEL=ui->ID_cong->text();
    QString ETAT="confirmee";
       query.prepare("update CONGE set  ETAT=:ETAT where ID_PERSONNEL=:ID_PERSONNEL" );
       query.bindValue(":ID_PERSONNEL",ID_PERSONNEL);
       query.bindValue(":ETAT",ETAT);
      if (query.exec())
      {

       QMessageBox::information(this,"edit","validee");

      }

      else
      {
          QMessageBox::warning(this,"edit","failed");

       }

}

void MainWindow::on_pushButton_9_clicked()
{
    QSqlQuery req;
        QStandardItemModel *model =new QStandardItemModel(4,4);
       int row=0;
       req.exec("select *from CONGE");
       while(req.next())
       {
           for(int i=0;i<4;i++)
           {
               QStandardItem *item=new QStandardItem(req.value(i).toString());   //i le nombre de colone;
               model->setItem(row,i,item);
           }
           row++;

       }

       model->setHeaderData(0,Qt::Horizontal,"ID_PERSONNEL");
       model->setHeaderData(1,Qt::Horizontal,"DATE_DEBUT");//ecrire header of table
       model->setHeaderData(2,Qt::Horizontal,"DATE_RETOUR");
       model->setHeaderData(3,Qt::Horizontal,"confirmation");




       ui->aff_cong->setModel(model);
}

void MainWindow::on_pushButton_10_clicked()
{
    QSqlQuery query;
    QString ID_PERSONNEL=ui->ID_cong->text();
    QString ETAT="refusée";
       query.prepare("update CONGE set  ETAT=:ETAT where ID_PERSONNEL=:ID_PERSONNEL" );
       query.bindValue(":ID_PERSONNEL",ID_PERSONNEL);
       query.bindValue(":ETAT",ETAT);
      if (query.exec())
      {

       QMessageBox::information(this,"edit","validee");

      }

      else
      {
          QMessageBox::warning(this,"edit","failed");

}
}



void MainWindow::on_pushButton_mail_clicked()
{
    Smtp* smtp = new Smtp("helmi.megdiche@esprit.tn","211JMT5938","smtp.gmail.com",465);
          connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("medamine.daboussi@esprit.tn", ui->rec->text() , ui->sub->text(),ui->textEdit_mail->toPlainText());
            QMessageBox::information(nullptr, QObject::tr(" OK"),
                                QObject::tr("mail sent Successfuly.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}
