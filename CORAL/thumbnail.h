#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <QMouseEvent>
#include <QFrame>
#include <QPalette>
#include <QRect>

class Thumbnail : public QFrame
{
    Q_OBJECT

public:
    enum ThumbnailType {PDF, Web, Youtube, Grouped};//Enum so we can tell which kind of thumbnail this is

    Thumbnail(ThumbnailType type, QString Title, QString Description, QPixmap Image, QString Content);
    Thumbnail(ThumbnailType thumbType, QString Title, QString Description, QString Content);

    virtual void createThumbnailUI(QWidget* parent){Q_UNUSED(parent)} //This method doesn't need to do anything until a higher class gets ahold of it

    ThumbnailType getThumbnailType();
    QPixmap getImage();
    QString getContent();

    void setImage(QPixmap newImage);

protected:
    QPalette hoverPalette;
    QPalette regularPalette;

    ThumbnailType type;
    QString title;
    QString description;
    QPixmap image;
    QString content; //The URL or Path to the content to display

    void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event){Q_UNUSED(event)}
};

#endif // THUMBNAIL_H
