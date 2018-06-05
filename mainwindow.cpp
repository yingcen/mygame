#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "icon.h"

#include <map>
#include <iostream>
#include <fstream>
#include <QTimer>

using namespace std;
extern fstream error;
extern bool man;
//extern bool state;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _game.initWorld1("C:\\Users\\dell\\Desktop\\map.txt");//TODO 应该是输入有效的地图文件
    _game.initWorld2("C:\\Users\\dell\\Desktop\\map2.txt");//TODO 应该是输入有效的地图文件

    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(randomMove1()));//timeoutslot()为自定义槽
    //时钟事件与randomMove函数绑定
    timer1->start(100);
    timer1->setInterval(1000);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     //设置随机数种子

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(randomMove2()));//timeoutslot()为自定义槽
    //时钟事件与randomMove函数绑定
    timer2->start(100);
    timer2->setInterval(1000);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     //设置随机数
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow ::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void  MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}

void  MainWindow::randomMove1(){
    int d = 1 + rand()%4;
    this->_game.monster1Move(d,1);
    this->repaint();
}

void  MainWindow::randomMove2(){
    int d = 1 + rand()%4;
    this->_game.monster2Move(d,1);
    this->repaint();
}
