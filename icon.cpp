#include "icon.h"
#include<iostream>
#include <fstream>

extern fstream error;

int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",1,13, 1,2)),
    make_pair("stone",ICON("stone",4,9, 1,1)),
    make_pair("flower",ICON("flower",3,6, 1,1)),
    make_pair("ground",ICON("ground",5,0, 1,1)),
    make_pair("plant",ICON("plant",4,6, 1,1)),
    make_pair("grave",ICON("grave",6,9, 1,1)),
    make_pair("monster",ICON("monster",8,12, 1,1)),
    make_pair("2ground",ICON("2ground",7,1, 1,1)),
    make_pair("fence",ICON("fence",5,10,1,1)),
    make_pair("door",ICON("door",13,12,1,1)),
    make_pair("bullet",ICON("bullet",0,4,1,1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){
        error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::app);
        error<<"Error:invalid ICON type!!!"<<endl;
        error.close();
        return ICON();
    }
    else{
        return kv->second;
    }
}
