/*
    Author: Arsen Tufankjian
    Creation Date: June 10, 2013

    Changelog:

        June 11:
            Added the functions to manage a PDFManager
        June 12:
            Added the ability to manage WebManager
        June 13:
            Started the ability for Grouped Thumbnails to be functional
        June 14:
            Grouped Thumbnails are working with GroupManager
*/

#ifndef ACTIVITYTABMANAGER_H
#define ACTIVITYTABMANAGER_H

#include "thumbnail.h"
#include "manager.h"
#include "pdftabmanager.h"
#include "webtabmanager.h"
#include "groupmanager.h"

#include <QWebView>

class ActivityTabManager : public Manager
{
    Q_OBJECT

public:
    ActivityTabManager(MainWindow* mainWin);

    void setVideoActivity(QString youtubeURL);
    void setPDFActivity(QString pdfFilePath);
    void setWebActivity(QString url, QString restriction);
    void setGroupedActivity(QVector<Thumbnail*> thumbnails);

private:
    void clearWidgets();
};

#endif // ACTIVITYTABMANAGER_H
