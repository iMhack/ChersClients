#-------------------------------------------------
#
# Project created by QtCreator 2012-04-20T17:07:29
#
#-------------------------------------------------

QT       += core gui

TARGET = ChersClients
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pacientscene.cpp \
    dialogtexteditor.cpp \
    formpacientssheets.cpp \
    database.cpp \
    formvbroverview.cpp

HEADERS  += mainwindow.h \
    pacientscene.h \
    dialogtexteditor.h \
    formpacientssheets.h \
    database.h \
    formvbroverview.h

RESOURCES += \
    data.qrc

FORMS += \
    dialogtexteditor.ui \
    formpacientssheets.ui \
    formvbroverview.ui
