#-------------------------------------------------
#
# Project created by QtCreator 2017-08-12T20:16:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtsudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        sudokumatrix.cc\
        solver.cc

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
