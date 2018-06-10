#include "two_write_in.h"
#include <iostream>
#include <fstream>
using namespace std;

extern fstream two_write;

void two_write_in::write_player(string fileName){
     two_write.open(fileName.c_str(),ios::app);
     two_write<<"player "<<12<<" "<<9<<endl;
     two_write.close();
}


void two_write_in::write_2ground(string fileName){//铺满小界面
    two_write.open(fileName.c_str(),ios::app);
    for(int i=0;i<25;i++){
        for(int j=0;j<20;j++){
            two_write<<"2ground "<<i<<" "<<j<<endl;
        }
    }
    two_write<<"door "<<23<<" "<<18<<endl;
    two_write.close();
}

void two_write_in::write_fence(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    for(int i=1;i<24;i++){
        two_write<<"fence "<<i<<" "<<0<<endl;
        two_write<<"fence "<<i<<" "<<19<<endl;
    }
    for(int j=1;j<19;j++){
        two_write<<"fence "<<0<<" "<<j<<endl;
        two_write<<"fence "<<24<<" "<<j<<endl;
    }
    for(int i=1;i<16;i=i+2)
    {
        two_write<<"fence "<<3<<" "<<i<<endl;
    }
    for(int i=4;i<19;i=i+2)
    {
        two_write<<"fence "<<21<<" "<<i<<endl;
    }
    two_write.close();
}

void two_write_in::write_stone(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    for(int i=2;i<15;i=i+2)
    {
        two_write<<"stone "<<3<<" "<<i<<endl;
    }
    for(int i=5;i<18;i=i+2)
    {
        two_write<<"stone "<<21<<" "<<i<<endl;
    }
    for(int i=1;i<8;i=i+2)
    {
        two_write<<"stone "<<9<<" "<<i<<endl;
    }
    for(int i=12;i<19;i=i+2)
    {
        two_write<<"stone "<<15<<" "<<i<<endl;
    }
    two_write.close();
}

void two_write_in::write_plant(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    for(int i=2;i<9;i=i+2)
    {
        two_write<<"plant "<<9<<" "<<i<<endl;
    }
    for(int i=11;i<18;i=i+2)
    {
        two_write<<"plant "<<15<<" "<<i<<endl;
    }
    for(int i=6;i<13;i++)
    {
        two_write<<"plant "<<i<<" "<<14<<endl;
    }
    for(int i=12;i<19;i++)
    {
        two_write<<"plant "<<i<<" "<<5<<endl;
    }
    two_write.close();
}

void two_write_in::write_grave(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    for(int i=3;i<7;i++)
    {
        two_write<<"grave "<<i<<" "<<17<<endl;
    }
    for(int i=14;i<18;i++)
    {
        two_write<<"grave "<<i<<" "<<8<<endl;
    }
    two_write.close();
}

void two_write_in::write_pend(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    two_write<<"MONSTER"<<endl;
    two_write.close();
}

void two_write_in::write_monster(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    two_write<<"monster "<<18<<" "<<13<<endl;
    two_write<<"monster "<<2<<" "<<16<<endl;
    two_write<<"monster "<<12<<" "<<1<<endl;
    two_write<<"monster "<<7<<" "<<5<<endl;
    two_write<<"monster "<<1<<" "<<17<<endl;
    two_write<<"monster "<<18<<" "<<2<<endl;
    two_write.close();
}

void two_write_in::write_end(string fileName){
    two_write.open(fileName.c_str(),ios::app);
    two_write<<"EOF"<<endl;
    two_write.close();
}
