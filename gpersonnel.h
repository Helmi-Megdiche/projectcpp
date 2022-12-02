#ifndef GPERSONNEL_H
#define GPERSONNEL_H

#include <QDialog>

#include "personnel.h"
#include <QObject>
#include <QDate>
#include <QApplication>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPrinter>
#include <QPrintDialog>
#include "arduino.h"
#include "ard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gpersonnel; }
QT_END_NAMESPACE

class gpersonnel : public QDialog
{
    Q_OBJECT

public:
    gpersonnel(QWidget *parent = nullptr);
    ~gpersonnel();

private:
    Ui::gpersonnel *ui;
    personnel a;
    ard a1;
    QString serialBuffer;
    QByteArray data;
    arduino A;
private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_clicked();
    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
    void on_linecomboBox_currentIndexChanged(const QString &x); //TRIER COMBOBOX
    void on_rechercher_textChanged(const QString &arg1);
    void on_pushButton_pdf_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_STSAT_clicked();
    void on_pushButton_7_clicked();
    void on_pb_supp1_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_mail_clicked();
    void on_ajout_arduino_clicked();

        void on_effacer_arduino_clicked();

        void on_modifier_arduino_clicked();

        void update_label();
        void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H

