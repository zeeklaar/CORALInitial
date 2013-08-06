/*
    Author: Arsen Tufankjian
    Creation Date: May 28, 2013

    Changelog:

    May 30:
        Changed Password from 'welcometocoral' to '1234'
*/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QDebug>
#include <QPalette>
#include <QUdpSocket>

#include "mainwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    
private:
    QUdpSocket* udpSocket;

    Ui::LoginWindow *ui;
    MainWindow coralMain;

private slots:
    void loginButtonClicked();
    void listenForServer();
};

#endif // LOGINWINDOW_H
