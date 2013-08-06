/*
    Author: Arsen Tufankjian
    Creation Date: June 10, 2013

    Changelog:

*/

#ifndef JSONDATAHANDLER_H
#define JSONDATAHANDLER_H

#include "parser.h"

#include <QObject>
#include <QEventLoop>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>

class JsonDataHandler : public QObject
{
    Q_OBJECT

public:
    JsonDataHandler();
    virtual ~JsonDataHandler();

    void retrieveYoutubeData(QString apiURL);

    QString getTitle();
    QString getDescription();
    QPixmap getImage();

private:
    QNetworkAccessManager* jsonNetworkManager;
    QNetworkAccessManager* imageNetworkManager;

    QString title;
    QString description;
    QPixmap image;

signals:
    void dataGathered();

private slots:
    void imageReplyFinished(QNetworkReply* reply);
    void jsonReplyFinished(QNetworkReply* reply);
};

#endif // JSONDATAHANDLER_H
