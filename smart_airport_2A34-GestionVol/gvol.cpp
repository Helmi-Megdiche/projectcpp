#include "gvol.h"
#include "ui_gvol.h"
#include "vol.h"
#include "map.h"
#include "arduino.h"
#include "QMessageBox"
#include <QIntValidator>
#include "connexion.h"
#include <QTableWidget>
#include <QModelIndex>
#include <QtDebug>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion & arduino

    switch(ret)
    {

    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
    break;

    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name() ;
    break;

    case(-1):qDebug() << "arduino is not available";

    }

    QObject::connect(A.getserial() ,SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
    //le slot update_label suite 4 la reception du signal readyRead (reception des données).


    QTimer *timer=new QTimer (this);
    connect (timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    QDate date=QDate::currentDate() ;
    QString datetext=date.toString("dd/MM/yyyy");
    ui->datetime->setText(datetext);
    ui->datetime_2->setText(datetext);

    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.tn/maps/dir/A%C3%A9roport+Tunis-Carthage,+Tunis/A%C3%A9roport+Paris+Beauvais,+Route+de+l'A%C3%A9roport,+Till%C3%A9,+France/@42.7983164,-2.8188915,5z/data=!3m1!4b1!4m14!4m13!1m5!1m1!1s0x12e2cad2e1d7f1bb:0x902488d100b5819b!2m2!1d10.2175601!2d36.8475562!1m5!1m1!1s0x47e66f8c0d8d3c2d:0xfa0f5b904d3dd76e!2m2!1d2.1115111!2d49.4544677!3e4?hl=fr");


    QPixmap pix1("C:/Users/Yassine/Desktop/2a34/projet/gestion_des_vols/backg&logo/backg.jpg") ;
    ui->backg->setPixmap(pix1);
    ui->backg_2->setPixmap(pix1);
    ui->backg_4->setPixmap(pix1);
    ui->backg_5->setPixmap(pix1);
    ui->backg_6->setPixmap(pix1);
    ui->backg_7->setPixmap(pix1);
    ui->backg_8->setPixmap(pix1);
    ui->backg_9->setPixmap(pix1);
    QPixmap pix2("C:/Users/Yassine/Desktop/2a34/projet/gestion_des_vols/backg&logo/logo2.png") ;
  //ui->logo->setPixmap(pix2);

    ui->num->setMaxLength(4);
    ui->num_2->setMaxLength(4);
    ui->num_3->setMaxLength(4);
    ui->id->setMaxLength(8);
    ui->id_2->setMaxLength(8);
    ui->tab_vols->setModel(v.afficher());
    ouvrir=A.read_from_arduino();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_afficher_2_clicked()
{
    ui->tab_vols->setModel(v.afficher());
}
void MainWindow::on_pb_ajouter_clicked()
{
    int num=ui->num->text().toInt();
    QString destination=ui->choisir->currentText();
    QString depart=ui->depart->text();
    QString arrivage=ui->arrivage->text() ;
    QString id_pilote=ui->id->text();
    QDate date_vol=ui->dateEdit->date() ;

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

    vol v;
    v.setnum(ui->num_2->text().toInt());
    bool test=v.supprimer(v.getnum());

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

void MainWindow::on_modifier_clicked()
{
    int num=ui->num_2->text().toInt();
    QString destination=ui->choisir_2->currentText();
    QString depart=ui->depart_2->text();
    QString arrivage=ui->arrivage_2->text() ;
    QString id_pilote=ui->id_2->text();
    QDate date_vol=ui->dateEdit_2->date() ;

    vol v(num,destination,depart,arrivage,id_pilote,date_vol) ;
    bool test = v.modifier();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("mise à jour effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("mise à jour non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_linecomboBox_activated(const QString &arg1)
{
    QString val = ui->linecomboBox->currentText();
    if (val == "num (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY NUM ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "num (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY NUM DESC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "id_pilote (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY ID_PILOTE ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "id_pilote (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY ID_PILOTE DESC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "destination (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY DESTINATION ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "destination (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY DESTINATION desc");
        ui->tab_vols->setModel(model);
    }
    else if (val == "date_vol (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY DATE_VOL ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "date_vol (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY DATE_VOL desc");
        ui->tab_vols->setModel(model);
    }
    else if (val == "temp_depart (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY TEMP_DEPART ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "temp_depart (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY TEMP_DEPART desc");
        ui->tab_vols->setModel(model);
    }

    else if (val == "temp_arrivage (asc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY TEMP_ARRIVAGE ASC");
        ui->tab_vols->setModel(model);
    }
    else if (val == "temp_arrivage (desc)")
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from VOL ORDER BY TEMP_ARRIVAGE desc");
        ui->tab_vols->setModel(model);
    }
}

void MainWindow::on_actionajouter_triggered()
{
    ui->tab_widget->setCurrentIndex(0);
}

void MainWindow::on_actionafficher_3_triggered()
{
    ui->tab_widget->setCurrentIndex(1);

}

void MainWindow::on_actionrechercher_2_triggered()
{
    ui->tab_widget->setCurrentIndex(2);

}

void MainWindow::on_actionmap_2_triggered()
{
    ui->tab_widget->setCurrentIndex(6);

}

void MainWindow::on_actionPdf_triggered()
{
    ui->tab_widget->setCurrentIndex(3);

}
void MainWindow::on_actionChat_Bot_triggered()
{
    ui->tab_widget->setCurrentIndex(5);

}

void MainWindow::on_actionQuitter_triggered()
{
    ui->tab_widget->close();
}
void MainWindow::on_actionQuitter_clicked()
{
    ui->tab_widget->close();

}
void MainWindow::on_pb_effacer_clicked()
{
    ui->num->clear();
    ui->choisir->clear();
    ui->depart->clear() ;
    ui->arrivage->clear() ;
    ui->id->clear();
    ui->dateEdit->clear() ;
}

void MainWindow::on_pushButton_clicked()
{
    ui->num_2->clear();
    ui->choisir_2->clear();
    ui->depart_2->clear() ;
    ui->arrivage_2->clear() ;
    ui->id_2->clear();
    ui->dateEdit_2->clear() ;
}


void MainWindow::on_num_3_textChanged(const QString &re)
{
    ui->tab_recherche->setModel(v.recherche(re));
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter print;
    print.setPrinterName("vol");
    QPrintDialog dialog(&print,this);
    if (dialog.exec() == QDialog::Rejected) return;
    ui->text_pdf->print(&print);
}

void MainWindow::on_retour_arduino_clicked()
{
    ui->tab_widget->close();

}

void MainWindow::on_retour_1_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_2_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_3_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_4_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_13_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_6_clicked()
{
    ui->tab_widget->close();
}
void MainWindow::on_retour_7_clicked()
{
    ui->tab_widget->close();
}

void MainWindow::on_actionStatistique_triggered()
{
    ui->tab_widget->show();
    ui->tab_widget->setCurrentIndex(4);
    QSqlQuery q1,q2,q3,q4,q5,q6,q7;
    qreal total=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    q1.prepare("Select * from vol");
    if(q1.exec())
    {
        while (q1.next())
        {
            total++;
        }
    }
    q2.prepare("Select * from vol where destination ='tunis-->paris'");
    if(q2.exec())
    {
        while (q2.next())
        {
            c1++;
        }
    }
    q3.prepare("Select * from vol where destination ='tunis-->marocco'");
    if(q3.exec())
    {
        while (q3.next())
        {
            c2++;
        }
    }
    q4.prepare("Select * from vol where destination ='tunis-->japan'");
    if(q4.exec())
    {
        while (q4.next())
        {
            c3++;
        }
    }
    q5.prepare("Select * from vol where destination ='tunis-->usa'");
    if(q5.exec())
    {
        while (q5.next())
        {
            c4++;
        }
    }
    q6.prepare("Select * from vol where destination ='tunis-->algerie'");
    if(q6.exec())
    {
        while (q6.next())
        {
            c5++;
        }
    }
    q7.prepare("Select * from vol where destination ='tunis-->madagashkar'");
    if(q7.exec())
    {
        while (q7.next())
        {
            c6++;
        }
    }
    c1=c1/total;
    c2=c2/total;
    c3=c3/total;
    c4=c4/total;
    c5=c5/total;
    c6=c6/total;

    QPieSeries *series = new QPieSeries();

            series->append("tunis-->paris",c1);
            series->append("tunis-->marocco",c2);
            series->append("tunis-->japan",c3);
            series->append("tunis-->usa",c4);
            series->append("tunis-->algerie",c5);
            series->append("tunis-->madagashkar",c6);

            QPieSlice *slice0 = series->slices().at(0);

            slice0->setExploded();
            slice0->setLabelVisible();
            slice0->setPen(QPen(Qt::darkRed, 2));
            slice0->setBrush(Qt::red);

            QPieSlice *slice1 = series->slices().at(1);

            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::darkMagenta, 2));
            slice1->setBrush(Qt::magenta);

            QPieSlice *slice2 = series->slices().at(2);

            slice2->setExploded();
            slice2->setLabelVisible();
            slice2->setPen(QPen(Qt::darkBlue, 2));
            slice2->setBrush(Qt::blue);

            QPieSlice *slice3 = series->slices().at(3);

            slice3->setExploded();
            slice3->setLabelVisible();
            slice3->setPen(QPen(Qt::darkGray, 2));
            slice3->setBrush(Qt::gray);

            QPieSlice *slice4 = series->slices().at(4);

            slice4->setExploded();
            slice4->setLabelVisible();
            slice4->setPen(QPen(Qt::darkCyan, 2));
            slice4->setBrush(Qt::cyan);

            QPieSlice *slice5 = series->slices().at(5);

            slice5->setExploded();
            slice5->setLabelVisible();
            slice5->setPen(QPen(Qt::darkYellow, 2));
            slice5->setBrush(Qt::yellow);


            QChart *chart = new QChart();

            chart->addSeries(series);
            chart->setTitle("les pays les plus visitées");
            chart->setAnimationOptions(QChart::AllAnimations);
            chart->legend()->hide();

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            QGridLayout *layout = new QGridLayout();
            layout->addWidget(chartView);
            ui->stat->setLayout(layout);
}

void MainWindow:: showTime ()

{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");

    if ((time.second() % 2) == 0)
    {
        time_text [3] = ' ' ;
        time_text [8] = ' ' ;
    }
    ui->clock->setText (time_text);
    ui->clock_2->setText (time_text);
}

void MainWindow::on_tab_vols_clicked(const QModelIndex &index)
{
    QString pdf;
    QString val =ui->tab_vols->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM VOL WHERE NUM = :val");
    qry.bindValue(":val",val);

    if(qry.exec())
       {
            while(qry.next())
            {
                pdf=(qry.value(0).toString() + "\n" + qry.value(1).toString() +"\n" +qry.value(2).toString() +"\n" +qry.value(3).toString() +"\n" +qry.value(4).toString() +"\n" +qry.value(5).toString());
            }
       }
    ui->text_pdf->setText(pdf);
}

void MainWindow::getChat()
{

    QString date;
    QString Conversation = ui->lineEdit_Conversation->text();
    QString nickname, msgForTextEdit, text,message_sent;
    chatbot CB(nickname,Conversation,message_sent);
    QSqlQuery querySelect = CB.afficherChat(Conversation);
    if (querySelect.exec())
    {
        ui->textEdit->clear();
        while (querySelect.next())
        {
            nickname = querySelect.value(0).toString();
            msgForTextEdit = querySelect.value(1).toString();
            date = querySelect.value(2).toString();
            text = date + "   " +  nickname +  ":  " + msgForTextEdit;
            ui->textEdit->append(text);
        }
    }
}


void MainWindow::on_chat_clicked()
{
    QString nickname = ui->lineEdit_->text();
    QString Conversation = ui->lineEdit_Conversation->text();
    QString message_sent =ui->lineEdit_message->text();
    chatbot CB(nickname,Conversation,message_sent);
    QSqlQuery query= CB.envoyerchat();

    if (query.exec())
    {
         getChat();
    }
}




void MainWindow::on_ajout_arduino_clicked()
{
    QString idaa= ui->id_arduino->text();
    QString nomaa= ui->nom_arduino->text();
    QString prenomaa= ui->prenom_arduino->text() ;
    int soldeaa= ui->solde_arduino->text().toInt() ;

    ard a(idaa,nomaa,prenomaa,soldeaa) ;


    bool test = a.ajouter_arduino();
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                     QObject::tr("Ajout non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_effacer_arduino_clicked()
{
    ui->id_arduino->clear();
    ui->nom_arduino->clear() ;
    ui->prenom_arduino->clear() ;
    ui->solde_arduino->clear() ;
}


void MainWindow::on_modifier_arduino_clicked()
{
    int soldeaa=ui->solde_arduino->text().toInt();
    QString nomaa=ui->nom_arduino->text();
    QString prenomaa=ui->prenom_arduino->text();
    QString idaa=ui->id_arduino->text();
    ard a(idaa,nomaa,prenomaa,soldeaa) ;
    bool test =a.modifier_arduino();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("mise à jour effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("mise à jour non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::update_label()
{

    data=A.read_from_arduino();
    QByteArray text=QByteArray::fromHex(data);
    QSqlQuery qry;
    serialBuffer +=QString::fromStdString(data.toStdString());


    if( qry.exec("select * from RFID where ID like '"+serialBuffer+"%'"))
    {
        A.write_to_arduino("1");
    }
}

