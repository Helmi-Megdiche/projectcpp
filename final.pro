QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += sql
QT+=printsupport
CONFIG += console
QT       += core gui charts
RC_ICONS = logo.ico
QT       += core gui network
QT += serialport
QT       += core  gui axcontainer
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ard.cpp \
    arduino.cpp \
    avions.cpp \
    blocknote.cpp \
    boutique.cpp \
    connect.cpp \
    gavions.cpp \
    gboutique.cpp \
    gpassager.cpp \
    gpersonnel.cpp \
    gvol.cpp \
    main.cpp \
    mainwindow.cpp \
    messengerconnection.cpp \
    notification.cpp \
    passager.cpp \
    personnel.cpp \
    smtp.cpp \
    vol.cpp \



HEADERS += \
    MessengerConnection.h \
    ard.h \
    arduino.h \
    avions.h \
    blocknote.h \
    boutique.h \
    connect.h \
    gavions.h \
    gboutique.h \
    gpassager.h \
    gpersonnel.h \
    gvol.h \
    mainwindow.h \
    map.h \
    notification.h \
    passager.h \
    personnel.h \
    smtp.h \
    vol.h \


FORMS += \
    blocknote.ui \
    gavions.ui \
    gboutique.ui \
    gpassager.ui \
    gpersonnel.ui \
    gvol.ui \
    mainwindow.ui \
    messengerconnection.ui \

QMAKE_CXXFLAGS +=-std=gnu++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    translations.qrc

DISTFILES += \
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
    Bottons/afficher.jfif \
    Bottons/ajouter.jfif \
    Bottons/chat.webp \
    Bottons/chercher.webp \
    Bottons/delete.png \
    Bottons/images.jfif \
    Bottons/map.jfif \
    Bottons/map.jpg \
    Bottons/map.webp \
    Bottons/pdf.jpg \
    Bottons/stat.jpg \
    backg&logo/backg.jfif \
    backg&logo/backg.jpg \
    backg&logo/logo1.png \
    backg&logo/logo2.png \
    logo.ico
