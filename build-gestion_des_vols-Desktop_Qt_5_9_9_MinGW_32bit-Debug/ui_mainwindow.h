/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionajouter;
    QAction *actionafficher_3;
    QAction *actionrechercher_2;
    QAction *actionmap_2;
    QAction *actionQuitter;
    QAction *actionStatistique;
    QAction *actionPdf;
    QAction *actionChat_Bot;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *tab_widget;
    QWidget *afficher;
    QLabel *label;
    QPushButton *pb_ajouter;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *num;
    QLineEdit *id;
    QPushButton *pb_effacer;
    QLabel *backg;
    QPushButton *retour_1;
    QDateEdit *dateEdit;
    QComboBox *choisir;
    QLineEdit *depart;
    QLineEdit *arrivage;
    QWidget *tab_2;
    QLabel *label_7;
    QTableView *tab_vols;
    QPushButton *pushButton;
    QComboBox *linecomboBox;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *num_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *id_2;
    QPushButton *modifier;
    QPushButton *afficher_2;
    QLabel *backg_2;
    QPushButton *pb_supprimer;
    QPushButton *retour_2;
    QLabel *clock;
    QLabel *datetime;
    QDateEdit *dateEdit_2;
    QComboBox *choisir_2;
    QLineEdit *arrivage_2;
    QLineEdit *depart_2;
    QWidget *tab;
    QLabel *backg_4;
    QLineEdit *num_3;
    QLabel *label_14;
    QTableView *tab_recherche;
    QPushButton *retour_3;
    QLabel *clock_2;
    QLabel *datetime_2;
    QWidget *tab_3;
    QTextEdit *text_pdf;
    QPushButton *pushButton_pdf;
    QPushButton *retour_4;
    QLabel *backg_6;
    QWidget *tab_4;
    QLabel *backg_7;
    QPushButton *retour_13;
    QLabel *stat;
    QWidget *tab_5;
    QLabel *backg_8;
    QPushButton *retour_6;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLineEdit *lineEdit_Conversation;
    QTextEdit *textEdit;
    QPushButton *chat;
    QLineEdit *lineEdit_;
    QLineEdit *lineEdit_message;
    QWidget *tab_6;
    QLabel *backg_5;
    QPushButton *retour_7;
    QAxWidget *map;
    QWidget *tab_7;
    QLabel *label_15;
    QLineEdit *id_arduino;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *nom_arduino;
    QLineEdit *prenom_arduino;
    QPushButton *ajout_arduino;
    QPushButton *effacer_arduino;
    QPushButton *retour_arduino;
    QLabel *backg_9;
    QLabel *label_18;
    QLineEdit *solde_arduino;
    QPushButton *modifier_arduino;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuajouter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1067, 779);
        actionajouter = new QAction(MainWindow);
        actionajouter->setObjectName(QStringLiteral("actionajouter"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Bottons/ajouter.jfif"), QSize(), QIcon::Normal, QIcon::Off);
        actionajouter->setIcon(icon);
        actionafficher_3 = new QAction(MainWindow);
        actionafficher_3->setObjectName(QStringLiteral("actionafficher_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Bottons/Afficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionafficher_3->setIcon(icon1);
        actionrechercher_2 = new QAction(MainWindow);
        actionrechercher_2->setObjectName(QStringLiteral("actionrechercher_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Bottons/chercher.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionrechercher_2->setIcon(icon2);
        actionmap_2 = new QAction(MainWindow);
        actionmap_2->setObjectName(QStringLiteral("actionmap_2"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Bottons/map.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionmap_2->setIcon(icon3);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/Bottons/Retour.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon4);
        actionStatistique = new QAction(MainWindow);
        actionStatistique->setObjectName(QStringLiteral("actionStatistique"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/Bottons/stat.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionStatistique->setIcon(icon5);
        actionPdf = new QAction(MainWindow);
        actionPdf->setObjectName(QStringLiteral("actionPdf"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/Bottons/pdf.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPdf->setIcon(icon6);
        actionChat_Bot = new QAction(MainWindow);
        actionChat_Bot->setObjectName(QStringLiteral("actionChat_Bot"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/Bottons/chat.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionChat_Bot->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 1031, 711));
        groupBox->setStyleSheet(QStringLiteral("font: italic 16pt \"Nueva Std\";"));
        tab_widget = new QTabWidget(groupBox);
        tab_widget->setObjectName(QStringLiteral("tab_widget"));
        tab_widget->setGeometry(QRect(20, 20, 981, 561));
        tab_widget->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        tab_widget->setTabPosition(QTabWidget::North);
        tab_widget->setIconSize(QSize(16, 16));
        tab_widget->setElideMode(Qt::ElideLeft);
        tab_widget->setMovable(false);
        tab_widget->setTabBarAutoHide(true);
        afficher = new QWidget();
        afficher->setObjectName(QStringLiteral("afficher"));
        label = new QLabel(afficher);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 161, 41));
        pb_ajouter = new QPushButton(afficher);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(520, 340, 111, 41));
        pb_ajouter->setIcon(icon);
        label_2 = new QLabel(afficher);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 161, 41));
        label_3 = new QLabel(afficher);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 230, 181, 41));
        label_4 = new QLabel(afficher);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 170, 161, 41));
        label_5 = new QLabel(afficher);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 290, 161, 41));
        label_6 = new QLabel(afficher);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 350, 161, 41));
        num = new QLineEdit(afficher);
        num->setObjectName(QStringLiteral("num"));
        num->setGeometry(QRect(270, 50, 191, 31));
        id = new QLineEdit(afficher);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(270, 290, 191, 31));
        pb_effacer = new QPushButton(afficher);
        pb_effacer->setObjectName(QStringLiteral("pb_effacer"));
        pb_effacer->setGeometry(QRect(640, 340, 111, 41));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/Bottons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_effacer->setIcon(icon8);
        backg = new QLabel(afficher);
        backg->setObjectName(QStringLiteral("backg"));
        backg->setGeometry(QRect(0, 0, 971, 521));
        retour_1 = new QPushButton(afficher);
        retour_1->setObjectName(QStringLiteral("retour_1"));
        retour_1->setGeometry(QRect(760, 340, 110, 41));
        retour_1->setIcon(icon4);
        dateEdit = new QDateEdit(afficher);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(270, 340, 191, 41));
        choisir = new QComboBox(afficher);
        choisir->setObjectName(QStringLiteral("choisir"));
        choisir->setGeometry(QRect(270, 110, 191, 31));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        choisir->setFont(font);
        depart = new QLineEdit(afficher);
        depart->setObjectName(QStringLiteral("depart"));
        depart->setGeometry(QRect(270, 170, 191, 31));
        arrivage = new QLineEdit(afficher);
        arrivage->setObjectName(QStringLiteral("arrivage"));
        arrivage->setGeometry(QRect(270, 230, 191, 31));
        tab_widget->addTab(afficher, icon, QString());
        backg->raise();
        num->raise();
        pb_effacer->raise();
        label_2->raise();
        id->raise();
        label_3->raise();
        label->raise();
        pb_ajouter->raise();
        label_5->raise();
        label_6->raise();
        label_4->raise();
        retour_1->raise();
        dateEdit->raise();
        choisir->raise();
        depart->raise();
        arrivage->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 30, 101, 31));
        tab_vols = new QTableView(tab_2);
        tab_vols->setObjectName(QStringLiteral("tab_vols"));
        tab_vols->setGeometry(QRect(20, 70, 861, 201));
        tab_vols->setMaximumSize(QSize(861, 16777215));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(600, 450, 111, 41));
        pushButton->setIcon(icon8);
        linecomboBox = new QComboBox(tab_2);
        linecomboBox->setObjectName(QStringLiteral("linecomboBox"));
        linecomboBox->setGeometry(QRect(20, 450, 261, 41));
        linecomboBox->setFont(font);
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 290, 161, 41));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 370, 161, 41));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 330, 161, 41));
        num_2 = new QLineEdit(tab_2);
        num_2->setObjectName(QStringLiteral("num_2"));
        num_2->setGeometry(QRect(250, 290, 191, 31));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(460, 330, 161, 41));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(460, 370, 161, 41));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(460, 290, 181, 41));
        id_2 = new QLineEdit(tab_2);
        id_2->setObjectName(QStringLiteral("id_2"));
        id_2->setGeometry(QRect(680, 330, 191, 31));
        modifier = new QPushButton(tab_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(740, 410, 131, 41));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/Bottons/Modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon9);
        afficher_2 = new QPushButton(tab_2);
        afficher_2->setObjectName(QStringLiteral("afficher_2"));
        afficher_2->setGeometry(QRect(300, 450, 121, 41));
        afficher_2->setIcon(icon1);
        backg_2 = new QLabel(tab_2);
        backg_2->setObjectName(QStringLiteral("backg_2"));
        backg_2->setGeometry(QRect(0, 0, 971, 521));
        pb_supprimer = new QPushButton(tab_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(440, 450, 151, 41));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/Bottons/Supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_supprimer->setIcon(icon10);
        retour_2 = new QPushButton(tab_2);
        retour_2->setObjectName(QStringLiteral("retour_2"));
        retour_2->setGeometry(QRect(760, 450, 110, 41));
        retour_2->setIcon(icon4);
        clock = new QLabel(tab_2);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(270, 10, 291, 51));
        datetime = new QLabel(tab_2);
        datetime->setObjectName(QStringLiteral("datetime"));
        datetime->setGeometry(QRect(570, 10, 291, 51));
        dateEdit_2 = new QDateEdit(tab_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(680, 370, 191, 31));
        choisir_2 = new QComboBox(tab_2);
        choisir_2->setObjectName(QStringLiteral("choisir_2"));
        choisir_2->setGeometry(QRect(250, 330, 191, 31));
        choisir_2->setFont(font);
        arrivage_2 = new QLineEdit(tab_2);
        arrivage_2->setObjectName(QStringLiteral("arrivage_2"));
        arrivage_2->setGeometry(QRect(680, 290, 191, 31));
        depart_2 = new QLineEdit(tab_2);
        depart_2->setObjectName(QStringLiteral("depart_2"));
        depart_2->setGeometry(QRect(250, 370, 191, 31));
        tab_widget->addTab(tab_2, icon1, QString());
        backg_2->raise();
        label_7->raise();
        label_9->raise();
        linecomboBox->raise();
        num_2->raise();
        label_13->raise();
        id_2->raise();
        modifier->raise();
        label_8->raise();
        label_10->raise();
        tab_vols->raise();
        label_11->raise();
        pushButton->raise();
        afficher_2->raise();
        label_12->raise();
        pb_supprimer->raise();
        retour_2->raise();
        clock->raise();
        datetime->raise();
        dateEdit_2->raise();
        choisir_2->raise();
        arrivage_2->raise();
        depart_2->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        backg_4 = new QLabel(tab);
        backg_4->setObjectName(QStringLiteral("backg_4"));
        backg_4->setGeometry(QRect(0, 0, 971, 521));
        num_3 = new QLineEdit(tab);
        num_3->setObjectName(QStringLiteral("num_3"));
        num_3->setGeometry(QRect(210, 30, 211, 31));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(80, 40, 121, 31));
        tab_recherche = new QTableView(tab);
        tab_recherche->setObjectName(QStringLiteral("tab_recherche"));
        tab_recherche->setGeometry(QRect(70, 130, 721, 311));
        retour_3 = new QPushButton(tab);
        retour_3->setObjectName(QStringLiteral("retour_3"));
        retour_3->setGeometry(QRect(850, 470, 110, 41));
        retour_3->setIcon(icon4);
        clock_2 = new QLabel(tab);
        clock_2->setObjectName(QStringLiteral("clock_2"));
        clock_2->setGeometry(QRect(500, 10, 291, 51));
        datetime_2 = new QLabel(tab);
        datetime_2->setObjectName(QStringLiteral("datetime_2"));
        datetime_2->setGeometry(QRect(500, 60, 291, 51));
        tab_widget->addTab(tab, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        text_pdf = new QTextEdit(tab_3);
        text_pdf->setObjectName(QStringLiteral("text_pdf"));
        text_pdf->setGeometry(QRect(220, 50, 671, 421));
        pushButton_pdf = new QPushButton(tab_3);
        pushButton_pdf->setObjectName(QStringLiteral("pushButton_pdf"));
        pushButton_pdf->setGeometry(QRect(10, 40, 110, 41));
        pushButton_pdf->setIcon(icon6);
        retour_4 = new QPushButton(tab_3);
        retour_4->setObjectName(QStringLiteral("retour_4"));
        retour_4->setGeometry(QRect(10, 470, 110, 41));
        retour_4->setIcon(icon4);
        backg_6 = new QLabel(tab_3);
        backg_6->setObjectName(QStringLiteral("backg_6"));
        backg_6->setGeometry(QRect(0, 0, 971, 521));
        tab_widget->addTab(tab_3, icon6, QString());
        backg_6->raise();
        text_pdf->raise();
        retour_4->raise();
        pushButton_pdf->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        backg_7 = new QLabel(tab_4);
        backg_7->setObjectName(QStringLiteral("backg_7"));
        backg_7->setGeometry(QRect(0, 0, 971, 521));
        retour_13 = new QPushButton(tab_4);
        retour_13->setObjectName(QStringLiteral("retour_13"));
        retour_13->setGeometry(QRect(850, 470, 110, 41));
        retour_13->setIcon(icon4);
        stat = new QLabel(tab_4);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(35, 25, 761, 471));
        tab_widget->addTab(tab_4, icon5, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        backg_8 = new QLabel(tab_5);
        backg_8->setObjectName(QStringLiteral("backg_8"));
        backg_8->setGeometry(QRect(0, 0, 971, 521));
        retour_6 = new QPushButton(tab_5);
        retour_6->setObjectName(QStringLiteral("retour_6"));
        retour_6->setGeometry(QRect(850, 470, 110, 41));
        retour_6->setIcon(icon4);
        line = new QFrame(tab_5);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 50, 20, 321));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(tab_5);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(60, 40, 661, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(tab_5);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(60, 360, 661, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(tab_5);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(710, 50, 20, 321));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        lineEdit_Conversation = new QLineEdit(tab_5);
        lineEdit_Conversation->setObjectName(QStringLiteral("lineEdit_Conversation"));
        lineEdit_Conversation->setGeometry(QRect(420, 190, 211, 31));
        textEdit = new QTextEdit(tab_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 100, 221, 87));
        chat = new QPushButton(tab_5);
        chat->setObjectName(QStringLiteral("chat"));
        chat->setGeometry(QRect(210, 270, 93, 28));
        lineEdit_ = new QLineEdit(tab_5);
        lineEdit_->setObjectName(QStringLiteral("lineEdit_"));
        lineEdit_->setGeometry(QRect(420, 90, 211, 31));
        lineEdit_message = new QLineEdit(tab_5);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));
        lineEdit_message->setGeometry(QRect(420, 140, 211, 31));
        tab_widget->addTab(tab_5, icon7, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        backg_5 = new QLabel(tab_6);
        backg_5->setObjectName(QStringLiteral("backg_5"));
        backg_5->setGeometry(QRect(0, 0, 971, 521));
        retour_7 = new QPushButton(tab_6);
        retour_7->setObjectName(QStringLiteral("retour_7"));
        retour_7->setGeometry(QRect(850, 470, 110, 41));
        retour_7->setIcon(icon4);
        map = new QAxWidget(tab_6);
        map->setControl(QStringLiteral("{8856f961-340a-11d0-a96b-00c04fd705a2}"));
        map->setObjectName(QStringLiteral("map"));
        map->setProperty("geometry", QVariant(QRect(0, 0, 841, 511)));
        tab_widget->addTab(tab_6, icon3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        label_15 = new QLabel(tab_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 90, 101, 20));
        id_arduino = new QLineEdit(tab_7);
        id_arduino->setObjectName(QStringLiteral("id_arduino"));
        id_arduino->setGeometry(QRect(240, 80, 241, 31));
        label_16 = new QLabel(tab_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(90, 150, 101, 20));
        label_17 = new QLabel(tab_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(90, 210, 101, 20));
        nom_arduino = new QLineEdit(tab_7);
        nom_arduino->setObjectName(QStringLiteral("nom_arduino"));
        nom_arduino->setGeometry(QRect(240, 140, 241, 31));
        prenom_arduino = new QLineEdit(tab_7);
        prenom_arduino->setObjectName(QStringLiteral("prenom_arduino"));
        prenom_arduino->setGeometry(QRect(240, 200, 241, 31));
        ajout_arduino = new QPushButton(tab_7);
        ajout_arduino->setObjectName(QStringLiteral("ajout_arduino"));
        ajout_arduino->setGeometry(QRect(630, 80, 111, 41));
        ajout_arduino->setIcon(icon);
        effacer_arduino = new QPushButton(tab_7);
        effacer_arduino->setObjectName(QStringLiteral("effacer_arduino"));
        effacer_arduino->setGeometry(QRect(630, 130, 111, 41));
        effacer_arduino->setIcon(icon8);
        retour_arduino = new QPushButton(tab_7);
        retour_arduino->setObjectName(QStringLiteral("retour_arduino"));
        retour_arduino->setGeometry(QRect(630, 180, 110, 41));
        retour_arduino->setIcon(icon4);
        backg_9 = new QLabel(tab_7);
        backg_9->setObjectName(QStringLiteral("backg_9"));
        backg_9->setGeometry(QRect(0, 0, 971, 521));
        label_18 = new QLabel(tab_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(90, 260, 131, 16));
        solde_arduino = new QLineEdit(tab_7);
        solde_arduino->setObjectName(QStringLiteral("solde_arduino"));
        solde_arduino->setGeometry(QRect(240, 251, 241, 31));
        modifier_arduino = new QPushButton(tab_7);
        modifier_arduino->setObjectName(QStringLiteral("modifier_arduino"));
        modifier_arduino->setGeometry(QRect(630, 230, 111, 41));
        modifier_arduino->setIcon(icon9);
        tab_widget->addTab(tab_7, QString());
        backg_9->raise();
        ajout_arduino->raise();
        prenom_arduino->raise();
        nom_arduino->raise();
        id_arduino->raise();
        label_15->raise();
        label_16->raise();
        effacer_arduino->raise();
        retour_arduino->raise();
        label_17->raise();
        label_18->raise();
        solde_arduino->raise();
        modifier_arduino->raise();
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1067, 26));
        menuajouter = new QMenu(menubar);
        menuajouter->setObjectName(QStringLiteral("menuajouter"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuajouter->menuAction());
        menuajouter->addAction(actionajouter);
        menuajouter->addSeparator();
        menuajouter->addAction(actionafficher_3);
        menuajouter->addSeparator();
        menuajouter->addAction(actionrechercher_2);
        menuajouter->addSeparator();
        menuajouter->addAction(actionPdf);
        menuajouter->addSeparator();
        menuajouter->addAction(actionStatistique);
        menuajouter->addSeparator();
        menuajouter->addAction(actionChat_Bot);
        menuajouter->addSeparator();
        menuajouter->addAction(actionmap_2);
        menuajouter->addSeparator();
        menuajouter->addAction(actionQuitter);
        menuajouter->addSeparator();

        retranslateUi(MainWindow);

        tab_widget->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        actionafficher_3->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        actionrechercher_2->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        actionmap_2->setText(QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionStatistique->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        actionPdf->setText(QApplication::translate("MainWindow", "Pdf", Q_NULLPTR));
        actionChat_Bot->setText(QApplication::translate("MainWindow", "Chat_Bot", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "gestion des vols :", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Num du vol :", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Destination :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Temp_arrivage :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Temp_depart :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Id_pilote :", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Date du vol :", Q_NULLPTR));
        pb_effacer->setText(QApplication::translate("MainWindow", "effacer", Q_NULLPTR));
        backg->setText(QString());
        retour_1->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        choisir->clear();
        choisir->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "choisir :", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->paris", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->marocco", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->japan", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->algerie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->madagashkar", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->usa", Q_NULLPTR)
        );
        tab_widget->setTabText(tab_widget->indexOf(afficher), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "les vols :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "effacer", Q_NULLPTR));
        linecomboBox->clear();
        linecomboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Trier Par :", Q_NULLPTR)
         << QApplication::translate("MainWindow", "num (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "num (desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "id_pilote (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "id_pilote (desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "destination (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "destination (desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "temp_depart (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "temp_depart (desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "temp_arrivage (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "temp_arrivage (desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_vol (asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_vol (desc)", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "Num du vol :", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Temp_depart :", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Destination :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Id_pilote :", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Date du vol :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Temp_arrivage :", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        afficher_2->setText(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        backg_2->setText(QString());
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        retour_2->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        clock->setText(QString());
        datetime->setText(QString());
        choisir_2->clear();
        choisir_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "choisir :", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->paris", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->marocco", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->japan", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->algerie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->madagashkar", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tunis-->usa", Q_NULLPTR)
        );
        tab_widget->setTabText(tab_widget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        backg_4->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "Num_Vol :", Q_NULLPTR));
        retour_3->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        clock_2->setText(QString());
        datetime_2->setText(QString());
        tab_widget->setTabText(tab_widget->indexOf(tab), QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        pushButton_pdf->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        retour_4->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        backg_6->setText(QString());
        tab_widget->setTabText(tab_widget->indexOf(tab_3), QApplication::translate("MainWindow", "Pdf", Q_NULLPTR));
        backg_7->setText(QString());
        retour_13->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        stat->setText(QString());
        tab_widget->setTabText(tab_widget->indexOf(tab_4), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        backg_8->setText(QString());
        retour_6->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        chat->setText(QApplication::translate("MainWindow", "chat", Q_NULLPTR));
        tab_widget->setTabText(tab_widget->indexOf(tab_5), QApplication::translate("MainWindow", "Chat_Bot", Q_NULLPTR));
        backg_5->setText(QString());
        retour_7->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        tab_widget->setTabText(tab_widget->indexOf(tab_6), QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Id :", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Nom :", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Prenom :", Q_NULLPTR));
        ajout_arduino->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        effacer_arduino->setText(QApplication::translate("MainWindow", "effacer", Q_NULLPTR));
        retour_arduino->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        backg_9->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "solde :", Q_NULLPTR));
        modifier_arduino->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        tab_widget->setTabText(tab_widget->indexOf(tab_7), QApplication::translate("MainWindow", "arduino", Q_NULLPTR));
        menuajouter->setTitle(QApplication::translate("MainWindow", "vols :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
