/*
    Author: Arsen Tufankjian
    Creation Date: June 12, 2013

    Changelog:

*/

#ifndef WEBTABMANAGER_H
#define WEBTABMANAGER_H

#include "manager.h"

#include <QObject>
#include <QWebView>

class MainWindow; //Forward Declaration

class WebTabManager : public Manager
{
    Q_OBJECT

public:
    WebTabManager(MainWindow* mainWin);

    void setupManager(QString url, QString restriction);


private:
    QString url;
    QString restriction;

    QWebView* webView;

private slots:
    void restrictPage(QUrl url);
    void restrictDomain(QUrl url);
};

#endif // WEBTABMANAGER_H
