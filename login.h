#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include "mainwindow.h"
#include "loginn.h"
#include "vol.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class login;
}

class login :
        public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_connexion_clicked();

    void on_inscrire_clicked();

   // void on_b_recuperation_clicked();

private:
    Ui::login *ui;
    loginn L;
    MainWindow *M;
};
#endif // LOGIN_H
