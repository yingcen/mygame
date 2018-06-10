#include "world2.h"
#include "icon.h"
#include "rpgobj.h"
#include <fstream>
#include "monster.h"
#include <iostream>
using namespace std;
extern fstream two_write;
extern fstream error;
extern bool man;

void World2::initWorld(string mapFile){
    fstream map;
        string icon_name;
        int x,y;
        map.open(mapFile.c_str(),ios::in);
        if(map.is_open()){
            map>>icon_name>>x>>y;
            this->_player2.initObj(icon_name);
            this->_player2.setPosX(1);
            this->_player2.setPosY(1);  //首先初始化玩家信息

            map>>icon_name;
            while(icon_name!="EOF"){
                RPGObj obj;
                map>>x>>y;
                obj.initObj(icon_name);
                obj.setPosX(x);
                obj.setPosY(y);      //初始化2地面画面信息
                this->_objs2.push_back(obj);
                map>>icon_name;
            }

            map.close();
        }
        else{   //出现错误记入错误日志中
            error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::out);
            error<<"Error:cannot open map file!!!";
            error.close();
        }

}

void World2::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs2.begin();it!=this->_objs2.end();++it){
        (*it).show(painter);
    }
    if(man) this->_player2.show(painter);
    /*vector<monster>::iterator itt;
    for(itt=this->_monsters.begin();itt!=this->_monsters.end();++itt){
        (*itt).show(painter);
    }*/
}

void World2::handlePlayerMove(int direction, int steps){
     this->_player2.move(direction, steps);
}
