/*
    Author: Arsen Tufankjian
    Creation Date: June 14, 2013

    Changelog:

*/

#ifndef GROUPEDTHUMBNAIL_H
#define GROUPEDTHUMBNAIL_H

#include "thumbnail.h"
#include "pdfthumbnail.h"
#include "webthumbnail.h"
#include "youtubethumbnail.h"

#include <QPixmap>
#include <QPainter>
#include <QVector>

class GroupedThumbnail : public Thumbnail
{
    Q_OBJECT

public:
    GroupedThumbnail(QString Title);

    void AddThumbnail(Thumbnail::ThumbnailType Type, QPixmap Image, QString URL, QString Restriction);
    void createThumbnailUI(QWidget* parent);

    QVector<Thumbnail*> getThumbnails();

private:
    QVector<Thumbnail*> thumbnails;

    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked(QVector<Thumbnail*>);
};

#endif // GROUPEDTHUMBNAIL_H
