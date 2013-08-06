/*
    Author: Arsen Tufankjian
    Creation Date: June 10, 2013

    Changelog:

*/


#include "jsondatahandler.h"

JsonDataHandler::JsonDataHandler()
{
    //Setup network managers
    imageNetworkManager = new QNetworkAccessManager(this);
    jsonNetworkManager = new QNetworkAccessManager(this);

    connect(imageNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imageReplyFinished(QNetworkReply*)));
    connect(jsonNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(jsonReplyFinished(QNetworkReply*)));
}
JsonDataHandler::~JsonDataHandler(){}

/*
    Public Functions
*/

void JsonDataHandler::retrieveYoutubeData(QString apiURL)
{
    jsonNetworkManager->get(QNetworkRequest(QUrl(apiURL)));
}

QString JsonDataHandler::getTitle()
{
    return title;
}
QString JsonDataHandler::getDescription()
{
    return description;
}
QPixmap JsonDataHandler::getImage()
{
    return image;
}
/*
    Private Slots
*/

void JsonDataHandler::jsonReplyFinished(QNetworkReply* reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error in " << reply->url() << " : " << reply->errorString();
        return;
    }


    QByteArray data = reply->readAll();

    QJson::Parser parser;

    bool ok;

    QVariantMap result = parser.parse(data, &ok).toMap();


    if(ok){
        QVariantMap data = result["data"].toMap();
        QVariantList items = data["items"].toList();
        QVariantMap itemsOne = items[0].toMap();

        //Parse JSON for title
        title = itemsOne["title"].toString();

        //Parse JSON for description
        description = itemsOne["description"].toString();

        //Parse JSON for Image URL
        QVariantMap thumbnails = itemsOne["thumbnail"].toMap();

        QString imageURL = thumbnails["hqDefault"].toString();

        imageNetworkManager->get(QNetworkRequest(QUrl(imageURL)));
    }
}

void JsonDataHandler::imageReplyFinished(QNetworkReply* reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error in " << reply->url() << " : " << reply->errorString();
        return;
    }

    QByteArray imgData = reply->readAll();
    QPixmap imagePixmap;
    imagePixmap.loadFromData(imgData);

    image = imagePixmap;

    emit dataGathered();
}

