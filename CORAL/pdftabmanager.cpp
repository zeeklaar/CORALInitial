/*
    Author: Arsen Tufankjian
    Creation Date: June 3, 2013

    Changelog:

        June 7:
            Now an extension of the Manager class
*/


#include "pdftabmanager.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

PDFTabManager::PDFTabManager(MainWindow* mainWin) : Manager(mainWin)
{
    //Initialize basic PDF values
    pdfScale = 1.0f;
    pdfPage = 0;

    currentPDF = NULL;

    //Create the main UI Frame
    PDFFrame = new QFrame();
    PDFFrame->setLayout(new QVBoxLayout());

    PDFWebView = new QWebView(PDFFrame);
    PDFWebView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    PDFWebView->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);

    //Setup control area
    ControlFrame = new QFrame(PDFFrame);
    ControlFrame->setMaximumHeight(70);
    ControlFrame->setLayout(new QHBoxLayout(ControlFrame));

    QFrame* spaceLayoutFrame = new QFrame(ControlFrame);
    spaceLayoutFrame->setLayout(new QHBoxLayout(ControlFrame));

    zoomInButton = new QPushButton("Zoom In", ControlFrame);
    zoomOutButton = new QPushButton("Zoom Out", ControlFrame);
    nextPageButton = new QPushButton("Next Page", ControlFrame);
    prevPageButton = new QPushButton("Prev Page", ControlFrame);

    spaceLayoutFrame->layout()->addWidget(zoomInButton);
    spaceLayoutFrame->layout()->addWidget(zoomOutButton);
    spaceLayoutFrame->layout()->addItem(new QSpacerItem(100, 50));
    spaceLayoutFrame->layout()->addWidget(nextPageButton);
    spaceLayoutFrame->layout()->addWidget(prevPageButton);

    ControlFrame->layout()->addWidget(spaceLayoutFrame);
    ControlFrame->layout()->addItem(new QSpacerItem(200,50, QSizePolicy::Expanding, QSizePolicy::Minimum));

    //Setup scroll area
    pdfScrollArea = new QScrollArea(mainWindow);
    pdfScrollArea->setAlignment(Qt::AlignCenter);
    pdfDisplay = new QLabel;

    pdfScrollArea->setWidget(pdfDisplay);

    PDFFrame->setLayout(new QGridLayout(mainWindow));
    PDFFrame->layout()->addWidget(PDFWebView);

    mainWindow->ui->ActivityTabFrame->layout()->addWidget(PDFFrame);
}

/*
    Public Functions
*/

void PDFTabManager::setupConnections()
{
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomInPDF()));
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOutPDF()));
    connect(nextPageButton, SIGNAL(clicked()), this, SLOT(nextPDFPage()));
    connect(prevPageButton, SIGNAL(clicked()), this, SLOT(previousPDFPage()));
}

void PDFTabManager::setPDFImage()
{
    MuPDF::Page *page = currentPDF->page(pdfPage);
    QImage image = page->renderImage(pdfScale,pdfScale);

    pdfDisplay->setPixmap(QPixmap::fromImage(image));
    pdfDisplay->resize(image.size());
}

void PDFTabManager::openPDF(QString filename)
{
    PDFWebView->setUrl(QUrl::fromLocalFile(filename));
    PDFWebView->reload();
}

/*
    Public Slots
*/

void PDFTabManager::zoomInPDF()
{
    //So long as we've opened a PDF
    if(currentPDF){

        //Increase scale
        if(pdfScale < 10){
            pdfScale += .5f;
        }

        //Redisplay image
        setPDFImage();
    }
}

void PDFTabManager::zoomOutPDF()
{
    if(currentPDF){

        //Decrease scale
        if(pdfScale > 0){
            pdfScale -= .5f;
        }

        //Redisplay image
        setPDFImage();
    }
}

void PDFTabManager::nextPDFPage()
{
    if(currentPDF){
        if(pdfPage < currentPDF->numPages() - 1)
        {
            pdfPage++;

            setPDFImage();
        }
    }
}

void PDFTabManager::previousPDFPage()
{
    if(currentPDF){
        if(pdfPage > 0)
        {
            pdfPage--;

            setPDFImage();
        }
    }
}
