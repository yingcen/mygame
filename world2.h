#ifndef WORLD2_H
#define WORLD2_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include "monster.h"



class World2
{
public:
    World2(){}
    ~World2(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    //void initWorld2(string mapFile);
    void show(QPainter * painter);
        //显示游戏世界所有对象
    //void monsterMove(int direction, int steps);
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家

private:
    vector<RPGObj> _objs2;
    //vector<monster> _monsters2;
    Player _player2;
};

#endif // WORLD2_H
