/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *id;
    QLineEdit *mdp;
    QPushButton *connexion;
    QLabel *label_3;
    QPushButton *inscrire;
    QLineEdit *mail;
    QLineEdit *mdp_3;
    QLineEdit *id_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(945, 701);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 30, 781, 561));
        groupBox->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 16pt \"Tekton Pro Ext\";\n"
"font: 75 italic 16pt \"MS Serif\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 181, 51));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 360, 181, 51));
        id = new QLineEdit(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(210, 90, 221, 31));
        mdp = new QLineEdit(groupBox);
        mdp->setObjectName(QStringLiteral("mdp"));
        mdp->setGeometry(QRect(210, 160, 221, 31));
        connexion = new QPushButton(groupBox);
        connexion->setObjectName(QStringLiteral("connexion"));
        connexion->setGeometry(QRect(260, 220, 171, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(520, 270, 181, 51));
        inscrire = new QPushButton(groupBox);
        inscrire->setObjectName(QStringLiteral("inscrire"));
        inscrire->setGeometry(QRect(500, 480, 171, 41));
        mail = new QLineEdit(groupBox);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(480, 420, 221, 31));
        mdp_3 = new QLineEdit(groupBox);
        mdp_3->setObjectName(QStringLiteral("mdp_3"));
        mdp_3->setGeometry(QRect(480, 370, 221, 31));
        id_3 = new QLineEdit(groupBox);
        id_3->setObjectName(QStringLiteral("id_3"));
        id_3->setGeometry(QRect(480, 320, 221, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 310, 181, 51));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 150, 181, 51));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 410, 181, 51));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("login", "Login :", Q_NULLPTR));
        label->setText(QApplication::translate("login", "Username :", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "Password :", Q_NULLPTR));
        connexion->setText(QApplication::translate("login", "connexion", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "s'inscrire:", Q_NULLPTR));
        inscrire->setText(QApplication::translate("login", "s'inscrire", Q_NULLPTR));
        label_4->setText(QApplication::translate("login", "Username :", Q_NULLPTR));
        label_5->setText(QApplication::translate("login", "Password :", Q_NULLPTR));
        label_6->setText(QApplication::translate("login", "mail :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
