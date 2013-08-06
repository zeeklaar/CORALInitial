/*
    Author: Arsen Tufankjian
    Creation Date: June 10, 2013

    Changelog:

*/

#ifndef YOUTUBETHUMBNAIL_H
#define YOUTUBETHUMBNAIL_H

#include "thumbnail.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>

class YoutubeThumbnail : public Thumbnail
{
    Q_OBJECT

public:
    YoutubeThumbnail(QString Title, QString Description, QPixmap Image, QString URL);

    void createThumbnailUI(QWidget* parent);

private:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked(QString url);

};

#endif // YOUTUBETHUMBNAIL_H
