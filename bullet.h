#ifndef BULLET_H
#define BULLET_H
#include "rpgobj.h"

class bullet:public RPGObj
{
public:
    bullet();
    ~bullet();
    void move(int direction);
    //void outmove();
/*private:
    int dirc;*/
    //direction =1,2,3,4 for 上下左右
};

#endif // BULLET_H
