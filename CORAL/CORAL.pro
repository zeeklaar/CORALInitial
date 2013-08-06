#-------------------------------------------------
#
# Project created by QtCreator 2013-05-28T10:11:28
#
#-------------------------------------------------

QT       += core gui webkitwidgets multimedia network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CORAL
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    loginwindow.cpp \
    exitdialog.cpp \
    pdftabmanager.cpp \
    mediatabmanager.cpp \
    contenttabmanager.cpp \
    manager.cpp \
    jsondatahandler.cpp \
    youtubethumbnail.cpp \
    activitytabmanager.cpp \
    thumbnail.cpp \
    pdfthumbnail.cpp \
    webthumbnail.cpp \
    webtabmanager.cpp \
    groupedthumbnail.cpp \
    groupmanager.cpp \
    flowlayout.cpp

HEADERS  += mainwindow.h \
    loginwindow.h \
    exitdialog.h \
    pdftabmanager.h \
    mediatabmanager.h \
    contenttabmanager.h \
    manager.h \
    jsondatahandler.h \
    youtubethumbnail.h \
    activitytabmanager.h \
    thumbnail.h \
    pdfthumbnail.h \
    webthumbnail.h \
    webtabmanager.h \
    groupedthumbnail.h \
    groupmanager.h \
    flowlayout.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    exitdialog.ui

#Windows Libraries
win32:LIBS += -L$$_PRO_FILE_PWD_/mupdf-qt-dev/win32/lib -lmupdf-qt \
 -lfitz \
 -ljpeg \
 -ljbig2dec \
 -lopenjpeg \
 -lfreetype \
 -lz
win32:LIBS += -L$$_PRO_FILE_PWD_/libvlc-qt/win32/lib -lvlc-qt
win32:LIBS += -L$$_PRO_FILE_PWD_/qjson/win32/lib -lqjson


win32:INCLUDEPATH += $$_PRO_FILE_PWD_/mupdf-qt-dev/include
win32:INCLUDEPATH += $$_PRO_FILE_PWD_/libvlc-qt/include
win32:INCLUDEPATH += $$_PRO_FILE_PWD_/qjson/include


#Mac OS X Libraries
unix:LIBS += -L$$_PRO_FILE_PWD_/mupdf-qt-dev/macX/lib -lmupdf-qt \
 -lfitz \
 -ljpeg \
 -ljbig2dec \
 -lopenjpeg \
 -lfreetype \
 -lz
unix:LIBS += -L$$_PRO_FILE_PWD_/libvlc-qt/macX/lib -lvlc-qt
unix:LIBS += -L$$_PRO_FILE_PWD_/qjson/macX/lib -lqjson

unix:INCLUDEPATH += $$_PRO_FILE_PWD_/mupdf-qt-dev/include
unix:INCLUDEPATH += $$_PRO_FILE_PWD_/libvlc-qt/include
unix:INCLUDEPATH += $$_PRO_FILE_PWD_/qjson/include
