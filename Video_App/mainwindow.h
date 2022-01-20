#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//importing Qt libraries
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QMediaDevices>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionFast_Forward_triggered();

    void on_actionRewind_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;

    QMediaPlayer* player;   //set pointer of QMediaPlayer to player variable
    QVideoWidget* vw;       //set pointer of QVideoWidget to vw variable
    QProgressBar* bar;      //set pointer of QProgressBar to bar variable
    QSlider* slider;        //set pointer of QSlider to slider variable
    QAudioOutput* audio;    //set pointer of QAudioOutput to audio variable
};
#endif // MAINWINDOW_H
