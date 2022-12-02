#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "avions.h"
#include <QObject>
#include <QDate>
#include <QCharRef>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList files;
    BOUTIQUE a;
    QSystemTrayIcon *mSystemTrayIcon;

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_clicked();
    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
    void on_pushButton_2_clicked();
    void on_modifier_2_clicked();
    void sendMail();
    void mailSent(QString);
   void browse();
   void on_sendBtn_clicked();
   void on_browseBtn_clicked();
};
#endif // MAINWINDOW_H
