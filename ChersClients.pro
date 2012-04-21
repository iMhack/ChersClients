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
    centralwidget.cpp \
    formpacientssheets.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    pacientscene.h \
    dialogtexteditor.h \
    centralwidget.h \
    formpacientssheets.h \
    database.h

RESOURCES += \
    data.qrc

FORMS += \
    dialogtexteditor.ui \
    formpacientssheets.ui
