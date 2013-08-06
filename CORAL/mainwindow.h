/*
    Author: Arsen Tufankjian
    Creation Date: May 28, 2013

    Changelog:

    May 30:
        Removed GLWIdget
        Added the ability to exit program with Exit Dialog
        Enabled Plugins in Web Viewer
        Added a basic PDF reader by rendering an image from the PDF
    June 4:
        Added PDF Tab as a seperate object
    June 5:
        Added Media Tab as seperate object
    June 7:
        Added Content Tab as seperate Object
    June 17:
        Added Splash Screen
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "exitdialog.h"
#include "mediatabmanager.h"
#include "contenttabmanager.h"
#include "activitytabmanager.h"

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
#include <QObject>
#include <QEvent>
#include <QLabel>
#include <QAction>
#include <QFileDialog>
#include <QSplashScreen>
#include <QGradient>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    Ui::MainWindow *ui;

    ContentTabManager* ContentManager;
    ActivityTabManager* ActivityManager;
    MediaTabManager* MediaTab;

    static QSplashScreen* SplashScreen;

private:
    ExitDialog *exitDialog;

    void closeEvent(QCloseEvent *event);

    void connectEvents();

    QAction *exitCoral;

private slots:
    void openExitDialog();

};

#endif // MAINWINDOW_H
