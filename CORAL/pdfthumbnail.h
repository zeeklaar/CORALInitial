/*
    Author: Arsen Tufankjian
    Creation Date: June 11, 2013

    Changelog:

*/

#ifndef PDFTHUMBNAIL_H
#define PDFTHUMBNAIL_H

#include "thumbnail.h"

#include <QGridLayout>
#include <QLabel>

class PDFThumbnail : public Thumbnail
{
    Q_OBJECT

public:
    PDFThumbnail(QString Title, QPixmap Image, QString FilePath);

    void createThumbnailUI(QWidget* parent);

private:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked(QString url);
};

#endif // PDFTHUMBNAIL_H
