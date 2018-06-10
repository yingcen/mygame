#include "mainwindow.h"
#include "write_in.h"
#include "two_write_in.h"
#include "write_win.h"
#include <QApplication>
#include <fstream>
#include <QtMultimedia/QMediaPlayer>

fstream error;
fstream write;
fstream two_write;
fstream _win;
write_in draw;
two_write_in two_draw;
write_win win_draw;

bool man=true;
short state=1;
short fruitnum=0;
short monnum=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    draw.write_all("C:\\Users\\dell\\Desktop\\map.txt");
    two_draw.write_all("C:\\Users\\dell\\Desktop\\map2.txt");
    win_draw.write_all("C:\\Users\\dell\\Desktop\\win.txt");


    MainWindow mw1;
    mw1.show();



    QMediaPlayer *player1 = new QMediaPlayer;
    player1->setMedia(QUrl::fromLocalFile("C:\\Users\\dell\\Desktop\\world.mp3"));
    player1->setVolume(60);
    player1->play();



    return a.exec();
}
