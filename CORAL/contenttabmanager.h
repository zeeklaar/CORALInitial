/*
    Author: Arsen Tufankjian
    Creation Date: June 7, 2013

    Changelog:
        June 10:
            Added the ability for this class to parse youtube URLs and create YouTubeThumbnails
        June 11:
            Added the ability for this to parse PDFs and add PDFThumnails to the UI
        June 12:
            Added the ability for this to generate web thumbnails
        June 13:
            Added the ability for this to create thumbnails which house groups of activities
        June 14:
            Added the functions for the grouped content to be loaded appropriately
        June 19:
            Added a test for an internet connection
*/

#ifndef CONTENTTABMANAGER_H
#define CONTENTTABMANAGER_H

#include "manager.h"
#include "jsondatahandler.h"
#include "mupdf-qt.h"
#include "thumbnail.h"

#include "flowlayout.h"
#include "parser.h"

#include <QWidget>
#include <QFrame>
#include <QEventLoop>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>

class MainWindow; //Forward Declaration

class ContentTabManager : public Manager
{
    Q_OBJECT //Macro to make sure connections don't go to the QObject Class

public:
    explicit ContentTabManager(MainWindow* mainWin);

private:
    QString getYoutubeID(QString url);

    void testInternetConnection();
    void readContentJson(QString path);

    void addVideoThumbnail(QString videoURL);
    void addPDFThumbnail(QString PDFPath);
    void addWebThumbnail(QString url, QString title, QString restriction);
    void addGroupThumbnail(QString Title, QVariantMap Group);

    bool connectedToInternet;
    QPixmap offlineImage;

private slots:
    void testConnectionFinished(QNetworkReply* reply);

    void setupVideo(QString videoURL);
    void setupPDF(QString PDFPath);
    void setupWeb(QString url, QString restriction);
    void setupGroup(QVector<Thumbnail*> thumbnails);
};

#endif // CONTENTTABMANAGER_H
