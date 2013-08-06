/*
    Author: Arsen Tufankjian
    Creation Date: June 3, 2013

    Changelog:

        June 7:
            Now an extension of the Manager class
*/


#ifndef PDFTABMANAGER_H
#define PDFTABMANAGER_H

#include "manager.h"

#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QDirIterator>
#include <QWebView>
#include <QWebFrame>

#include "mupdf-qt.h"

class MainWindow; //Forward Declaration

class PDFTabManager : public Manager
{
    Q_OBJECT //Macro to make sure connections don't go to the QObject Class

public:
    PDFTabManager(MainWindow* mainUI);

    void openPDF(QString filename);
    void setupConnections();

private:

    void setPDFImage();

    float pdfScale;
    float pdfPage;

    QWebView* PDFWebView;
    QFrame* PDFFrame;
    QFrame* ControlFrame;

    QPushButton* zoomInButton;
    QPushButton* zoomOutButton;
    QPushButton* nextPageButton;
    QPushButton* prevPageButton;

    QScrollArea *pdfScrollArea;
    MuPDF::Document *currentPDF;
    QLabel *pdfDisplay;

public slots:
    void zoomInPDF();
    void zoomOutPDF();
    void nextPDFPage();
    void previousPDFPage();
};

#endif // PDFTABMANAGER_H
