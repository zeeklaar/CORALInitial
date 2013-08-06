/*
    Author: Arsen Tufankjian
    Creation Date: May 30, 2013

    Changelog:

*/

#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);

    //Set Error Label Color to Red
    QPalette errorPalette;
    errorPalette.setColor(QPalette::WindowText, Qt::red);

    ui->errorLabel->setPalette(errorPalette);

    //Set a fixed size for the exit window
    setFixedSize(400,160);

    //Setup connections
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitProgram()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(returnToCoral()));

    setWindowFlags(Qt::WindowStaysOnTopHint); //Make the window always on top

    hide();
}

/*
    Private Slots
*/

void ExitDialog::exitProgram()
{
    if(ui->exitCodeLine->text() == "1234"){
        qApp->exit();
    }
    else
    {
        ui->errorLabel->setText("Error: Incorrect Exit Code");
    }
}

void ExitDialog::returnToCoral()
{
    hide();
}

ExitDialog::~ExitDialog()
{
    delete ui;
}
