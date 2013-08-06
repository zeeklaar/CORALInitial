#include "youtubethumbnail.h"

YoutubeThumbnail::YoutubeThumbnail(QString Title, QString Description, QPixmap Image, QString URL) : Thumbnail(Thumbnail::Youtube,Title, Description, Image, URL)
{    
}

/*
    Public Methods
*/

void YoutubeThumbnail::createThumbnailUI(QWidget* parent)
{
    //Setup palettes
    QColor currentColor = palette().color(QPalette::Background);

    hoverPalette.setBrush(QPalette::Background, QColor(currentColor.red() - 20, currentColor.green() - 20, currentColor.blue() - 20)); // A Darker of the original
    regularPalette.setBrush(QPalette::Background, currentColor);

    QLabel* titleLabel = new QLabel(this);
    QLabel* descriptionLabel = new QLabel(this);
    QLabel* imageLabel = new QLabel(this);

    //Title Label setup
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setFamily("Roboto");

    titleLabel->setFont(titleFont);
    titleLabel->setWordWrap(true);

    //Description Label Setup
    descriptionLabel->setWordWrap(true);

    titleLabel->setText(title);
    descriptionLabel->setText(description);
    imageLabel->setPixmap(image);

    setLayout(new QGridLayout(parent));

    setMaximumSize(320,320);

    layout()->addWidget(imageLabel);
    layout()->addWidget(titleLabel);
    layout()->addWidget(descriptionLabel);

    setMouseTracking(true); //So we can see if the mouse enters the frame
    this->setAutoFillBackground(true);
}

/*
    Private Functions
*/

void YoutubeThumbnail::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(content);
    }
}

