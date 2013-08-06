/*
    Author: Arsen Tufankjian
    Creation Date: June 3, 2013

    Changelog:
        June 6:
            Added total functionality with VLC-qt
        June 7:
            Made possible to use on Mac OSX
            Now an extension of the Manager Class
*/

#include "mediatabmanager.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MediaTabManager::MediaTabManager(MainWindow* mainWin) : Manager(mainWin)
{
    mainWindow->ui->mediaBrowser->setColumnCount(2); //One column for name, the other for location

    mainWindow->ui->trackTable->horizontalHeader()->show();
    mainWindow->ui->trackTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Setup VLC variables
    vlcInstance = new VlcInstance(VlcCommon::args(),this);
    mediaPlayer = new VlcMediaListPlayer(vlcInstance);
    playlist = new VlcMediaList(vlcInstance);

    isPlaying = false;

    AddRootFolder();
}

/*
    Public Functions
*/

void MediaTabManager::setupConnections()
{
    connect(mainWindow->ui->addMediaButton, SIGNAL(clicked()), this, SLOT(addMedia()));
    connect(mainWindow->ui->mediaBrowser, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(updateTrackList(QTreeWidgetItem*)));
    connect(mainWindow->ui->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(changeVolume()));

    connect(mainWindow->ui->trackTable, SIGNAL(cellClicked(int,int)), this, SLOT(playSelectedMedia(int, int)));
    connect(mainWindow->ui->playPauseButton, SIGNAL(clicked()), this, SLOT(pausePlay()));
    connect(mainWindow->ui->nextTrackButton, SIGNAL(clicked()), this, SLOT(nextTrack()));
    connect(mainWindow->ui->previousTrackButton, SIGNAL(clicked()), this, SLOT(prevTrack()));

    connect(mediaPlayer->mediaPlayer(), SIGNAL(timeChanged(int)), this, SLOT(updateTime()));
}

/*
    Private Functions
*/

void MediaTabManager::AddRootFolder()
{
    QTreeWidgetItem *root = new QTreeWidgetItem();
    root->setText(0, "Music");
    mainWindow->ui->mediaBrowser->addTopLevelItem(root);
}
void MediaTabManager::AddChildFolder(QTreeWidgetItem* parent, QTreeWidgetItem *child)
{
    parent->addChild(child);
}

//Returns the name of the folder of file minus the path and file extention
QString MediaTabManager::FileNameFromDirectory(QString directory)
{
    QString name = directory.mid(directory.lastIndexOf("/") +1 );

    //Is there a file extention?
    int fileExtentionIndex = name.lastIndexOf(".");

    if(fileExtentionIndex > 0)
    {
        name = name.mid(0, fileExtentionIndex);
    }


    return name;
}

void MediaTabManager::SearchForMusic(QTreeWidgetItem *parent, QString directory)
{

    QDirIterator directoryWalker(directory, QDir::AllEntries | QDir::NoSymLinks);

    while(directoryWalker.hasNext())
    {
        directoryWalker.next();

         if(directoryWalker.fileName().contains(".mp3") || !directoryWalker.filePath().contains('.')){

            //Create the Widget item
            QTreeWidgetItem *child = new QTreeWidgetItem();
            child->setText(0, directoryWalker.fileName());
            child->setText(1, directory);

            //Add the file to the widget only if it's an mp3 or if it's a directory
            if(directoryWalker.fileName().contains(".mp3") || !directoryWalker.fileName().contains(".")){
                AddChildFolder(parent, child);
            }

            //Recursivley search if the file is not an mp3
            if(!directoryWalker.fileName().contains(".mp3")){
                SearchForMusic(child, directoryWalker.filePath());
            }
        }
    }
}

//Converts time from milliseconds into a string
QString MediaTabManager::MSToString(int time)
{
    int seconds = time / 1000; // convert to seconds

    int minutes = seconds / 60; // get the number of minutes

    int remainingSeconds = seconds % 60; // get the leftover seconds

    QString timeString;

    if(remainingSeconds < 10)
    {
        timeString = QString::number(minutes) + ":0" + QString::number(remainingSeconds);
    }
    else
    {
        timeString = QString::number(minutes) + ":" + QString::number(remainingSeconds);
    }

    return timeString;
}

/*
    Private Slots
*/

void MediaTabManager::addMedia()
{
    QString folderDir = QFileDialog::getExistingDirectory(mainWindow, tr("Open Media Folder"),tr("C:/"), QFileDialog::ShowDirsOnly );

    if(folderDir != NULL)
    {
        QString folderName = FileNameFromDirectory(folderDir);
        QString folderPath = folderDir.mid(0,folderDir.length() - folderName.length());

        //Create the Widget item
        QTreeWidgetItem *topChild = new QTreeWidgetItem();
        topChild->setText(0, folderName);
        topChild->setText(1, folderPath);
        mainWindow->ui->mediaBrowser->topLevelItem(0)->addChild(topChild);

        SearchForMusic(topChild, folderDir);
    }
}

void MediaTabManager::updateTrackList(QTreeWidgetItem* clickedItem)
{
    QTableWidget* trackTable = mainWindow->ui->trackTable;

    trackTable->setRowCount(0); //Reset the table

    QString directory;

    //Get the directory that deals with the content we want but only if we're not clicking the top level item
    if(clickedItem != mainWindow->ui->mediaBrowser->topLevelItem(0)){
       directory = clickedItem->text(1) + "/" + clickedItem->text(0);
    }

    if(directory != NULL){
        QDirIterator directoryWalker(directory, QDir::AllEntries | QDir::NoSymLinks, QDirIterator::Subdirectories);

        playlist = new VlcMediaList(vlcInstance); //Create a new playlist to clear it

        while(directoryWalker.hasNext())
        {
            directoryWalker.next();

            if(directoryWalker.fileName().contains(".mp3"))
            {
                VlcMedia* foundMedia = new VlcMedia(directoryWalker.filePath(), true, vlcInstance);

                //Add songs found to playlist
                playlist->addMedia(foundMedia);

                metaManager = new VlcMetaManager(foundMedia);

                QTableWidgetItem *trackItem = new QTableWidgetItem();
                QTableWidgetItem *titleItem = new QTableWidgetItem();
                QTableWidgetItem *artistItem = new QTableWidgetItem();
                QTableWidgetItem *albumItem = new QTableWidgetItem();
                QTableWidgetItem *locItem = new QTableWidgetItem();

                trackItem->setText(QString::number(metaManager->number()));
                titleItem->setText(metaManager->title());
                artistItem->setText(metaManager->artist());
                albumItem->setText(metaManager->album());
                locItem->setText(directoryWalker.filePath());

                int row = trackTable->rowCount();
                trackTable->insertRow(row);

                //Make sure they can't be edited
                trackItem->setFlags(trackItem->flags() ^ Qt::ItemIsEditable);
                titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
                artistItem->setFlags(artistItem->flags() ^ Qt::ItemIsEditable);
                albumItem->setFlags(albumItem->flags() ^ Qt::ItemIsEditable);
                locItem->setFlags(locItem->flags() ^ Qt::ItemIsEditable);

                trackTable->setItem(row, 0, trackItem);
                trackTable->setItem(row, 1, titleItem);
                trackTable->setItem(row, 2, artistItem);
                trackTable->setItem(row, 3, albumItem);
                trackTable->setItem(row, 4, locItem);
            }
        }
        //After all the data is added to the playlist, link the playlist to the media player
        mediaPlayer->setMediaList(playlist);
    }
}

void MediaTabManager::playSelectedMedia(int row, int column)
{
    Q_UNUSED(column)

    if(mainWindow->ui->trackTable->rowCount() != 0){
        isPlaying = true;

        mainWindow->ui->playPauseButton->setText("Pause");

        currentMedia = playlist->at(row);
        mediaPlayer->itemAt(row); //Starts playing media at that index
    }
}

void MediaTabManager::pausePlay()
{

    if(isPlaying)
    {
        mainWindow->ui->playPauseButton->setText("Play");
        mediaPlayer->mediaPlayer()->togglePause();

        isPlaying = false;
    }
    else if(!isPlaying)
    {
        mainWindow->ui->playPauseButton->setText("Pause");
        mediaPlayer->mediaPlayer()->togglePause();
    }
}


void MediaTabManager::nextTrack()
{
    int currentRow = mainWindow->ui->trackTable->currentRow();

    if(currentRow < playlist->count()){
        currentRow++;

        mainWindow->ui->trackTable->selectRow(currentRow); //Increment the selected row

        playSelectedMedia(currentRow, 4);
    }
}

void MediaTabManager::prevTrack()
{
    int currentRow = mainWindow->ui->trackTable->currentRow();

    if(currentRow > 0){
        currentRow--;

        mainWindow->ui->trackTable->selectRow(currentRow);

        playSelectedMedia(currentRow, 4);
    }
}

//Edit the audio volume
void MediaTabManager::changeVolume()
{
    mediaPlayer->mediaPlayer()->audio()->setVolume(mainWindow->ui->volumeSlider->value());

    mainWindow->ui->volumePercentLabel->setText(QString::number(mainWindow->ui->volumeSlider->value()) + "%");
}

//Make the time slider and time lables update accordingly
void MediaTabManager::updateTime()
{
    mainWindow->ui->trackTimeSlider->setMaximum(mediaPlayer->mediaPlayer()->length());

    mainWindow->ui->trackCurrentTimeLabel->setText(MSToString(mediaPlayer->mediaPlayer()->time()));
    mainWindow->ui->trackMaxTimeLabel->setText(MSToString(mediaPlayer->mediaPlayer()->length()));

    mainWindow->ui->trackTimeSlider->setValue(mediaPlayer->mediaPlayer()->time());
}

