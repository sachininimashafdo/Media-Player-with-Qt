#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>  //importing QMessagebox library
#include <QApplication> //importing QApplication library

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this); //new player from QMediaPlayer
    audio = new QAudioOutput(this);  //new audio from QAudioOutput
    vw = new QVideoWidget(this);     //new vw from QVideoWidget
    player->setVideoOutput(vw);     //set video output to the video widget
    this->setCentralWidget(vw);     //set the theatre as the center
    player->setAudioOutput(audio);  //set audio output from video

    slider = new QSlider(this);     //new slider from QSlider

    slider->setOrientation(Qt::Horizontal); //set slider as Horizontal

    ui->statusbar->addPermanentWidget(slider);  //create slider on status bar (UI)


    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum); //connect video duration with slider
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);   //set slider position and video position
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition); //when slider move back and forth video will positioned correctly

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a file", " " , "Video File (*.avi, *.mpg, *.mp4)");  //file format of opening video
    on_actionStop_triggered();

    player->setSource(QUrl::fromLocalFile(filename));   //file location

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();                             //play the video
    player->setPlaybackRate(1.0);               //speed of the video(when we rewind or forward, user can ress play button to get to normal speed)
    audio->setVolume(50);                       //volume of video
    ui->statusbar->showMessage("Playing..");    //message which shows on status bar
}


void MainWindow::on_actionPause_triggered()
{
    player->pause();                            //pause the video
    ui->statusbar->showMessage("Paused");       //message which shows on status bar
}


void MainWindow::on_actionStop_triggered()
{
    player->stop();                             //Stop the video
    ui->statusbar->showMessage("Stopped.!!");   //message which shows on status bar

}


void MainWindow::on_actionFast_Forward_triggered()
{
    player->setPlaybackRate(8.0);                   //set fast forward speed as 8
    audio->setVolume(0);                            //mute video when forwarding
    ui->statusbar->showMessage("Forwarding...");    //message which shows on status bar
}


void MainWindow::on_actionRewind_triggered()
{
    player->setPlaybackRate(-8.0);                  //set rewind speed as 8
    audio->setVolume(0);                            //mute video when rewinding
    ui->statusbar->showMessage("Rewinding...");     //message which shows on status bar
}


void MainWindow::on_actionHelp_triggered()
{
    //set message box when open help
    QMessageBox::information(this, ("Help"), ("Welcome to Video Player!! This is help section. From Play icon you can play the video. From Pause icon you can pause the video. From Stop icon you can stop the video. Also you can use shortcuts. Play : Ctrl + P, Pause : Ctrl + I, Stop : Ctrl + X, Open a file : Ctrl + A, Help : Ctrl + H"));
}


void MainWindow::on_actionAbout_triggered()
{
    //set message box when open about
    QMessageBox::information(this, ("About"), ("This is a video player created by Nimasha Fernando with Qt creator."));
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    //set in-built about qt feature
    QApplication::aboutQt();
}


void MainWindow::on_actionQuit_triggered()
{
    //set exit when press quit
    QApplication::quit();
}

