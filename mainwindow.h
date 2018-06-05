#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include "world2.h"
#include "player.h"
#include<QTime>
#include<QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
   // void keyPressEvent(QKeyEvent *);
protected slots:
    void randomMove1();//响应时钟事件的函数
    void randomMove2();
private:
    Ui::MainWindow *ui;
    World _game;
   // World2 _game2;
    QTimer *timer1;//时钟，控制玩家移动频率
    QTimer *timer2;
};

#endif // MAINWINDOW_H
