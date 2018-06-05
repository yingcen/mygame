#include "bullet.h"

bullet::bullet()
{

}

bullet::~bullet()
{

}

//direction =1,2,3,4 for 上下左右
void bullet::move(int direction, int steps){
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
    //if(this->_pos_x+_x !=0&& this->_pos_x+_x !=24 && this->_pos_y+_y !=19 && this->_pos_y+_y !=0)
    //{
         this->_pos_x += _x;
         this->_pos_y += _y;
    //}
}
