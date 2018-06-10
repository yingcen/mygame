#include "bullet.h"

bullet::bullet()
{

}

bullet::~bullet()
{

}

//direction =1,2,3,4 for 上下左右
void bullet::move(int direction){
    switch (direction){
        case 1:
            this->_pos_y--;
            break;
        case 2:
            this->_pos_y++;
            break;
        case 3:
            this->_pos_x--;
            break;
        case 4:
            this->_pos_x++;
            break;
    }
}


