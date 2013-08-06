/*
    Author: Arsen Tufankjian
    Creation Date: June 14, 2013

    Changelog:

*/

#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include "manager.h"
#include "thumbnail.h"

#include <QPushButton>

class MainWindow; //Forward Declaration

class GroupManager : public Manager
{
    Q_OBJECT

public:
    GroupManager(MainWindow* mainWin, QVector<Thumbnail*> Thumbnails);

    void setupManager();

private:
    void loadActivity(int index);
    void clearActivity();

    QFrame* ControlFrame;

    QPushButton* nextButton;
    QPushButton* prevButton;
    QPushButton* finishButton;

    QVector<Thumbnail*> thumbnails;
    int activityIndex;

private slots:
    void nextActivity();
    void prevActivity();
    void finishGroup();

};

#endif // GROUPMANAGER_H
