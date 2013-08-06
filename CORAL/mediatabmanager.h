/*
    Author: Arsen Tufankjian
    Creation Date: June 5, 2013

    Changelog:
        June 6:
            Added total functionality with VLC-qt
        June 7:
            Made possible to use on Mac OSX
            Now an extension of the Manager Class
*/

#ifndef MEDIATABMANAGER_H
#define MEDIATABMANAGER_H

#include "manager.h"

#include <QDebug>
#include <QObject>
#include <QString>
#include <QTreeWidget>
#include <QTableWidget>
#include <QSignalMapper>
#include <QThread>

#include <Instance.h>
#include <MediaPlayer.h>
#include <Media.h>
#include <Common.h>
#include <MetaManager.h>
#include <MediaListPlayer.h>
#include <MediaList.h>
#include <Audio.h>

class MainWindow; //Forward Declaration

class MediaTabManager : public Manager
{
    Q_OBJECT //Macro to make sure connections don't go to the QObject Class

public:
    MediaTabManager(MainWindow* mainUI);

    void setupConnections();

private:
    VlcInstance* vlcInstance;
    VlcMediaListPlayer* mediaPlayer;
    VlcMediaList* playlist;
    VlcMedia* currentMedia;
    VlcMetaManager* metaManager;

    bool isPlaying;

    void AddRootFolder();
    void AddChildFolder(QTreeWidgetItem* parent, QTreeWidgetItem *child);
    void SearchForMusic(QTreeWidgetItem* parent, QString directory);
    QString FileNameFromDirectory(QString directory);
    QString MSToString(int time);

    //Variables stored for threading
    QTreeWidgetItem* clickedItem;

private slots:
    void addMedia();
    void updateTrackList(QTreeWidgetItem* clickedItem);
    void playSelectedMedia(int row, int column);
    void pausePlay();
    void nextTrack();
    void prevTrack();
    void changeVolume();
    void updateTime();
};

#endif // MEDIATABMANAGER_H
