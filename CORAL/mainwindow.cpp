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
        Added a splash screen as a static object to be interacted with from other objects
    June 19:
        Added a call to make sure that the ContentTab is shown first
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

QSplashScreen* MainWindow::SplashScreen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Setup a splash screen
    QPixmap splashImage("C://splash.png");
    MainWindow::SplashScreen = new QSplashScreen();
    MainWindow::SplashScreen->setPixmap(splashImage);
    MainWindow::SplashScreen->show();

    setUnifiedTitleAndToolBarOnMac(true);

    //Set Background to a gradient
    QLinearGradient gradient(QPointF(this->width() / 2, 0), QPointF(this->width() / 2, this->height()));
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::gray);

    QPalette backgroundPalette;
    backgroundPalette.setBrush(QPalette::Window, *(new QBrush(gradient)));
    this->setPalette(backgroundPalette);

    //Setup UI
    ui->setupUi(this);

    //Make the first thing seen the first index
    ui->tabPane->setCurrentIndex(0);

    //Setup custom objects
    ContentManager = new ContentTabManager(this);
    ActivityManager = new ActivityTabManager(this);
    MediaTab = new MediaTabManager(this);

    exitDialog = new ExitDialog;

    //Actions
    exitCoral = new QAction(tr("Exit"), this);
    ui->toolBar->addAction(exitCoral);

    //Connect events
    connectEvents();

    //setWindowFlags(Qt::WindowStaysOnTopHint); //Make the window always on top
    showFullScreen(); //Make the application fullscreen

    hide(); //So that the login screen can show up first
}

/*
    Private Functions
*/

void MainWindow::connectEvents()
{
    connect(exitCoral, SIGNAL(triggered()), this, SLOT(openExitDialog()));

    MediaTab->setupConnections();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore(); //Makes the program unable to be exited regularly
}

/*
    Private Slots
*/

void MainWindow::openExitDialog()
{
    exitDialog->show();
}


//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}
