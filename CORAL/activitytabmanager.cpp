#include "activitytabmanager.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

ActivityTabManager::ActivityTabManager(MainWindow* mainWin) : Manager(mainWin)
{
}

/*
    Public Functions
*/

void ActivityTabManager::setVideoActivity(QString youtubeURL)
{
    //Make sure to clear all widgets so that we can add new ones
    clearWidgets();

    if(youtubeURL != "about::blank"){ //Make sure the URL isn't 'blank'
        QWebView* videoView = new QWebView();
        videoView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
        videoView->setUrl(youtubeURL);

        mainWindow->ui->ActivityTabFrame->layout()->addWidget(videoView);

        //Set the focus to the activity tab
        mainWindow->ui->tabPane->setCurrentIndex(1);
    }
}

void ActivityTabManager::setPDFActivity(QString pdfFilePath)
{
    clearWidgets();

    PDFTabManager* PDFManager = new PDFTabManager(mainWindow);
    PDFManager->setupConnections();

    PDFManager->openPDF(pdfFilePath);

    //Set the focus to the activity tab
    mainWindow->ui->tabPane->setCurrentIndex(1);
}

void ActivityTabManager::setWebActivity(QString url, QString restriction)
{
    clearWidgets();

    if(url != "about::blank")
    {
        WebTabManager* webTab = new WebTabManager(mainWindow);
        webTab->setupManager(url, restriction);
    }
}

void ActivityTabManager::setGroupedActivity(QVector<Thumbnail*> thumbnails)
{
    clearWidgets();

    GroupManager* groupManager = new GroupManager(mainWindow, thumbnails);
    groupManager->setupManager();

    //Set the focus to the activity tab
    mainWindow->ui->tabPane->setCurrentIndex(1);
}


/*
    Private Functions
*/

void ActivityTabManager::clearWidgets()
{
    QFrame* toClear = mainWindow->ui->ActivityTabFrame;

    //Delete all existing widgets if any exist
    if(toClear->layout() != NULL)
    {
        QLayoutItem* item;
        while( (item = toClear->layout()->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }
    }
}
