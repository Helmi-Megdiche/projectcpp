#include "personnel.h"
#include "ui_personnel.h"
#include<QTimer>
#include<QMessageBox>
#include <QSqlError>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <Qt>
#include <QTableWidget>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QTcpSocket>
#include "messengerconnection.h"
#include <blocknote.h>
QT_CHARTS_USE_NAMESPACE



personnel::personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personnel)
{
    ui->setupUi(this);
    msocket =new QTcpSocket(this);
    connect(msocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(msocket);
        auto text =T.readAll();
        ui->textEdit->append(text);
    });
    QTimer *timer=new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();

    QRegularExpression frnumber("\\b([0-9][0-9][0-9][0-9][-][0-1][0-9][-][0-3][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *fvalnumber = new QRegularExpressionValidator(frnumber,this);
             ui->lineEdit_DATEACHAT_2->setValidator(fvalnumber);
    QRegularExpression rnumber("\\b([0-9][0-9][0-9][0-9][-][0-1][0-9][-][0-3][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
             ui->lineEdit_DATEACHAT->setValidator(valnumber);
    ui->lineEdit_ID_AVION_3->setValidator(new QIntValidator(0, 1000000000, this));
    ui->lineEdit_ID_AVION_2->setValidator(new QIntValidator(0, 1000000000, this));
    ui->lineEdit_ID_AVION->setValidator(new QIntValidator(0, 1000000000, this));
    ui->lineEdit_CAPACITE_2->setValidator(new QIntValidator(20, 1000, this));
    ui->lineEdit_CAPACITE->setValidator(new QIntValidator(20, 1000, this));
    ui->lineEdit_ETAT_2->setValidator(new QIntValidator(0, 1, this));
    ui->lineEdit_ETAT->setValidator(new QIntValidator(0, 1, this));
    ui->tab_av->setModel(a.afficher());

    //arduino
    int ret=A.connect_arduino();
    switch(ret) {
    case(0):qDebug() <<"arduino is available and connected to : " << A.getarduino_port_name();
        break;
    case(1):qDebug() <<"arduino is available but not connected to : " << A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}
void personnel::showtime()
{
    QTime time=QTime::currentTime();
    QString text_time=time.toString("hh : mm : ss");
    if ((time.second() % 2) ==0)
    {
        text_time.replace(":"," ");
    }
    ui->DigitalClock->setText(text_time);
}

personnel::~personnel()
{
    delete ui;
}

void personnel::on_pushButton_Ajouter_clicked()
{
    QString ID_AVION=ui->lineEdit_ID_AVION->text();


    QString ETAT=ui->lineEdit_ETAT->text();
    QString CAPACITE=ui->lineEdit_CAPACITE->text();
    QString TYPE=ui->lineEdit_TYPE->text();
    QString DATEACHAT=ui->lineEdit_DATEACHAT->text();
    AVIONS a(ID_AVION,TYPE,CAPACITE,ETAT,DATEACHAT);

ui->lineEdit_ID_AVION->clear();
ui->lineEdit_CAPACITE->clear();
ui->lineEdit_ETAT->clear();
ui->lineEdit_TYPE->clear();
ui->lineEdit_DATEACHAT->clear();

     bool test1=a.ajouter();

    if(test1)
    {
        QMessageBox::information (nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué .\n"
                            "click cancel to exit."),QMessageBox::Cancel);

        ui->tab_av->setModel(a.afficher());
        N.notification_ajoutAvion();
    }
    else  QMessageBox::critical (nullptr,QObject::tr("not ok"),
                                    QObject::tr("ajout échoué.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
}

void personnel::on_pushButton_clicked()
{

    if (tri=="ID_AVION")
       {
        ui->tab_av->setModel(a.trierID());
       }
    else if (tri=="CAPACITE")
      {
        ui->tab_av->setModel(a.trierCAP());
       }
    else if (tri=="ETAT")
      {
        ui->tab_av->setModel(a.trierETAT());
      }
    else
      {
        ui->tab_av->setModel(a.trierDATE());
      }
}

void personnel::on_pb_supprimer_clicked()
{
    QString ID_AVION=ui->lineEdit_ID_AVION_3->text();
    ui->lineEdit_ID_AVION_3->clear();


    bool test2=a.supprimer(ID_AVION);

    if(test2)
    {
        QMessageBox::information (nullptr,QObject::tr("ok"),
                QObject::tr("suppression effectuée .\n"
                            "click cancel to exit."),QMessageBox::Cancel);
        N.notification_supprimerAvion();
    }
    else  QMessageBox::critical (nullptr,QObject::tr("not ok"),
                                    QObject::tr("suppression échoué.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
}

void personnel::on_modifier_clicked()
{
    QSqlQuery query;

      QString type=ui->lineEdit_TYPE_2->text();
      QString capacite=ui->lineEdit_CAPACITE_2->text();
  QString etat =ui->lineEdit_ETAT_2->text();
  QString idavion=ui->lineEdit_ID_AVION_2->text();
  QString dateachat=ui->lineEdit_DATEACHAT_2->text();
  ui->lineEdit_ID_AVION_2->clear();
  ui->lineEdit_CAPACITE_2->clear();
  ui->lineEdit_ETAT_2->clear();
  ui->lineEdit_TYPE_2->clear();
  ui->lineEdit_DATEACHAT_2->clear();

        query.prepare("UPDATE AVIONS SET TYPE='"+type+"',CAPACITE='"+capacite+"',ETAT='"+etat+"',DATEACHAT='"+dateachat+"' WHERE ID_AVION=:ID_AVION");
        query.bindValue(":ID_AVION",idavion);

         if(query.exec())
          {
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("UPDATE successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_av->setModel(a.afficher());
             N.notification_modifierAvion();

          }
          else
          {
             QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("UPDATE failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

          }
}

void personnel::on_comboBox_activated(const QString &arg1)
{
    tri=arg1;
}

void personnel::on_comboBox_2_activated(const QString &arg2)
{
    recherche=arg2;
}

void personnel::on_pushButton_2_clicked()
{
    if (recherche=="ID_AVION")
       {
        QString ID_AVION=ui->lineEdit_RECHERCHE->text();
        ui->tab_av->setModel(a.rechercherID(ID_AVION));
       }
    else if (recherche=="CAPACITE")
      {
       QString CAPACITE=ui->lineEdit_RECHERCHE->text();
        ui->tab_av->setModel(a.rechercherCAP(CAPACITE));
       }
    else if (recherche=="TYPE")
      {
        QString TYPE=ui->lineEdit_RECHERCHE->text();
        ui->tab_av->setModel(a.rechercherTYPE(TYPE));
       }
    else if (recherche=="ETAT")
      {
        QString ETAT=ui->lineEdit_RECHERCHE->text();
        ui->tab_av->setModel(a.rechercherETAT(ETAT));
      }
    else
      {
        QString DATEACHAT=ui->lineEdit_RECHERCHE->text();
        ui->tab_av->setModel(a.rechercherDATE(DATEACHAT));
      }
    ui->lineEdit_RECHERCHE->clear();
}

void personnel::on_tab_av_activated(const QModelIndex &index)
{
    QString modif=ui->tab_av->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from AVIONS where ID_AVION='"+modif+"'  ");
    if (qry.exec())
    {
         while (qry.next())
         {
             ui->lineEdit_ID_AVION_2->setText(qry.value(0).toString());
             ui->lineEdit_TYPE_2->setText(qry.value(1).toString());
             ui->lineEdit_CAPACITE_2->setText(qry.value(2).toString());
             ui->lineEdit_ETAT_2->setText(qry.value(3).toString());
             ui->lineEdit_DATEACHAT_2->setText(qry.value(4).toString());
         }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void personnel::on_pushButton_4_clicked()
{
    QTableView tab_av;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QString ID_AVION=ui->lineEdit_ID_AVION_4->text();
    QSqlQuery qury;
     qury.prepare("SELECT TYPE, CAPACITE, ETAT, DATEACHAT FROM AVIONS WHERE ID_AVION='"+ID_AVION+"'" );
     qury.exec();
     Modal->setQuery(qury);
    tab_av.setModel(Modal);

     QString strStream;
     QTextStream out(&strStream);

     const int rowCount = tab_av.model()->rowCount();
     const int columnCount =  tab_av.model()->columnCount();


     const QString strTitle ="Document";


     out <<  "<html>\n"
         "<head>\n"
             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg(strTitle)
         <<  "</head>\n"
         "<body bgcolor=#ffffff link=#5000A0>\n"
        << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Fiche Technique ")
        <<"<br>"
         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

     out << "<thead><tr bgcolor=#f0f0f0>";
     for (int column = 0; column < columnCount; column++)
         if (!tab_av.isColumnHidden(column))
             out << QString("<th>%1</th>").arg(tab_av.model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     for (int row = 0; row < rowCount; row++) {
         out << "<tr>";
         for (int column = 0; column < columnCount; column++) {
             if (!tab_av.isColumnHidden(column)) {
                 QString data = tab_av.model()->data(tab_av.model()->index(row, column)).toString().simplified();
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

ui->lineEdit_ID_AVION_4->clear();
N.notification_pdf();
}



void personnel::on_calendarWidget_activated(const QDate &date)
{
 QString date_text=date.toString(Qt::ISODate);
 ui->tab_vol->setModel(a.affichervol(date_text));

}



void personnel::on_pushButton_9_clicked()
{
    QString etat1="1";
    QSqlQuery qury;
    int nbav=0;
    qury.prepare("SELECT * FROM AVIONS WHERE ETAT='"+etat1+"'" );

     if(qury.exec())
     {
         while (qury.next())
         {
             nbav++;
         }
     }

int nbvol=ui->tab_vol->model()->rowCount();
if(nbav>nbvol+2)
{
    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("On peut assurer les vols.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    N.notification_vol1();


}
else if (nbav<nbvol)
{
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("On ne peut pas assurer les vols.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    N.notification_vol3();

}
else
{
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("On peut assurer les vols mais avec risque.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    N.notification_vol2();

}
}



void personnel::on_pushButton_stat_clicked()
{

    QString etat0="0";
    QString etat1="1";
    QTableView tab_av;
   qreal av0=0,av1=0;
    QSqlQuery qury,query;
     qury.prepare("SELECT * FROM AVIONS WHERE ETAT='"+etat0+"'" );

      if(qury.exec())
      {
          while (qury.next())
          {
              av0++;
          }
      }
      query.prepare("SELECT * FROM AVIONS WHERE ETAT='"+etat1+"'" );
      if(query.exec())
      {
          while (query.next())
          {
              av1++;
          }
      }

qreal pourcentage0=(av0/(av0+av1)*100);
qreal pourcentage1=(av1/(av0+av1)*100);


    // Define slices and percentage of whole they take up
     QPieSeries *series = new QPieSeries();
     series->append("etat critique",pourcentage0);
     series->append("bon etat",pourcentage1);
   /*  series->append("Fruits",.15);
     series->append("Seeds/Nuts",.10);
     series->append("Whole Grains",.15);*/

     QPieSlice *slice0 = series->slices().at(0);
     slice0->setExploded();
     slice0->setLabelVisible();
     slice0->setPen(QPen(Qt::darkRed, 2));
     slice0->setBrush(Qt::red);
     QPieSlice *slice1 = series->slices().at(1);
     slice1->setExploded();
     slice1->setLabelVisible();
     slice1->setPen(QPen(Qt::darkGreen, 2));
     slice1->setBrush(Qt::green);

     // Add labels to rest of slices
    /* QPieSlice *slice2 = series->slices().at(2);
     slice2->setLabelVisible();
     QPieSlice *slice3 = series->slices().at(3);
     slice3->setLabelVisible();
     QPieSlice *slice4 = series->slices().at(4);
     slice4->setLabelVisible();*/

     // Create the chart widget
     QChart *chart = new QChart();

     // Add data to chart with title and hide legend
     chart->addSeries(series);
     chart->setTitle("L'état actuel de nos avions");
     chart->legend()->hide();
      chart->setAnimationOptions(QChart::AllAnimations);

     // Used to display the chart
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     // Create the main app window
     //QMainWindow window;

     // Set the main window widget
   //  window.setCentralWidget(chartView);
   //  window.resize(420, 300);
   //  window.show();

     QGridLayout *layout = new QGridLayout();
     layout->addWidget(chartView);
     ui->statistique->setLayout(layout);

}

void personnel::on_send_clicked()
{
  QTextStream T(msocket);
  T << ui->nickname->text() << ":" << ui->message->text();
  msocket->flush();
  ui->message->clear();
}

void personnel::on_bind_clicked()
{
  MessengerConnection D(this);
  if (D.exec() == QDialog::Rejected){
      return;
  }
  msocket->connectToHost(D.hostname(),D.port());
}

void personnel::on_pushButton_10_clicked()
{
    blocknotee =new blocknote(this);
    blocknotee->show();
}

void personnel::update_label()
{
data=A.read_from_arduino();
QByteArray text=QByteArray::fromHex(data);
QSqlQuery query;
QString ard=ui->lineEdit_ID_AVION_5->text();
serialBuffer +=QString::fromStdString(data.toStdString());

query.prepare("UPDATE AVIONS SET ETAT='"+serialBuffer+"' WHERE ID_AVION=:ID_AVION");
query.bindValue(":ID_AVION",ard);

 if(query.exec())
  {
    N.notification_modifierAvion();

}
}

void personnel::on_pushButton_11_clicked()
{
    QString ard=ui->lineEdit_ID_AVION_5->text();
    QSqlQuery q;
     QString etatactuel;
    if(q.exec("select * from AVIONS where ID_AVION='"+ard+"'"))
    {

        while(q.next())

        etatactuel=q.value(3).toString();
    if (etatactuel=="1")
    {

        A.write_to_arduino("1");

    }
    else     {
        A.write_to_arduino("0");


    }
    }



}
