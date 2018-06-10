#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include "monster.h"
#include "bullet.h"


class World
{
public:
    World(){}
    ~World(){}
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void initWorld1(string mapFile);
    void initWorld2(string mapFile);
    void initWin(string winFile);
    void initbullet();
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void monster1Move(int direction, int steps);
    void monster2Move(int direction,int steps);
    void handlePlayerMove(int direction, int steps);
    void bulletMove(int direction);
        //假定只有一个玩家
    void beat();
    bullet _bullet;

private:
    vector<RPGObj> _objs1;
    vector<RPGObj> _objs2;
    vector<RPGObj> _objs3;
    vector<monster> _monsters1;
    vector<monster> _monsters2;
    //vector<bullet> _bullet;
    Player _player;

/*public:
    bool flag=1;*/
};

#endif // WORLD_H
