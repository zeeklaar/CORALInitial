#include "groupedthumbnail.h"

GroupedThumbnail::GroupedThumbnail(QString Title) : Thumbnail(Thumbnail::Grouped, Title, "", "")
{

}

/*
    Public Functions
*/

void GroupedThumbnail::AddThumbnail(Thumbnail::ThumbnailType Type, QPixmap Image, QString URL, QString Restriction)
{
    Thumbnail* newThumbnail;

    switch(Type)
    {
    case PDF:
        newThumbnail = new PDFThumbnail("", Image, URL);
        break;
    case Web:
        newThumbnail = new WebThumbnail("", Image, URL, Restriction);
        break;
    case Youtube:
        newThumbnail = new YoutubeThumbnail("", "", Image, URL);
        break;
    }

    thumbnails.append(newThumbnail);
}

void GroupedThumbnail::createThumbnailUI(QWidget* parent)
{
    QVector<QPixmap> images;

    //Create 4 blank images
    for(int i =0; i < 4; i++)
    {
        QPixmap newImage(0,0);
        images.append(newImage);
    }

    //If we have more than 4 images, only store the first 4, otherwise store as many as we can
    if(thumbnails.size() > 4)
    {
        for(int i = 0; i < 4; i++)
        {
            images[i] = thumbnails[i]->getImage();
        }
    }
    else
    {
        for(int i = 0; i < thumbnails.size(); i++)
        {
            images[i] = thumbnails[i]->getImage();
        }
    }

    //Setup a painter and draw 1-4 thumbnails
    QPixmap combinedImage(300,320);
    QPainter painter(&combinedImage);
    painter.drawPixmap(0,0,150,160,images[0]);
    painter.drawPixmap(150,0,150,160,images[1]);
    painter.drawPixmap(0,160,150,160,images[2]);
    painter.drawPixmap(150,160,150,160,images[3]);

    image = combinedImage;


    //Setup palettes
    QColor currentColor = palette().color(QPalette::Background);

    hoverPalette.setBrush(QPalette::Background, QColor(currentColor.red() - 20, currentColor.green() - 20, currentColor.blue() - 20)); // A Darker of the original
    regularPalette.setBrush(QPalette::Background, currentColor);

    QLabel* titleLabel = new QLabel(title, this);
    QLabel* imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);

    //Title Label setup
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setFamily("Roboto");

    titleLabel->setFont(titleFont);
    titleLabel->setWordWrap(true);

    setLayout(new QGridLayout(parent));

    setMaximumSize(320,320);

    layout()->addWidget(imageLabel);
    layout()->addWidget(titleLabel);

    setMouseTracking(true); //So we can see if the mouse enters the frame
    this->setAutoFillBackground(true);
}

QVector<Thumbnail*> GroupedThumbnail::getThumbnails()
{
    return thumbnails;
}


/*
    Private Functions
*/

void GroupedThumbnail::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(thumbnails);
    }
}

