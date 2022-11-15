#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    personnel a;
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
    void on_pushButton_2_clicked();
    void on_pushButton_mail_clicked();
};
#endif // MAINWINDOW_H
