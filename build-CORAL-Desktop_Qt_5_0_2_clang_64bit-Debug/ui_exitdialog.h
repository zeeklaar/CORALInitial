/********************************************************************************
** Form generated from reading UI file 'exitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITDIALOG_H
#define UI_EXITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExitDialog
{
public:
    QPushButton *exitButton;
    QPushButton *cancelButton;
    QLabel *exitCodeLabel;
    QLineEdit *exitCodeLine;
    QLabel *errorLabel;

    void setupUi(QDialog *ExitDialog)
    {
        if (ExitDialog->objectName().isEmpty())
            ExitDialog->setObjectName(QStringLiteral("ExitDialog"));
        ExitDialog->resize(400, 160);
        exitButton = new QPushButton(ExitDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(200, 100, 75, 23));
        cancelButton = new QPushButton(ExitDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(300, 100, 75, 23));
        exitCodeLabel = new QLabel(ExitDialog);
        exitCodeLabel->setObjectName(QStringLiteral("exitCodeLabel"));
        exitCodeLabel->setGeometry(QRect(20, 45, 46, 13));
        exitCodeLine = new QLineEdit(ExitDialog);
        exitCodeLine->setObjectName(QStringLiteral("exitCodeLine"));
        exitCodeLine->setGeometry(QRect(80, 40, 301, 20));
        errorLabel = new QLabel(ExitDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(40, 70, 331, 16));

        retranslateUi(ExitDialog);

        QMetaObject::connectSlotsByName(ExitDialog);
    } // setupUi

    void retranslateUi(QDialog *ExitDialog)
    {
        ExitDialog->setWindowTitle(QApplication::translate("ExitDialog", "Enter Exit Code", 0));
        exitButton->setText(QApplication::translate("ExitDialog", "Exit", 0));
        cancelButton->setText(QApplication::translate("ExitDialog", "Cancel", 0));
        exitCodeLabel->setText(QApplication::translate("ExitDialog", "Exit Code:", 0));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExitDialog: public Ui_ExitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITDIALOG_H
