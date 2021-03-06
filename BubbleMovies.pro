#-------------------------------------------------
#
# Project created by QtCreator 2019-11-15T13:53:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BubbleMovies
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    source/datastructures/tst.cpp \
    source/model/movie.cpp \
    source/model/rating.cpp \
    source/model/tag.cpp \
    source/model/user.cpp \
    source/utils/intHC.cpp \
    source/utils/stringHashable.cpp \
    source/utils/utils.cpp \
    source/api.cpp \
    source/main.cpp \
    source/mainwindow.cpp

HEADERS += \
    header/datastructures/hash.h \
    header/datastructures/tst.h \
    header/interfaces/comparable.h \
    header/interfaces/hashable.h \
    header/model/movie.h \
    header/model/rating.h \
    header/model/tag.h \
    header/model/user.h \
    header/utils/intHC.h \
    header/utils/sort.h \
    header/utils/stringHashable.h \
    header/utils/utils.h \
    header/api.h \
    header/mainwindow.h

FORMS += \
        mainwindow.ui \
    mainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    BubbleMovies.pro \
    BubbleMovies.pro

DISTFILES += \
    icons/play-16.ico \
    source/datastructures/hash.ipp \
    source/utils/sort.ipp
