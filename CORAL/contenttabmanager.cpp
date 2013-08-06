/*
    Author: Arsen Tufankjian
    Creation Date: June 7, 2013

    Changelog:
*/

#include "contenttabmanager.h"
#include "youtubethumbnail.h"
#include "pdfthumbnail.h"
#include "webthumbnail.h"
#include "groupedthumbnail.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

ContentTabManager::ContentTabManager(MainWindow* mainWin) : Manager(mainWin)
{
    //Set the layouts for the list frames
    mainWindow->ui->requiredListFrame->setLayout(new FlowLayout(mainWindow->ui->requiredListFrame));
    mainWindow->ui->optionalListFrame->setLayout(new FlowLayout(mainWindow->ui->optionalListFrame));

    offlineImage.load(QCoreApplication::applicationDirPath() + "/res/images/Offline.png");

    testInternetConnection();
    readContentJson(QCoreApplication::applicationDirPath()+ "/res/json/");
}

/*
    Private Functions
*/

QString ContentTabManager::getYoutubeID(QString url)
{
    int indexOfEquals = url.lastIndexOf("=");
    QString id = url.mid(indexOfEquals + 1);

    return id;
}

void ContentTabManager::testInternetConnection()
{
    MainWindow::SplashScreen->showMessage("Testing Internet Connection");

    QNetworkAccessManager* testManager = new QNetworkAccessManager();
    connect(testManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(testConnectionFinished(QNetworkReply*)));
    testManager->get(QNetworkRequest(QUrl("http://www.google.com")));

    QEventLoop loop;
    connect(testManager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    loop.exec();

}

//This will read a JSON file
void ContentTabManager::readContentJson(QString path)
{
    QString jsonPath = path + "/content.json";

    //If the content.json file does not exits, post an error and return
    if(!QFile::exists(jsonPath))
    {
        qDebug() << "MISSING CONTENT.JSON!";
        return;
    }

    //Get the json in QByteArray format for easy parsing
    QFile file;
    file.setFileName(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    MainWindow::SplashScreen->showMessage("Reading JSON");
    QByteArray jsonData = file.readAll();

    //Use QJson to parse the data into QVariant format
    QJson::Parser parser;
    bool ok;

    QVariantMap jsonObject = parser.parse(jsonData, &ok).toMap();

    //If 'ok' has been set to true, then we're all set to read and manipulate the json data
    if(ok)
    {
        QVariantMap required = jsonObject["required"].toMap();
        QVariantList requiredVideoList = required["videos"].toList();
        QVariantList requiredGroupList = required["groups"].toList();

        MainWindow::SplashScreen->showMessage("Loading Required Videos");
        //Load thumbnails for each required video
        foreach(QVariant v, requiredVideoList){
            addVideoThumbnail(v.toString());
        }

        MainWindow::SplashScreen->showMessage("Loading Required Grouped Content");
        //Load thumbnails for each required group
        foreach(QVariant v, requiredGroupList)
        {
            QVariantMap group = v.toMap();

            //search all of the nested lists, and if they're all empty, don't add the group
            QVariantList groupedVideoList = group["videos"].toList();
            QVariantList groupedDocumentList = group["documents"].toList();
            QVariantList groupedWebList = group["webpages"].toList();

            if(groupedVideoList.count() > 0 || groupedDocumentList.count() > 0 || groupedWebList.count() > 0)
            {
                QString title = group["title"].toString();

                addGroupThumbnail(title, group);
            }
        }

        QVariantMap optional = jsonObject["optional"].toMap();
        QVariantList optionalPDFList = optional["documents"].toList();
        QVariantList optionalWebList = optional["webpages"].toList();

        MainWindow::SplashScreen->showMessage("Loading Optional Documents");
        //Load thumbnails for each optional PDF
        foreach(QVariant v, optionalPDFList)
        {
            QString basePath = QApplication::applicationDirPath() + "/res/doc/";
            addPDFThumbnail(basePath + v.toString());
        }

        MainWindow::SplashScreen->showMessage("Loading Optional Web Content");
        //Load thumbnails for each optional webpage
        foreach(QVariant v, optionalWebList)
        {
            QVariantMap webObject = v.toMap();

            QString url = webObject["url"].toString();
            QString title = webObject["title"].toString();
            QString restriction = webObject["restriction"].toString();

            addWebThumbnail(url, title, restriction);
        }

    }else
    {
        qDebug() << "Error parsing content.json!";
    }
}

/*
    Private Slots
*/

void ContentTabManager::testConnectionFinished(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        connectedToInternet = true;
    }
    else
    {
        connectedToInternet = false;
    }
}

//This will end up running two network queries before creating the thumbnail object
void ContentTabManager::addVideoThumbnail(QString videoURL)
{
    //Only do this if we're either connected to the internet, or if we've never checked
    if(connectedToInternet){
        QString videoID = getYoutubeID(videoURL);
        QString apiURL = "https://gdata.youtube.com/feeds/api/videos?q="+videoID+"&max-results=1&v=2&alt=jsonc";
        QString fullscreenURL = "https://www.youtube.com/embed/" + videoID ;

        JsonDataHandler* jsonHandler = new JsonDataHandler();
        jsonHandler->retrieveYoutubeData(apiURL);

        //Run this loop to make sure that the json handler has collected the data before the data is accessed
        QEventLoop loop;
        connect(jsonHandler, SIGNAL(dataGathered()), &loop, SLOT(quit()));
        loop.exec();

        YoutubeThumbnail* ytThumbnail = new YoutubeThumbnail(jsonHandler->getTitle(), jsonHandler->getDescription(), jsonHandler->getImage(), fullscreenURL);
        ytThumbnail->createThumbnailUI(mainWindow->ui->ActivityTabFrame);


        mainWindow->ui->requiredListFrame->layout()->addWidget(ytThumbnail);

        //Connect thumbnail signals
        connect(ytThumbnail, SIGNAL(clicked(QString)), this, SLOT(setupVideo(QString)));
    }
    else
    {
        //If there is no internet connection, create a thumbnail that has no effect when clicked and has a generic image

        YoutubeThumbnail* ytThumbnail = new YoutubeThumbnail("Title Unavailable", "Description Unavailable", offlineImage, "about::blank");
        ytThumbnail->createThumbnailUI(mainWindow->ui->ActivityTabFrame);


        mainWindow->ui->requiredListFrame->layout()->addWidget(ytThumbnail);

        //Connect thumbnail signals
        connect(ytThumbnail, SIGNAL(clicked(QString)), this, SLOT(setupVideo(QString)));
    }
}

//This will open up the PDF really quickly to get its title, a picture and other metadata
void ContentTabManager::addPDFThumbnail(QString PDFPath)
{
    //Failsafe to make sure this doesn't crash
    if(PDFPath.contains(".pdf")){
        MuPDF::Document* pdfDoc = MuPDF::loadDocument(PDFPath);
        MuPDF::Page* pdfPage = pdfDoc->page(0);

        QString title = pdfDoc->title();
        QImage image = pdfPage->renderImage(1.0f, 1.0f);
        QPixmap pixImage = QPixmap::fromImage(image);

        PDFThumbnail* pdfThumbnail = new PDFThumbnail(title, pixImage, PDFPath);
        pdfThumbnail->createThumbnailUI(mainWindow->ui->ActivityTabFrame);

        mainWindow->ui->optionalListFrame->layout()->addWidget(pdfThumbnail);

        //Connect signals
        connect(pdfThumbnail, SIGNAL(clicked(QString)), this, SLOT(setupPDF(QString)));
    }
}

//This will take a screenshot of the website before creating the thumbnail object
void ContentTabManager::addWebThumbnail(QString url, QString title, QString restriction)
{
    QPixmap screenshot;

    QWebView* testWebView = new QWebView();
    testWebView->setUrl(url);

    QPainter painter;
    QImage image(testWebView->page()->viewportSize(), QImage::Format_ARGB32);

    painter.begin(&image);
    testWebView->render(&painter);
    painter.end();

    screenshot = QPixmap::fromImage(image);

    WebThumbnail* webThumbnail = new WebThumbnail(title, screenshot, url, restriction);
    webThumbnail->createThumbnailUI(mainWindow->ui->ActivityTabFrame);

    mainWindow->ui->optionalListFrame->layout()->addWidget(webThumbnail);

    //Connect signal
    connect(webThumbnail, SIGNAL(clicked(QString,QString)), this, SLOT(setupWeb(QString,QString)));
}

void ContentTabManager::addGroupThumbnail(QString Title, QVariantMap Group)
{
    GroupedThumbnail* groupThumbnail = new GroupedThumbnail(Title);

    QVariantList groupedVideoList = Group["videos"].toList();
    QVariantList groupedDocumentList = Group["documents"].toList();
    QVariantList groupedWebList = Group["webpages"].toList();

    //Similar to the addVideoThumbnail but we want to add it to the group
    foreach(QVariant v, groupedVideoList)
    {
        if(connectedToInternet){
            QString url = v.toString();

            QString videoID = getYoutubeID(url);
            QString apiURL = "https://gdata.youtube.com/feeds/api/videos?q="+videoID+"&max-results=1&v=2&alt=jsonc";
            QString fullscreenURL = "https://www.youtube.com/embed/" + videoID ;

            JsonDataHandler* jsonHandler = new JsonDataHandler();
            jsonHandler->retrieveYoutubeData(apiURL);

            //Run this loop to make sure that the json handler has collected the data before the data is accessed
            QEventLoop loop;
            connect(jsonHandler, SIGNAL(dataGathered()), &loop, SLOT(quit()));
            loop.exec();

            groupThumbnail->AddThumbnail(Thumbnail::Youtube, jsonHandler->getImage(), fullscreenURL, "");
        }
    }
    //Also similar to the addPDFThumbnail, but again, we're adding it to the group
    foreach(QVariant v, groupedDocumentList)
    {
        QString basePath = QApplication::applicationDirPath() + "/res/doc/";
        QString fullPath = basePath + v.toString();

        MuPDF::Document* pdfDoc = MuPDF::loadDocument(fullPath);
        MuPDF::Page* pdfPage = pdfDoc->page(0);

        QImage image = pdfPage->renderImage(1.0f, 1.0f);
        QPixmap pixImage = QPixmap::fromImage(image);

        groupThumbnail->AddThumbnail(Thumbnail::PDF, pixImage, fullPath, "");
    }
    foreach(QVariant v, groupedWebList)
    {
        QVariantMap webObject = v.toMap();

        QString url = webObject["url"].toString();
        QString restriction = webObject["restriction"].toString();

        groupThumbnail->AddThumbnail(Thumbnail::Web, *(new QPixmap(0,0)), url, restriction);
    }

    groupThumbnail->createThumbnailUI(mainWindow->ui->ActivityTabFrame);

    mainWindow->ui->requiredListFrame->layout()->addWidget(groupThumbnail);

    connect(groupThumbnail, SIGNAL(clicked(QVector<Thumbnail*>)), this, SLOT(setupGroup(QVector<Thumbnail*>)));
}

/*
    Private Slots
*/

void ContentTabManager::setupVideo(QString videoURL)
{
    mainWindow->ActivityManager->setVideoActivity(videoURL);
}

void ContentTabManager::setupPDF(QString PDFPath)
{
    mainWindow->ActivityManager->setPDFActivity(PDFPath);
}

void ContentTabManager::setupWeb(QString url, QString restriction)
{
    mainWindow->ActivityManager->setWebActivity(url, restriction);
}
void ContentTabManager::setupGroup(QVector<Thumbnail*> thumbnails)
{
    mainWindow->ActivityManager->setGroupedActivity(thumbnails);
}
