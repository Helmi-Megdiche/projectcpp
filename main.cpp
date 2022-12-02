#include "mainwindow.h"
#include <QApplication>
#include<QTranslator>
#include <QInputDialog>
#include "gavions.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList Langues;
    Langues <<"Français" <<"Anglais";
    QString langue= QInputDialog::getItem(NULL,"choisir la langue",
                                          "Langue",Langues);
    if(langue=="Anglais")
    {
        t.load(":/english.qm");
    }
    if(langue!="Français")
    {
        a.installTranslator(&t);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
