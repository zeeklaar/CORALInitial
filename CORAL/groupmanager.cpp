#include "groupmanager.h"

#include "pdfthumbnail.h"
#include "webthumbnail.h"
#include "youtubethumbnail.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

GroupManager::GroupManager(MainWindow* mainWin, QVector<Thumbnail *> Thumbnails) : Manager(mainWin)
{
    activityIndex = 0;

    thumbnails = Thumbnails;
}

/*
    Public Functions
*/

void GroupManager::setupManager()
{
    //Setup the UI to go between activities
    ControlFrame = new QFrame(mainWindow->ui->ActivityTabFrame);

    finishButton = new QPushButton("Finish Activities");
    nextButton = new QPushButton("Next Activity", ControlFrame);
    prevButton = new QPushButton("Previous Activity", ControlFrame);

    ControlFrame->setMaximumHeight(50);

    ControlFrame->setLayout(new QHBoxLayout());

    ControlFrame->layout()->addWidget(prevButton);
    ControlFrame->layout()->addItem(new QSpacerItem(500,50, QSizePolicy::Expanding));
    ControlFrame->layout()->addWidget(nextButton);

    //Add the finish button but hide it
    ControlFrame->layout()->addWidget(finishButton);
    finishButton->hide();

    mainWindow->ui->ActivityTabFrame->layout()->addWidget(ControlFrame);

    //Load the first activity
    loadActivity(activityIndex);

    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextActivity()));
    connect(prevButton, SIGNAL(clicked()), this, SLOT(prevActivity()));
    connect(finishButton, SIGNAL(clicked()), this, SLOT(finishGroup()));
}

/*
    Private Functions
*/

//Load up the activity from the thumbnail
void GroupManager::loadActivity(int index)
{
    clearActivity();

    Thumbnail* activityThumbnail = thumbnails[index];

    //Each case will end up casting the generic thumbnail to the more specific one to gain access to specific functions
    switch(activityThumbnail->getThumbnailType())
    {
        case Thumbnail::PDF:
        {
            PDFThumbnail* pdfThumb = (PDFThumbnail*)activityThumbnail;

            PDFTabManager* pdfManager = new PDFTabManager(mainWindow);
            pdfManager->setupConnections();

            pdfManager->openPDF(pdfThumb->getContent());
            break;
        }
        case Thumbnail::Web:
        {
            WebThumbnail* webThumb = (WebThumbnail*)activityThumbnail;

            WebTabManager* webManager = new WebTabManager(mainWindow);
            webManager->setupManager(webThumb->getContent(), webThumb->getRestriction());

            break;
        }
        case Thumbnail::Youtube:
        {
            YoutubeThumbnail* youtubeThumb = (YoutubeThumbnail*)activityThumbnail;

            QWebView* videoView = new QWebView();
            videoView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
            videoView->setUrl(youtubeThumb->getContent());

            mainWindow->ui->ActivityTabFrame->layout()->addWidget(videoView);

            break;
        }
    }
}

//Just clear the widget housing the activity
void GroupManager::clearActivity()
{
    QFrame* toClear = mainWindow->ui->ActivityTabFrame;

    if(toClear->layout() != NULL)
    {
        QLayoutItem* item;
        while((item = toClear->layout()->takeAt(1)) != NULL)
        {
            delete item->widget();
            delete item;
        }
    }
}

/*
    Private Slots
*/

void GroupManager::nextActivity()
{
    if(activityIndex < thumbnails.size() -1){
        activityIndex++;
        loadActivity(activityIndex);
    }

    //If we get to the last index, then replace the "Next" button with the "Finish" Button
    if(activityIndex == thumbnails.size() -1 )
    {
        nextButton->hide();
        finishButton->show();
    }
}

void GroupManager::prevActivity()
{
    qDebug() << activityIndex << " : " << thumbnails.size();

    //If we're not on the last index, make sure that the finish button isn't there
    if(activityIndex <= thumbnails.size() )
    {
        qDebug() << "test";
        finishButton->hide();
        nextButton->show();
    }

    if(activityIndex > 0){
        activityIndex--;
        loadActivity(activityIndex);
    }
}

void GroupManager::finishGroup()
{
    //TODO: Run API calls to make sure the activity has been completed

    mainWindow->ui->tabPane->setCurrentIndex(0);
}
