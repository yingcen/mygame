#include "mainwindow.h"
#include "write_in.h"
#include "two_write_in.h"
#include <QApplication>
#include <fstream>
fstream error;
fstream write;
fstream two_write;
write_in draw;
two_write_in two_draw;

bool man=true;
short state=1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    draw.write_all("C:\\Users\\dell\\Desktop\\map.txt");
    two_draw.write_all("C:\\Users\\dell\\Desktop\\map2.txt");

    MainWindow mw1;
    mw1.show();

    return a.exec();
}
