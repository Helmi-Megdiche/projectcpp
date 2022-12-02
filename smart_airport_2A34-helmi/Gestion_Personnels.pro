QT       += core gui
QT += core gui printsupport
QT+=sql
QT += core gui charts
QT += core gui charts network
QT += serialport
QT += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


QT +=sql

SOURCES += \
    arduino.cpp \
    connection.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp

HEADERS += \
    arduino.h \
    connection.h \
    mail.h \
    mainwindow.h \
    personnel.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Background/Backg.jpg \
    Bottons/Afficher.png \
    Bottons/Ajouter.png \
    Bottons/Annuler.png \
    Bottons/Enregistrer.png \
    Bottons/Modifier.png \
    Bottons/Pdf.png \
    Bottons/Rechercher.png \
    Bottons/Recommendation.png \
    Bottons/Retour.png \
    Bottons/Statistiques.png \
    Bottons/Supprimer.png \
    Bottons/imprimer.png \
    Logo/Logo.png \
    Logo/Logo1.png

RESOURCES += \
    Bottons/botons.qrc
