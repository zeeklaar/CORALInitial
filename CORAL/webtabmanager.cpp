#include "webtabmanager.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

WebTabManager::WebTabManager(MainWindow* mainWin) : Manager(mainWin)
{
    webView = new QWebView();
    webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks); //Allows us to detect when links are pressed
}

/*
    public functions
*/

void WebTabManager::setupManager(QString url, QString restriction)
{
    this->url = url;

    webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    webView->setUrl(url);

    if(restriction == "page")
    {
        connect(webView, SIGNAL(linkClicked(QUrl)), this, SLOT(restrictPage(QUrl)));
    }
    else if(restriction == "domain")
    {
        connect(webView, SIGNAL(linkClicked(QUrl)), this, SLOT(restrictDomain(QUrl)));
    }

    mainWindow->ui->ActivityTabFrame->layout()->addWidget(webView);

    mainWindow->ui->tabPane->setCurrentIndex(1);
}


/*
    Private Slots
*/

void WebTabManager::restrictPage(QUrl newURL)
{
    Q_UNUSED(newURL)

    //The URL has changed, we don't want anything to happen
}

void WebTabManager::restrictDomain(QUrl newURL)
{
    int domainStart = url.lastIndexOf(':');

    QString domain = url.mid(domainStart + 3);

    int domainEnd = domain.lastIndexOf('.');

    domain = domain.mid(0, domainEnd + 4);

    //If the domain is in the new url, we can go to it
    if(newURL.toString().contains(domain))
    {
        webView->setUrl(newURL);
    }
}
