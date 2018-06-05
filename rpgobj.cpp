#include "rpgobj.h"
#include <iostream>
#include <fstream>
extern fstream error;

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
           this->_coverable = false;
           this->_eatable = false;
       }
       else if (type.compare("stone")==0){
           this->_coverable = false;
           this->_eatable = false;
       }
       else if (type.compare("fence")==0){
           this->_coverable = false;
           this->_eatable = false;
       }
       else if (type.compare("flower")==0){
           this->_coverable = true;
           this->_eatable = true;
       }
       else if (type.compare("ground")==0){
           this->_coverable = true;
           this->_eatable = false;
       }
       else if (type.compare("plant")==0){
           this->_coverable = false;
           this->_eatable = false;
       }
       else if (type.compare("grave")==0){
           this->_coverable = true;
           this->_eatable = false;
       }
       else if (type.compare("monster")==0){
           this->_coverable = true;
           this->_eatable = false;
       }
       else if (type.compare("2ground")==0){
           this->_coverable = true;
           this->_eatable = false;
       }
       else if(type.compare("door")==0){
           this->_coverable=true;
           this->_eatable=false;
       }
       else if(type.compare("bullet")==0){
           this->_coverable=false;
           this->_eatable=false;
       }
       else{
            //TODO 应由专门的错误日志文件记录
           error.open("C:\\Users\\dell\\Desktop\\error.txt",ios::app);
           error<<"Error:invalid ICON type!!!"<<endl;
           error.close();
           return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("C:/Users/dell/Desktop/TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}
