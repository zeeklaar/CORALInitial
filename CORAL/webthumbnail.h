/*
    Author: Arsen Tufankjian
    Creation Date: June 12, 2013

    Changelog:

*/

#ifndef WEBTHUMBNAIL_H
#define WEBTHUMBNAIL_H

#include "thumbnail.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>

class WebThumbnail : public Thumbnail
{
    Q_OBJECT

public:
    WebThumbnail(QString Title, QPixmap Image, QString URL, QString Restriction);

    void createThumbnailUI(QWidget* parent);

    QString getRestriction();

private:
    QString restriction;

    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked(QString url, QString restriction);
};

#endif // WEBTHUMBNAIL_H
