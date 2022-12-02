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
#include <QTextStream>
#include <QTextDocument>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QCharRef>
#include <QChar>
#include "QPrintDialog"
#include "connection.h"
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include "smtp.h"
#include "avions.h"
#include "avions.cpp"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QChartView>
#include <QtCharts/QLegend>

#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
QT_CHARTS_USE_NAMESPACE







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{





    ui->setupUi(this);




    //appel a l'icon
    mSystemTrayIcon = new QSystemTrayIcon (this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mSystemTrayIcon->setVisible(true);

//statistique






    QBarSet *set0 = new QBarSet("Devise") ;
    QBarSet *set1 = new QBarSet("Vetemens");
    QBarSet *set2 = new QBarSet("parfums") ;
    QBarSet *set3 = new QBarSet("Tabac");
    QBarSet *set4 = new QBarSet("Eau de vie") ;

    *set0<< 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;


    QBarSeries *series = new QBarSeries();
    series->append(set0) ;
    series->append(set1)  ;
    series->append(set2) ;
    series->append(set3) ;   //horizontalFrame
    series->append(set4) ;

    QChart *chart = new QChart();
    chart->addSeries(series) ;

    chart->setTitle("Les categories des  achats par rapport au Mois du Jan au Jun (avant Saison) ");
    chart->setAnimationOptions(QChart::SeriesAnimations) ;

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis;
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame) ;
    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse()));

    Connection c1;
    c1.createconnect();
//

    //les boutons mailer
    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse()));


    //ui->lineEdit_ETAT->setValidator(new QIntValidator(0, 1, this));
    ui->tab_av->setModel(a.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    mSystemTrayIcon->showMessage(tr("Notifiaction"), tr("boutique ajoutée"));


    QString ID_BOUTIQUE=ui->lineEdit_ID_AVION->text();

QMessageBox::aboutQt(this,tr("About Qt"));
    QString DATEF=ui->lineEdit_ETAT->text();
    QString PRIX=ui->lineEdit_CAPACITE->text();
    QString SURFACE=ui->lineEdit_TYPE->text();

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
    ui->tab_av->setModel(a.afficherTri());

}

void MainWindow::on_pb_supprimer_clicked()
{mSystemTrayIcon->showMessage(tr("Notifiaction"), tr("boutique supprimée"));
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
{mSystemTrayIcon->showMessage(tr("Notifiaction"), tr("boutique modifée"));
    QSqlQuery query;

      QString type=ui->lineEdit_type->text();
      QString capacite=ui->lineEdit_capacite->text();
  QString etat =ui->lineEdit_etat->text();
  QString idavion=ui->lineEdit_ID_AVION_2->text();

        query.prepare("UPDATE BOUTIQUE SET SURFACE='"+type+"',PRIX='"+capacite+"',DATEF='"+etat+"'WHERE ID_BOUTIQUE=:ID_BOUTIQUE");
        query.bindValue(":ID_BOUTIQUE",idavion);

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

void MainWindow::on_pushButton_2_clicked()
{

    QString ID_BOUTIQUE=ui->line_rech->text();
    ui->tab_av->setModel(a.Recherche(ID_BOUTIQUE));
}


/*void MainWindow::on_modifier_2_clicked()
{
    QSqlDatabase db;
                   QTableView tab_av;
                   QSqlQueryModel * Modal=new  QSqlQueryModel();
                   QSqlQuery query;

                   QSqlQuery qry;
                    qry.prepare("SELECT * FROM BOUTIQUE,ACHAT where (ACHAT.ID_BOUTIQUE=BOUTIQUE.ID_BOUTIQUE) and (ID_BOUTIQUE=) and (DATEA)  ");
                    qry.exec();
                    Modal->setQuery(qry);
                   tab_av.setModel(Modal);
                   QString ID_BOUTIQUE=ui->lineEdit_ID_AVION_4->text();
                   QDate A=ui->dateEdit_2->date();

                    QDate DE=ui->dateEdit->date();







                    db.close();


                    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = tab_client.model()->rowCount();
                    const int columnCount =  tab_client.model()->columnCount();


                    const QString strTitle ="Document";


                    out <<  "<html>\n"
                        "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg(strTitle)
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                       << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Clients")
                       <<"<br>"
                        <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!tab_client.isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(tab_client.model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!tab_client.isColumnHidden(column)) {
                                QString data = tab_client.model()->data(tab_client.model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                            "<br><br>"
                            //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                            <<"<br>"
                            <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                        out << "<thead><tr bgcolor=#f0f0f0>";

                            out <<  "</table>\n"

                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;
                    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                    if (dialog->exec() == QDialog::Accepted) {

                        QLabel lab;
                         QPixmap pixmap(":/img/aze.png");
                        lab.setPixmap(pixmap);
                        QPainter painter(&lab);
                        //QPrinter printer(QPrinter::PrinterResolution);

                        //pixmap.load("aze.png");
                        //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                        //painter.drawPixmap(10,10,50,50, pixmap);

                        document->print(&printer);
                    }

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName("/tmp/commandes.pdf");
                    printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                    delete document;
}

void MainWindow::on_modifier_2_clicked()
{

}
*/


void MainWindow::on_modifier_2_clicked()
{mSystemTrayIcon->showMessage(tr("Notifiaction"), tr("Document imprimé"));
    /*QMediaPlayer * bulletsound = new QMediaPlayer();
           bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/HP/Desktop/Smart_Pastry_Shop_2A26/yassine/2.mp3"));
          if (bulletsound->state() == QMediaPlayer::PlayingState){
               bulletsound->setPosition(0);
           }
           else if (bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->play();
           }*/
    QPdfWriter pdf("C:/Users/medal/Desktop/wael/untitled/untitled.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Boutiques");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/medal/Desktop/wael/untitled/untitled.pdf"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID_BOUTIQUE");
    painter.drawText(1800,3300,"SURFACE");
    painter.drawText(3800,3300,"PRIX ALLOCATION");    //ID_PASSAGER,NOM,PRENOM,SOMME,TAXFREE from BOUTIQUE,PASSAGER,ACHAT where (BOUTIQUE.ID_BOUTIQUE=ACHAT.ID_BOUTIQUE)AND (PASSAGER.ID_PASSAGER=ACHAT.ID_PASSAGER) AND (ID_BOUTIQUE=ID_BOUTIQUE)
    painter.drawText(5800,3300,"assba");
  //  painter.drawText(8000,3300,"TELEPHONE");

    QString ID_BOUTIQUE=ui->lineEdit_ID_AVION_4->text();

    QSqlQuery query;
    QString up= QString(ID_BOUTIQUE);
    query.prepare(" select * from BOUTIQUE "); //ID_PASSAGER,NOM,PRENOM,SOMME,TAXFREE from BOUTIQUE,PASSAGER,ACHAT where (BOUTIQUE.ID_BOUTIQUE=ACHAT.ID_BOUTIQUE)AND (PASSAGER.ID_PASSAGER=ACHAT.ID_PASSAGER) AND (ID_BOUTIQUE=ID_BOUTIQUE)
    query.bindValue(":ID_BOUTIQUE",up);
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        //painter.drawText(8000,i,query.value(4).toString());
        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/medal/Desktop/wael/untitled/untitled.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }


}


void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("mohamedali.benromdhane1@esprit.tn","medali@@@","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
    smtp->sendMail("mohamedali.benromdhane1@esprit.tn", ui->adresseMail->text() , ui->objet->text(),ui->message->toPlainText() );
    else
        smtp->sendMail("mohamedali.benromdhane1@esprit.tn", ui->adresseMail->text() , ui->objet->text(),ui->message->toPlainText());
}

void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->adresseMail->clear();
    ui->objet->clear();
    ui->file->clear();
    ui->message->clear();
    ui->pass->clear();
}



/*void MainWindow::on_browse_clicked()
{
  // browse();

}

void Dialog::on_envoyer_clicked()
{
   QString status;
    sendMail();
    mailSent(status);

}*/
