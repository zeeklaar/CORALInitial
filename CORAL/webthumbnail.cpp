#include "webthumbnail.h"

WebThumbnail::WebThumbnail(QString Title, QPixmap Image, QString URL, QString Restriction) : Thumbnail(Thumbnail::Web,Title, "", Image, URL)
{
    //Need to store restriction level here
    restriction = Restriction;
}

/*
    Public Methods
*/

void WebThumbnail::createThumbnailUI(QWidget* parent)
{
    //Setup palettes
    QColor currentColor = palette().color(QPalette::Background);

    hoverPalette.setBrush(QPalette::Background, QColor(currentColor.red() - 20, currentColor.green() - 20, currentColor.blue() - 20)); // A Darker of the original
    regularPalette.setBrush(QPalette::Background, currentColor);

    QLabel* titleLabel = new QLabel(this);
    QLabel* imageLabel = new QLabel(this);

    //Title Label setup
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setFamily("Roboto");

    titleLabel->setFont(titleFont);
    titleLabel->setWordWrap(true);

    titleLabel->setText(title);
    imageLabel->setPixmap(image);

    setLayout(new QGridLayout(parent));

    setMaximumSize(320,320);

    layout()->addWidget(imageLabel);
    layout()->addWidget(titleLabel);

    setMouseTracking(true); //So we can see if the mouse enters the frame
    this->setAutoFillBackground(true);
}

QString WebThumbnail::getRestriction()
{
    return restriction;
}

/*
    Private Functions
*/

void WebThumbnail::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(content, restriction);
    }
}
