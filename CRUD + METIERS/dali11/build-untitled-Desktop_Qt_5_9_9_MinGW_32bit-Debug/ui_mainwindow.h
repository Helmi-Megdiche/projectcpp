/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_ID_AVION;
    QPushButton *pushButton_Ajouter;
    QGroupBox *lineEdit_DATEACHAT;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lej;
    QLineEdit *lean;
    QLineEdit *lem;
    QLabel *label_10;
    QLineEdit *lineEdit_TYPE;
    QLabel *label_12;
    QLineEdit *lineEdit_CAPACITE;
    QLabel *label_14;
    QLineEdit *lineEdit_ETAT;
    QPushButton *pushButton_Ajouter_2;
    QWidget *tab_2;
    QTableView *tab_av;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_ID_AVION_2;
    QLineEdit *lineEdit_etat;
    QPushButton *modifier;
    QLabel *label_11;
    QLineEdit *lineEdit_type;
    QLabel *label_13;
    QLineEdit *lineEdit_capacite;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *line_rech;
    QWidget *tab_3;
    QLabel *label_2;
    QLineEdit *lineEdit_ID_AVION_3;
    QPushButton *pb_supprimer;
    QWidget *tab_4;
    QCalendarWidget *calendarWidget;
    QWidget *tab_5;
    QWidget *tab_6;
    QPushButton *modifier_2;
    QLineEdit *lineEdit_ID_AVION_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_16;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QWidget *tab_7;
    QWidget *tab_8;
    QLineEdit *rcpt;
    QPushButton *sendBtn;
    QLineEdit *mail_pass;
    QPushButton *browseBtn;
    QLineEdit *subject;
    QTextEdit *msg;
    QLineEdit *file;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/myappico.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 30, 671, 411));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 231, 212);\n"
"font: 75 12pt \"Roman\";"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setMouseTracking(true);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 20, 511, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 101, 20));
        lineEdit_ID_AVION = new QLineEdit(groupBox);
        lineEdit_ID_AVION->setObjectName(QStringLiteral("lineEdit_ID_AVION"));
        lineEdit_ID_AVION->setEnabled(true);
        lineEdit_ID_AVION->setGeometry(QRect(130, 20, 113, 20));
        pushButton_Ajouter = new QPushButton(groupBox);
        pushButton_Ajouter->setObjectName(QStringLiteral("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(210, 170, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/aa.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Ajouter->setIcon(icon1);
        lineEdit_DATEACHAT = new QGroupBox(groupBox);
        lineEdit_DATEACHAT->setObjectName(QStringLiteral("lineEdit_DATEACHAT"));
        lineEdit_DATEACHAT->setGeometry(QRect(270, 20, 231, 111));
        label_3 = new QLabel(lineEdit_DATEACHAT);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 20, 81, 20));
        label_4 = new QLabel(lineEdit_DATEACHAT);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 50, 81, 20));
        label_5 = new QLabel(lineEdit_DATEACHAT);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 80, 81, 20));
        lej = new QLineEdit(lineEdit_DATEACHAT);
        lej->setObjectName(QStringLiteral("lej"));
        lej->setGeometry(QRect(130, 20, 51, 20));
        lean = new QLineEdit(lineEdit_DATEACHAT);
        lean->setObjectName(QStringLiteral("lean"));
        lean->setGeometry(QRect(130, 80, 51, 20));
        lean->setMouseTracking(false);
        lem = new QLineEdit(lineEdit_DATEACHAT);
        lem->setObjectName(QStringLiteral("lem"));
        lem->setGeometry(QRect(130, 50, 51, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 50, 71, 16));
        lineEdit_TYPE = new QLineEdit(groupBox);
        lineEdit_TYPE->setObjectName(QStringLiteral("lineEdit_TYPE"));
        lineEdit_TYPE->setGeometry(QRect(130, 50, 113, 20));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 80, 61, 21));
        lineEdit_CAPACITE = new QLineEdit(groupBox);
        lineEdit_CAPACITE->setObjectName(QStringLiteral("lineEdit_CAPACITE"));
        lineEdit_CAPACITE->setGeometry(QRect(130, 80, 113, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 110, 71, 21));
        lineEdit_ETAT = new QLineEdit(groupBox);
        lineEdit_ETAT->setObjectName(QStringLiteral("lineEdit_ETAT"));
        lineEdit_ETAT->setGeometry(QRect(130, 110, 113, 20));
        pushButton_Ajouter_2 = new QPushButton(groupBox);
        pushButton_Ajouter_2->setObjectName(QStringLiteral("pushButton_Ajouter_2"));
        pushButton_Ajouter_2->setGeometry(QRect(290, 170, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_av = new QTableView(tab_2);
        tab_av->setObjectName(QStringLiteral("tab_av"));
        tab_av->setGeometry(QRect(10, 20, 261, 171));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(290, 20, 101, 20));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 110, 71, 21));
        lineEdit_ID_AVION_2 = new QLineEdit(tab_2);
        lineEdit_ID_AVION_2->setObjectName(QStringLiteral("lineEdit_ID_AVION_2"));
        lineEdit_ID_AVION_2->setGeometry(QRect(410, 20, 113, 20));
        lineEdit_etat = new QLineEdit(tab_2);
        lineEdit_etat->setObjectName(QStringLiteral("lineEdit_etat"));
        lineEdit_etat->setGeometry(QRect(400, 110, 113, 20));
        modifier = new QPushButton(tab_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(250, 210, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("myappico.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon2);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(290, 50, 81, 16));
        lineEdit_type = new QLineEdit(tab_2);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(410, 50, 113, 20));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 80, 81, 20));
        lineEdit_capacite = new QLineEdit(tab_2);
        lineEdit_capacite->setObjectName(QStringLiteral("lineEdit_capacite"));
        lineEdit_capacite->setGeometry(QRect(410, 80, 113, 20));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 210, 75, 23));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 211, 81, 21));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 250, 75, 23));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 240, 271, 41));
        line_rech = new QLineEdit(tab_2);
        line_rech->setObjectName(QStringLiteral("line_rech"));
        line_rech->setGeometry(QRect(100, 250, 113, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 20));
        lineEdit_ID_AVION_3 = new QLineEdit(tab_3);
        lineEdit_ID_AVION_3->setObjectName(QStringLiteral("lineEdit_ID_AVION_3"));
        lineEdit_ID_AVION_3->setGeometry(QRect(140, 70, 113, 20));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(64, 130, 91, 31));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        calendarWidget = new QCalendarWidget(tab_4);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 20, 461, 251));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        modifier_2 = new QPushButton(tab_6);
        modifier_2->setObjectName(QStringLiteral("modifier_2"));
        modifier_2->setGeometry(QRect(270, 240, 91, 31));
        lineEdit_ID_AVION_4 = new QLineEdit(tab_6);
        lineEdit_ID_AVION_4->setObjectName(QStringLiteral("lineEdit_ID_AVION_4"));
        lineEdit_ID_AVION_4->setGeometry(QRect(150, 110, 113, 20));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 110, 111, 20));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 150, 111, 20));
        label_16 = new QLabel(tab_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 190, 111, 20));
        dateEdit = new QDateEdit(tab_6);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 150, 110, 22));
        dateEdit_2 = new QDateEdit(tab_6);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(150, 190, 110, 22));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        rcpt = new QLineEdit(tab_8);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(10, 20, 491, 21));
        sendBtn = new QPushButton(tab_8);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(20, 320, 431, 51));
        mail_pass = new QLineEdit(tab_8);
        mail_pass->setObjectName(QStringLiteral("mail_pass"));
        mail_pass->setGeometry(QRect(510, 20, 141, 20));
        mail_pass->setEchoMode(QLineEdit::Password);
        browseBtn = new QPushButton(tab_8);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(530, 70, 91, 21));
        subject = new QLineEdit(tab_8);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(10, 50, 651, 16));
        msg = new QTextEdit(tab_8);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(0, 110, 631, 201));
        file = new QLineEdit(tab_8);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(10, 70, 491, 23));
        tabWidget->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Ajouter_2, SIGNAL(clicked()), lineEdit_CAPACITE, SLOT(clear()));
        QObject::connect(pushButton_Ajouter_2, SIGNAL(clicked()), lineEdit_ID_AVION, SLOT(clear()));
        QObject::connect(pushButton_Ajouter_2, SIGNAL(clicked()), lineEdit_ETAT, SLOT(clear()));
        QObject::connect(pushButton_Ajouter_2, SIGNAL(clicked()), lineEdit_TYPE, SLOT(clear()));

        tabWidget->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Id boutique", Q_NULLPTR));
        pushButton_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        lineEdit_DATEACHAT->setTitle(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Jour", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Moins", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Annees", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "surface", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "date fin", Q_NULLPTR));
        pushButton_Ajouter_2->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter une boutique ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID boutique", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "date fin", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "surface", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "par ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date", Q_NULLPTR)
         << QApplication::translate("MainWindow", "etat", Q_NULLPTR)
         << QApplication::translate("MainWindow", "capacit\303\251", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Nombre des boutique pour cette ann\303\251e", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les boutiques", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ID boutique", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "supprimer boutiques", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Calendrier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "stat", Q_NULLPTR));
        modifier_2->setText(QApplication::translate("MainWindow", "IMPRIMER", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "ID boutique", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "DE", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Chifre d'affaire", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "TAXFREE", Q_NULLPTR));
        rcpt->setPlaceholderText(QApplication::translate("MainWindow", "recipient", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        mail_pass->setPlaceholderText(QApplication::translate("MainWindow", "your mail password", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("MainWindow", "Browse ...", Q_NULLPTR));
        subject->setPlaceholderText(QApplication::translate("MainWindow", "subject", Q_NULLPTR));
        msg->setPlaceholderText(QApplication::translate("MainWindow", "type your message here ...", Q_NULLPTR));
        file->setPlaceholderText(QApplication::translate("MainWindow", "attachement here", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
