#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "vol.h"
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
    void on_afficher_2_clicked();
    void on_linecomboBox_activated(const QString &arg1);
    void on_actionafficher_3_triggered();
    void on_actionrechercher_2_triggered();
    void on_actionmap_2_triggered();
    void on_actionQuitter_clicked();
    void on_pb_effacer_clicked();
    void on_pushButton_clicked();
    void on_actionajouter_triggered();
    void on_num_3_textChanged(const QString &re);
    void on_pushButton_pdf_clicked();
    void on_retour_1_clicked();
    void on_retour_2_clicked();
    void on_retour_3_clicked();
    void on_retour_4_clicked();
    void on_retour_13_clicked();
    void on_retour_6_clicked();
    void on_retour_7_clicked();
    void on_actionStatistique_triggered();
    void on_actionPdf_triggered();
    void on_actionChat_Bot_triggered();
    void on_actionQuitter_triggered();
    void showTime ();
    void on_tab_vols_clicked(const QModelIndex &index);
    void getChat();
    void on_chat_clicked();




    void on_retour_arduino_clicked();

    void on_ajout_arduino_clicked();

    void on_effacer_arduino_clicked();

    void on_modifier_arduino_clicked();

    void update_label();


private:
    Ui::gvol *ui;
    vol v;
    ard a;
    Arduino A;
    QString ouvrir;
    QByteArray data;
    QString serialBuffer;
};

#endif // MAINWINDOW_H
