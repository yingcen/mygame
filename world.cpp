#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <fstream>
#include "monster.h"
#include <iostream>
#include <QtMultimedia/QMediaPlayer>

using namespace std;
extern fstream write;
extern fstream two_write;
extern fstream error;
extern bool man;
extern short state;
extern short fruitnum;
extern short monnum;


void World::initWorld1(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    fstream map;
        string icon_name;
        int x,y;
        map.open(mapFile.c_str(),ios::in);
        if(map.is_open()){
            map>>icon_name>>x>>y;
            this->_player.initObj(icon_name);
            this->_player.setPosX(12);
            this->_player.setPosY(9);  //首先初始化玩家信息

            map>>icon_name;
            while(icon_name!="MONSTER"){
                RPGObj obj;
                map>>x>>y;
                obj.initObj(icon_name);
                obj.setPosX(x);
                obj.setPosY(y);      //初始化其余画面信息
                this->_objs1.push_back(obj);
                map>>icon_name;
            }

            map>>icon_name;
            while(icon_name!="EOF"){
                monster mon;
                map>>x>>y;
                mon.initObj(icon_name);
                mon.setPosX(x);
                mon.setPosY(y);      //初始化怪兽画面信息
                this->_monsters1.push_back(mon);
                map>>icon_name;
            }

            map.close();
        }
        else{   //出现错误记入错误日志中
            error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::out);
            error<<"Error:cannot open map file!!!";
            error.close();
        }

        /*QMediaPlayer *player1 = new QMediaPlayer;
        player1->setMedia(QUrl::fromLocalFile("C:\\Users\\dell\\Desktop\\world1.mp3"));
        player1->setVolume(30);
        player1->play();*/

}

void World::initWorld2(string mapFile){
    fstream map;
        string icon_name;
        int x,y;
        map.open(mapFile.c_str(),ios::in);
        if(map.is_open()){
            map>>icon_name>>x>>y;
            this->_player.initObj(icon_name);
            this->_player.setPosX(12);
            this->_player.setPosY(9);  //首先初始化玩家信息

            map>>icon_name;
            while(icon_name!="MONSTER"){
                RPGObj obj;
                map>>x>>y;
                obj.initObj(icon_name);
                obj.setPosX(x);
                obj.setPosY(y);      //初始化2地面画面信息
                this->_objs2.push_back(obj);
                map>>icon_name;
            }

            map>>icon_name;
            while(icon_name!="EOF"){
                monster mon;
                map>>x>>y;
                mon.initObj(icon_name);
                mon.setPosX(x);
                mon.setPosY(y);      //初始化怪兽画面信息
                this->_monsters2.push_back(mon);
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

void World::initWin(string winFile){
    fstream map;
        string icon_name;
        int x,y;
        map.open(winFile.c_str(),ios::in);
        if(map.is_open()){
            map>>icon_name;
            while(icon_name!="EOF"){
                RPGObj obj;
                map>>x>>y;
                obj.initObj(icon_name);
                obj.setPosX(x);
                obj.setPosY(y);      //初始化2地面画面信息
                this->_objs3.push_back(obj);
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

void World::initbullet(){
    int x,y;
    x=this->_player.getPosX();
    y=this->_player.getPosY();
    this->_bullet.initObj("bullet");
    this->_bullet.setPosX(x);
    this->_bullet.setPosY(y+1);
}

void World::bulletMove(int direction){
    //this->initbullet();
    this->_bullet.move(direction);
    this->beat();
}

void World::show(QPainter * painter){
    //if(((this->_player.getPosX()!=1)||((this->_player.getPosY()+1)!=1))&&(state==1))
   if(state==1)
    {
       vector<RPGObj>::iterator it =this->_objs1.begin();
       for (;it != _objs1.end();it++){
           (*it).show(painter);
       }

       if(man) this->_player.show(painter);

       vector<monster>::iterator itt =this->_monsters1.begin();
       for (;itt != _monsters1.end();itt++){
           (*itt).show(painter);
       }
    }
   if(state==2)
    //else
    {
       vector<RPGObj>::iterator it =this->_objs2.begin();
       for (;it != _objs2.end();it++){
           (*it).show(painter);
       }
       if(man) this->_player.show(painter);

       vector<monster>::iterator itt =this->_monsters2.begin();
       for (;itt != _monsters2.end();itt++){
           (*itt).show(painter);
       }

       if((this->_bullet.getPosX()>-1)&&(this->_bullet.getPosX()<25)
                &&(this->_bullet.getPosY()>-1)&&(this->_bullet.getPosY()<20))
       {
           this->_bullet.show(painter);
       }
    }
   if(state==3){
       vector<RPGObj>::iterator it =this->_objs3.begin();
       for (;it != _objs3.end();it++){
           (*it).show(painter);
       }
   }
}

void World::handlePlayerMove(int direction, int steps){
  if(state==1)
   {
   vector<RPGObj>::iterator it = _objs1.end();
        if(direction==1){
            man=true;
            for(;it != _objs1.begin();--it){//遍历
                if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==this->_player.getPosY()){
                    if(!(*it).canCover()){

                        return;
                    }
                    else{
                        if((*it).getObjType()=="grave"){//遇到坟墓
                            man=false;//人不见了
                            _objs1.clear();//clear()删除vector中的所有元素
                            _monsters1.clear();

                            exit(0);//退出程序
                        }
                        else if((*it).canEat()){
                            this->_objs1.erase(it);
                            fruitnum++;
                        }
                        this->_player.move(direction, steps);

                        if((this->_player.getPosX()==1)&&((this->_player.getPosY()+1)==1)&&(fruitnum==70))
                        {
                            _objs1.clear();//clear()删除vector中的所有元素
                            _monsters1.clear();

                            state=2;

                        }


                        return;
                    }
                }
            }
        }
        else if(direction==2){
            man=true;
            for(;it != _objs1.begin();--it){
                if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==(this->_player.getPosY()+2)){
                    if(!(*it).canCover()){

                        return;
                    }
                    else{
                        if((*it).getObjType()=="grave"){
                            man=false;
                            _objs1.clear();
                            _monsters1.clear();

                            exit(0);
                        }
                        if((*it).canEat()){
                            this->_objs1.erase(it);
                            fruitnum++;
                        }
                        this->_player.move(direction, steps);

                        if((this->_player.getPosX()==1)&&((this->_player.getPosY()+1)==1)&&(fruitnum==70))
                        {
                            _objs1.clear();//clear()删除vector中的所有元素
                            _monsters1.clear();

                            state=2;
                        }


                        return;
                    }
                }
            }
        }
        else if(direction==3){
            man=true;
            for(;it != _objs1.begin();--it){
                if((*it).getPosX()==(this->_player.getPosX()-1)&&(*it).getPosY()==(this->_player.getPosY()+1)){
                    if(!(*it).canCover()){

                        return;
                    }
                    else{
                        if((*it).getObjType()=="grave"){
                            man=false;
                            _objs1.clear();
                            _monsters1.clear();

                            exit(0);
                        }
                        if((*it).canEat()){
                            this->_objs1.erase(it);
                            fruitnum++;
                        }
                        this->_player.move(direction, steps);

                        if((this->_player.getPosX()==1)&&((this->_player.getPosY()+1)==1)&&(fruitnum==70))
                        {
                            _objs1.clear();//clear()删除vector中的所有元素
                            _monsters1.clear();

                            state=2;
                        }


                        return;
                    }
                }
            }
        }
        else if(direction==4){
            man=true;
            for(;it != _objs1.begin();--it){
                if((*it).getPosX()==(this->_player.getPosX()+1)&&(*it).getPosY()==(this->_player.getPosY()+1)){
                    if(!(*it).canCover()){

                        return;
                    }
                    else{
                        if((*it).getObjType()=="grave"){
                            man=false;
                            _objs1.clear();
                            _monsters1.clear();

                            exit(0);
                        }
                        if((*it).canEat()){
                            this->_objs1.erase(it);
                            fruitnum++;
                        }
                        this->_player.move(direction, steps);

                        if((this->_player.getPosX()==1)&&((this->_player.getPosY()+1)==1)&&(fruitnum==70))
                        {
                            _objs1.clear();//clear()删除vector中的所有元素
                            _monsters1.clear();

                            state=2;
                        }

                        return;
                    }
                }
            }
        }
        else{
            error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::out);
            error<<"Error:position is out of map!!!";
            error.close();
            this->_player.move(direction, steps);

        }
   }
   if(state==2)
   //else
   {
       vector<RPGObj>::iterator it =_objs2.end();
            if(direction==1){
                man=true;
                for(;it != _objs2.begin();--it){//遍历
                    if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==this->_player.getPosY()){
                        if(!(*it).canCover()){

                            return;
                        }
                        else{
                            if((*it).getObjType()=="grave"){//遇到坟墓
                                man=false;//人不见了
                                _objs2.clear();//clear()删除vector中的所有元素
                                _monsters2.clear();

                                exit(0);//退出程序
                                }

                            this->_player.move(direction, steps);

                            if((this->_player.getPosX()==23)&&((this->_player.getPosY()+1)==18)&&(monnum==6))
                            {
                                _objs2.clear();//clear()删除vector中的所有元素
                                _monsters2.clear();

                                state=3;
                            }


                            return;
                        }
                    }
                }
            }
            else if(direction==2){
                man=true;
                for(;it != _objs2.begin();--it){
                    if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==(this->_player.getPosY()+2)){
                        if(!(*it).canCover()){

                            return;
                        }
                        else{
                            if((*it).getObjType()=="grave"){
                                man=false;
                                _objs2.clear();
                                _monsters2.clear();

                                exit(0);
                            }

                            this->_player.move(direction, steps);

                            if((this->_player.getPosX()==23)&&((this->_player.getPosY()+1)==18)&&(monnum==6))
                            {
                                _objs2.clear();//clear()删除vector中的所有元素
                                _monsters2.clear();

                                state=3;
                            }


                            return;
                        }
                    }
                }
            }
            else if(direction==3){
                man=true;
                for(;it != _objs2.begin();--it){
                    if((*it).getPosX()==(this->_player.getPosX()-1)&&(*it).getPosY()==(this->_player.getPosY()+1)){
                        if(!(*it).canCover()){

                            return;
                        }
                        else{
                            if((*it).getObjType()=="grave"){
                                man=false;
                                _objs2.clear();
                                _monsters2.clear();

                                exit(0);
                            }

                            this->_player.move(direction, steps);

                            if((this->_player.getPosX()==23)&&((this->_player.getPosY()+1)==18)&&(monnum==6))
                            {
                                _objs2.clear();//clear()删除vector中的所有元素
                                _monsters2.clear();

                                state=3;
                            }


                            return;
                        }
                    }
                }
            }
            else if(direction==4){
                man=true;
                for(;it != _objs2.begin();--it){
                    if((*it).getPosX()==(this->_player.getPosX()+1)&&(*it).getPosY()==(this->_player.getPosY()+1)){
                        if(!(*it).canCover()){

                            return;
                        }
                        else{
                            if((*it).getObjType()=="grave"){
                                man=false;
                                _objs2.clear();
                                _monsters2.clear();

                                exit(0);
                            }

                            this->_player.move(direction, steps);

                            if((this->_player.getPosX()==23)&&((this->_player.getPosY()+1)==18)&&(monnum==6))
                            {
                                _objs2.clear();//clear()删除vector中的所有元素
                                _monsters2.clear();

                                state=3;
                            }


                            return;
                        }
                    }
                }
            }
            else{
                error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::out);
                error<<"Error:position is out of map!!!";
                error.close();
                this->_player.move(direction, steps);

            }
   }
}

void World::monster1Move(int direction, int steps){
    vector<monster>::iterator it =_monsters1.begin();
    for(;it !=this->_monsters1.end();it++){
        (*it).move(direction, steps);

        if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==(this->_player.getPosY()+1)){
             _objs1.clear();//clear()删除vector中的所有元素
             _monsters1.clear();
             //delete (*it);
             exit(0);
        }
    }
}

void World::monster2Move(int direction, int steps){
    vector<monster>::iterator it =_monsters2.begin();
    for(;it !=this->_monsters2.end();it++){
        (*it).move(direction, steps);

        if((*it).getPosX()==this->_player.getPosX()&&(*it).getPosY()==(this->_player.getPosY()+1)){
            _objs2.clear();//clear()删除vector中的所有元素
             _monsters2.clear();
             exit(0);
        }
       // if(((*it).getPosX()==this->_bullet.getPosX())&&((*it).getPosY()==this->_bullet.getPosY()))
        /*if((this->_bullet.getPosX()==(*it).getPosX())&&(this->_bullet.getPosY()==(*it).getPosY()))
        {
            _monsters2.erase(it);
        }*/
        //(*it).move(direction, steps);
    }
}

void World::beat(){
     vector<monster>::iterator it=_monsters2.begin();
     for(;it !=this->_monsters2.end();it++){
         if((this->_bullet.getPosX()==(*it).getPosX())&&(this->_bullet.getPosY()==(*it).getPosY()))
         {
             _monsters2.erase(it); 
             monnum++;
             break;
         }
     }
}




