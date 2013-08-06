/*
    QT Doesn't initialy have a QFlowLayout as needed in the
    ContentTabManager class, so this is a custom layout object
    to fill that role. It's adapted from:
    https://qt-project.org/doc/qt-4.8/layouts-flowlayout.html
*/

#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include <QLayout>
#include <QStyle>
#include <QWidget>

class FlowLayout : public QLayout
{
    Q_OBJECT
public:
    FlowLayout(QWidget *parent = 0, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    FlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~FlowLayout();

    void addItem(QLayoutItem* item);
    int horizontalSpacing() const;
    int verticalSpacing() const;
    Qt::Orientations expandingDirections() const;
    bool hasHeightForWidth() const;
    int heightForWidth(int) const;
    int count() const;
    QLayoutItem* itemAt(int index) const;
    QSize minimumSize() const;
    void setGeometry(const QRect &rect);
    QSize sizeHint() const;
    QLayoutItem *takeAt(int index);

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm)const;

    QList<QLayoutItem* > itemList;
    int hSpace;
    int vSpace;
    
};

#endif // FLOWLAYOUT_H
