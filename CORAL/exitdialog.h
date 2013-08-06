/*
    Author: Arsen Tufankjian
    Creation Date: May 30, 2013
*/

#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ExitDialog(QWidget *parent = 0);
    ~ExitDialog();
    
private:
    Ui::ExitDialog *ui;

private slots:
    void exitProgram();
    void returnToCoral();

};

#endif // EXITDIALOG_H
