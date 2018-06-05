#include "monster.h"
#include "icon.h"
#include <iostream>
#include <vector>
#include "world.h"
#include "mw1.h"
using namespace std;
//direction =1,2,3,4 for 上下左右

monster::monster(){

}
monster::~monster(){

}

void monster::move(int direction, int steps){
    int _x=0,_y=0;
    switch (direction){
        case 1:
            _x=0;
            _y=-steps;
            break;
        case 2:
            _x=0;
            _y=steps;
            break;
        case 3:
            _x=-steps;
            _y=0;
            break;
        case 4:
           _x=steps;
           _y=0;
           break;
    }
    //避免怪物跑出边界
    if(this->_pos_x+_x !=0&& this->_pos_x+_x !=24 && this->_pos_y+_y !=19 && this->_pos_y+_y !=0)
    {
         this->_pos_x += _x;
         this->_pos_y += _y;
    }
}
