/*
    Author: Arsen Tufankjian
    Creation Date: May 28, 2013

    Changelog:

*/

#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow login;

    login.show();

    MainWindow::SplashScreen->finish(login.topLevelWidget());

    return a.exec();
}
