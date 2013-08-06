#include "pdfthumbnail.h"

PDFThumbnail::PDFThumbnail(QString Title, QPixmap Image, QString FilePath) : Thumbnail(Thumbnail::PDF, Title, "", Image, FilePath)
{    
}

/*
    Public Methods
*/

void PDFThumbnail::createThumbnailUI(QWidget* parent)
{
    //rescale the image
    image = image.scaled(300,250);

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



/*
    Private Functions
*/

void PDFThumbnail::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(content);
    }
}

