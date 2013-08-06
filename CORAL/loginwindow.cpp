/*
    Author: Arsen Tufankjian
    Creation Date: May 28, 2013

    Changelog:

    May 30:
        Changed Password from 'welcometocoral' to '1234'
    June 18:
        Added the ability for this to listen for the CORAL server over UDP
*/

#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->passwordLine->setEchoMode(QLineEdit::Password); //Make the passwordLine object hide characters

    //Set Error Label Color to Red
    QPalette errorPalette;
    errorPalette.setColor(QPalette::WindowText, Qt::red);

    ui->errorLabel->setPalette(errorPalette);

    setWindowFlags(Qt::WindowStaysOnTopHint); //Make sure the login window stays on top so that nothing gets in its way

    setFixedSize(400,160); //Set a fixed size for the login window

    //Initialize UDP Socket Pointer
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    //Setup event connections
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(listenForServer()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

/*
    Private Slots
*/

void LoginWindow::loginButtonClicked()
{
    /*
      TODO: This will need to connect to a remote database to grab passwords.
      This will mean threading the database info grabbing and then
      displaying a little splash screen while the data is retrieved.
      As of right now that's a bit out of scope, what without having
      a real database or even functional APIs, so this will be saved for later.
      This is more of a demo of a possible login screen
    */

    //Get info from UI
    QString username = ui->usernameLine->text();
    QString password = ui->passwordLine->text();

    if(username == "Arsen" && password == "1234")
    {
        hide();
        ui->errorLabel->setText("");
        coralMain.show();
    }else
    {
        ui->errorLabel->setText("Error logging in: Invalid Username or Password");
    }
}

void LoginWindow::listenForServer()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());
        setWindowTitle(data.data());
    }
}
