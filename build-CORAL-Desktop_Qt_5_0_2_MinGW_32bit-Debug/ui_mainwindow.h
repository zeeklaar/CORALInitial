/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabPane;
    QWidget *ContentTab;
    QHBoxLayout *horizontalLayout;
    QScrollArea *contentScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QFrame *requiredFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *requiredLabel;
    QFrame *requiredListFrame;
    QFrame *optionalFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QFrame *optionalListFrame;
    QWidget *ActivityTab;
    QGridLayout *gridLayout_2;
    QFrame *ActivityTabFrame;
    QVBoxLayout *verticalLayout;
    QWidget *MediaTab;
    QGridLayout *gridLayout_3;
    QFrame *mediaBrowsingFrame;
    QHBoxLayout *horizontalLayout_5;
    QTreeWidget *mediaBrowser;
    QTableWidget *trackTable;
    QFrame *mediaControlFrame;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *previousTrackButton;
    QPushButton *playPauseButton;
    QPushButton *nextTrackButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *trackCurrentTimeLabel;
    QSlider *trackTimeSlider;
    QLabel *trackMaxTimeLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *volumeLabel;
    QSlider *volumeSlider;
    QLabel *volumePercentLabel;
    QSpacerItem *horizontalSpacer_6;
    QFrame *mediaManagementFrame;
    QPushButton *addMediaButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1304, 622);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabPane = new QTabWidget(centralWidget);
        tabPane->setObjectName(QStringLiteral("tabPane"));
        ContentTab = new QWidget();
        ContentTab->setObjectName(QStringLiteral("ContentTab"));
        horizontalLayout = new QHBoxLayout(ContentTab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        contentScrollArea = new QScrollArea(ContentTab);
        contentScrollArea->setObjectName(QStringLiteral("contentScrollArea"));
        contentScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1260, 546));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        requiredFrame = new QFrame(scrollAreaWidgetContents);
        requiredFrame->setObjectName(QStringLiteral("requiredFrame"));
        requiredFrame->setFrameShape(QFrame::StyledPanel);
        requiredFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(requiredFrame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        requiredLabel = new QLabel(requiredFrame);
        requiredLabel->setObjectName(QStringLiteral("requiredLabel"));
        requiredLabel->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(requiredLabel);

        requiredListFrame = new QFrame(requiredFrame);
        requiredListFrame->setObjectName(QStringLiteral("requiredListFrame"));
        requiredListFrame->setFrameShape(QFrame::StyledPanel);
        requiredListFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(requiredListFrame);


        verticalLayout_3->addWidget(requiredFrame);

        optionalFrame = new QFrame(scrollAreaWidgetContents);
        optionalFrame->setObjectName(QStringLiteral("optionalFrame"));
        optionalFrame->setFrameShape(QFrame::StyledPanel);
        optionalFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(optionalFrame);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(optionalFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_5->addWidget(label_2);

        optionalListFrame = new QFrame(optionalFrame);
        optionalListFrame->setObjectName(QStringLiteral("optionalListFrame"));
        optionalListFrame->setFrameShape(QFrame::StyledPanel);
        optionalListFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(optionalListFrame);


        verticalLayout_3->addWidget(optionalFrame);

        contentScrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(contentScrollArea);

        tabPane->addTab(ContentTab, QString());
        ActivityTab = new QWidget();
        ActivityTab->setObjectName(QStringLiteral("ActivityTab"));
        gridLayout_2 = new QGridLayout(ActivityTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ActivityTabFrame = new QFrame(ActivityTab);
        ActivityTabFrame->setObjectName(QStringLiteral("ActivityTabFrame"));
        ActivityTabFrame->setFrameShape(QFrame::StyledPanel);
        ActivityTabFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(ActivityTabFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout_2->addWidget(ActivityTabFrame, 0, 0, 1, 1);

        tabPane->addTab(ActivityTab, QString());
        MediaTab = new QWidget();
        MediaTab->setObjectName(QStringLiteral("MediaTab"));
        gridLayout_3 = new QGridLayout(MediaTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        mediaBrowsingFrame = new QFrame(MediaTab);
        mediaBrowsingFrame->setObjectName(QStringLiteral("mediaBrowsingFrame"));
        mediaBrowsingFrame->setFrameShape(QFrame::StyledPanel);
        mediaBrowsingFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(mediaBrowsingFrame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mediaBrowser = new QTreeWidget(mediaBrowsingFrame);
        mediaBrowser->setObjectName(QStringLiteral("mediaBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaBrowser->sizePolicy().hasHeightForWidth());
        mediaBrowser->setSizePolicy(sizePolicy);
        mediaBrowser->setMaximumSize(QSize(250, 16777215));
        mediaBrowser->setColumnCount(2);

        horizontalLayout_5->addWidget(mediaBrowser);

        trackTable = new QTableWidget(mediaBrowsingFrame);
        if (trackTable->columnCount() < 5)
            trackTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        trackTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        trackTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        trackTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        trackTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        trackTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        trackTable->setObjectName(QStringLiteral("trackTable"));
        trackTable->setShowGrid(true);
        trackTable->setSortingEnabled(true);
        trackTable->setWordWrap(false);
        trackTable->setColumnCount(5);
        trackTable->horizontalHeader()->setVisible(false);
        trackTable->horizontalHeader()->setCascadingSectionResizes(true);
        trackTable->horizontalHeader()->setDefaultSectionSize(200);
        trackTable->horizontalHeader()->setStretchLastSection(true);
        trackTable->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(trackTable);


        gridLayout_3->addWidget(mediaBrowsingFrame, 1, 0, 1, 1);

        mediaControlFrame = new QFrame(MediaTab);
        mediaControlFrame->setObjectName(QStringLiteral("mediaControlFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mediaControlFrame->sizePolicy().hasHeightForWidth());
        mediaControlFrame->setSizePolicy(sizePolicy1);
        mediaControlFrame->setMinimumSize(QSize(0, 50));
        mediaControlFrame->setFrameShape(QFrame::StyledPanel);
        mediaControlFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(mediaControlFrame);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        previousTrackButton = new QPushButton(mediaControlFrame);
        previousTrackButton->setObjectName(QStringLiteral("previousTrackButton"));

        horizontalLayout_4->addWidget(previousTrackButton);

        playPauseButton = new QPushButton(mediaControlFrame);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));
        playPauseButton->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_4->addWidget(playPauseButton);

        nextTrackButton = new QPushButton(mediaControlFrame);
        nextTrackButton->setObjectName(QStringLiteral("nextTrackButton"));

        horizontalLayout_4->addWidget(nextTrackButton);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        trackCurrentTimeLabel = new QLabel(mediaControlFrame);
        trackCurrentTimeLabel->setObjectName(QStringLiteral("trackCurrentTimeLabel"));

        horizontalLayout_6->addWidget(trackCurrentTimeLabel);

        trackTimeSlider = new QSlider(mediaControlFrame);
        trackTimeSlider->setObjectName(QStringLiteral("trackTimeSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(trackTimeSlider->sizePolicy().hasHeightForWidth());
        trackTimeSlider->setSizePolicy(sizePolicy2);
        trackTimeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(trackTimeSlider);

        trackMaxTimeLabel = new QLabel(mediaControlFrame);
        trackMaxTimeLabel->setObjectName(QStringLiteral("trackMaxTimeLabel"));

        horizontalLayout_6->addWidget(trackMaxTimeLabel);

        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        volumeLabel = new QLabel(mediaControlFrame);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        horizontalLayout_6->addWidget(volumeLabel);

        volumeSlider = new QSlider(mediaControlFrame);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy3);
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(volumeSlider);

        volumePercentLabel = new QLabel(mediaControlFrame);
        volumePercentLabel->setObjectName(QStringLiteral("volumePercentLabel"));

        horizontalLayout_6->addWidget(volumePercentLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout_3->addWidget(mediaControlFrame, 2, 0, 1, 1);

        mediaManagementFrame = new QFrame(MediaTab);
        mediaManagementFrame->setObjectName(QStringLiteral("mediaManagementFrame"));
        sizePolicy1.setHeightForWidth(mediaManagementFrame->sizePolicy().hasHeightForWidth());
        mediaManagementFrame->setSizePolicy(sizePolicy1);
        mediaManagementFrame->setMinimumSize(QSize(0, 40));
        mediaManagementFrame->setFrameShape(QFrame::StyledPanel);
        mediaManagementFrame->setFrameShadow(QFrame::Raised);
        addMediaButton = new QPushButton(mediaManagementFrame);
        addMediaButton->setObjectName(QStringLiteral("addMediaButton"));
        addMediaButton->setGeometry(QRect(20, 10, 75, 23));

        gridLayout_3->addWidget(mediaManagementFrame, 0, 0, 1, 1);

        tabPane->addTab(MediaTab, QString());

        gridLayout->addWidget(tabPane, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabPane->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        requiredLabel->setText(QApplication::translate("MainWindow", "Required Activities:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Optional Activites: ", 0));
        tabPane->setTabText(tabPane->indexOf(ContentTab), QApplication::translate("MainWindow", "Content Tab", 0));
        tabPane->setTabText(tabPane->indexOf(ActivityTab), QApplication::translate("MainWindow", "Activity Tab", 0));
        QTreeWidgetItem *___qtreewidgetitem = mediaBrowser->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Location", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Folder Name", 0));
        QTableWidgetItem *___qtablewidgetitem = trackTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Track", 0));
        QTableWidgetItem *___qtablewidgetitem1 = trackTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem2 = trackTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Artist", 0));
        QTableWidgetItem *___qtablewidgetitem3 = trackTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem4 = trackTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Location", 0));
        previousTrackButton->setText(QApplication::translate("MainWindow", "<<", 0));
        playPauseButton->setText(QApplication::translate("MainWindow", "Play", 0));
        nextTrackButton->setText(QApplication::translate("MainWindow", ">>", 0));
        trackCurrentTimeLabel->setText(QApplication::translate("MainWindow", "0:00", 0));
        trackMaxTimeLabel->setText(QApplication::translate("MainWindow", "0:00", 0));
        volumeLabel->setText(QApplication::translate("MainWindow", "Volume:", 0));
        volumePercentLabel->setText(QApplication::translate("MainWindow", "100%", 0));
        addMediaButton->setText(QApplication::translate("MainWindow", "Add Folder", 0));
        tabPane->setTabText(tabPane->indexOf(MediaTab), QApplication::translate("MainWindow", "Media Tab", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
