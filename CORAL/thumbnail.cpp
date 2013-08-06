#include "thumbnail.h"

Thumbnail::Thumbnail(ThumbnailType thumbType, QString Title, QString Description, QPixmap Image, QString Content)
{
    type = thumbType;

    title = Title;
    description = Description;
    image = Image;
    content = Content;
}
Thumbnail::Thumbnail(ThumbnailType thumbType, QString Title, QString Description, QString Content)
{
    type = thumbType;

    title = Title;
    description = Description;
    image = *(new QPixmap(0,0));
    content = Content;
}


/*
    Public Functions
*/
void Thumbnail::setImage(QPixmap newImage)
{
    image = newImage;
}

Thumbnail::ThumbnailType Thumbnail::getThumbnailType()
{
    return type;
}

QPixmap Thumbnail::getImage()
{
    return image;
}

QString Thumbnail::getContent()
{
    return content;
}

/*
    Protected Events
*/
void Thumbnail::mouseMoveEvent(QMouseEvent* event)
{
    if(event->x() > this->width() - 6 || event->x() < 4 || event->y() > this->height() - 6 || event->y() < 4)
    {
        setPalette(regularPalette);
    }else{
        setPalette(hoverPalette);
    }
}
