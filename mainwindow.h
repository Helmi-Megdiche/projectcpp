#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "avions.h"
#include <QObject>
#include <QDate>
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
    AVIONS a;
private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_clicked();
    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
};
#endif // MAINWINDOW_H
