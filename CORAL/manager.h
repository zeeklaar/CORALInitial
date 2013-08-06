/*
    Author: Arsen Tufankjian
    Creation Date: June 7, 2013

    Changelog:

*/

#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QDebug>

class MainWindow; //Forward Declaration

class Manager : public QObject
{
    Q_OBJECT //Macro to make sure connections don't go to the QObject Class

public:
    explicit Manager(MainWindow* mainWin);

protected:
    MainWindow* mainWindow;
};

#endif // MANAGER_H
