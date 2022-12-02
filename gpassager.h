#ifndef GPASSAGER_H
#define GPASSAGER_H
#include <QDialog>

#include "arduino.h"
#include"passager.h"
#include<QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class gpassager; }
QT_END_NAMESPACE

class gpassager: public QDialog
{
    Q_OBJECT

public:
    gpassager(QWidget *parent = nullptr);
    ~gpassager();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();



    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_pb_rech_clicked();

    void on_tab_passager_clicked(const QModelIndex &index);



    void on_pb_impri_clicked();

    void on_pushButton_clicked();

    void on_pb_web_clicked();

    void serial_read();

    void on_checkin_clicked();

    void on_arduino_ouvrir_clicked();

    void on_arduino_fermer_clicked();

private:
    Ui::gpassager *ui;
    Passager P;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();
    QByteArray data;
    QString serialBuffer;
    arduino A;
};
#endif // MAINWINDOW_H
