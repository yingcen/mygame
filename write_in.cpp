#include "write_in.h"
#include <iostream>
#include <fstream>
using namespace std;

extern fstream write;

void write_in::write_player(string fileName){
     write.open(fileName.c_str(),ios::app);
     write<<"player "<<12<<" "<<9<<endl;
     write.close();
}

void write_in::write_ground(string fileName){//铺满小界面
    write.open(fileName.c_str(),ios::app);
    for(int i=0;i<25;i++){
            for(int j=0;j<20;j++){
                write<<"ground "<<i<<" "<<j<<endl;
            }
        }
    write.close();
}

void write_in::write_2ground(string fileName){
    write.open(fileName.c_str(),ios::app);
    for(int i=4;i<10;i++)
    {
        write<<"2ground "<<i<<" "<<4<<endl;
    }
    for(int i=4;i<16;i++)
    {
        write<<"2ground "<<3<<" "<<i<<endl;
    }
    for(int i=4;i<10;i++)
    {
        write<<"2ground "<<i<<" "<<15<<endl;
    }
    for(int i=16;i<22;i++)
    {
        write<<"2ground "<<i<<" "<<4<<endl;
    }
    for(int i=16;i<21;i++)
    {
        write<<"2ground "<<i<<" "<<9<<endl;
    }
    for(int i=15;i<21;i++)
    {
        write<<"2ground "<<i<<" "<<15<<endl;
    }
    for(int i=4;i<10;i++)
    {
        write<<"2ground "<<15<<" "<<i<<endl;
    }
    for(int i=9;i<16;i++)
    {
        write<<"2ground "<<21<<" "<<i<<endl;
    }
    write.close();
}

void write_in::write_door(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"door "<<1<<" "<<1<<endl;
    write.close();
}

void write_in::write_plant(string fileName){//  i横坐标，j纵坐标,画出植物围成的 ‘5’字形
    write.open(fileName.c_str(),ios::app);
    for(int i=1;i<8;i=i+2)
    {
        write<<"plant "<<12<<" "<<i<<endl;
    }
    for(int i=12;i<19;i=i+2)
    {
        write<<"plant "<<12<<" "<<i<<endl;
    }
    write<<"plant "<<1<<" "<<7<<endl;
    write<<"plant "<<2<<" "<<7<<endl;
    write<<"plant "<<2<<" "<<12<<endl;
    for(int i=5;i<10;i++)
    {
        write<<"plant "<<i<<" "<<7<<endl;
    }
    for(int i=4;i<9;i++)
    {
        write<<"plant "<<i<<" "<<5<<endl;
    }
    for(int i=4;i<11;i++)
    {
        write<<"plant "<<i<<" "<<12<<endl;
    }
    for(int i=2;i<8;i++)
    {
        write<<"plant "<<i<<" "<<2<<endl;
    }
    for(int i=15;i<21;i++)
    {
        write<<"plant "<<i<<" "<<10<<endl;
    }
    write<<"plant "<<22<<" "<<10<<endl;
    write<<"plant "<<23<<" "<<10<<endl;
    write<<"plant "<<16<<" "<<11<<endl;
    write<<"plant "<<20<<" "<<11<<endl;
    write<<"plant "<<17<<" "<<12<<endl;
    write<<"plant "<<19<<" "<<12<<endl;
    write<<"plant "<<18<<" "<<13<<endl;
    write<<"plant "<<15<<" "<<14<<endl;
    write<<"plant "<<16<<" "<<14<<endl;
    write<<"plant "<<17<<" "<<14<<endl;
    write<<"plant "<<20<<" "<<14<<endl;
    write<<"plant "<<15<<" "<<3<<endl;
    write<<"plant "<<16<<" "<<3<<endl;
    write<<"plant "<<20<<" "<<3<<endl;
    write<<"plant "<<21<<" "<<3<<endl;
    write.close();
}

void write_in::write_stone(string fileName){
    write.open(fileName.c_str(),ios::app);
    for(int i=1;i<24;i++){
        write<<"stone "<<i<<" "<<0<<endl;
        write<<"stone "<<i<<" "<<19<<endl;
    }
    for(int j=1;j<19;j++){
        write<<"stone "<<0<<" "<<j<<endl;
        write<<"stone "<<24<<" "<<j<<endl;
    }
    for(int i=2;i<9;i=i+2)
    {
        write<<"stone "<<12<<" "<<i<<endl;
    }
    for(int i=11;i<18;i=i+2)
    {
        write<<"stone "<<12<<" "<<i<<endl;
    }
    for(int i=2;i<11;i=i+2)
    {
        write<<"stone "<<i<<" "<<10<<endl;
    }
    write<<"stone "<<16<<" "<<12<<endl;
    write<<"stone "<<18<<" "<<12<<endl;
    write<<"stone "<<20<<" "<<12<<endl;
    write<<"stone "<<17<<" "<<13<<endl;
    write<<"stone "<<19<<" "<<13<<endl;
    write<<"stone "<<18<<" "<<14<<endl;
    write<<"stone "<<16<<" "<<6<<endl;
    write<<"stone "<<16<<" "<<7<<endl;
    write.close();
}

void write_in::write_flower(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"flower "<<12<<" "<<9<<endl;
    write<<"flower "<<2<<" "<<18<<endl;
    write<<"flower "<<3<<" "<<18<<endl;
    write<<"flower "<<21<<" "<<18<<endl;
    write<<"flower "<<22<<" "<<18<<endl;
    for(int i=4;i<10;i++)
    {
        write<<"flower "<<i<<" "<<4<<endl;
    }
    for(int i=4;i<16;i++)
    {
        write<<"flower "<<3<<" "<<i<<endl;
    }
    for(int i=4;i<10;i++)
    {
        write<<"flower "<<i<<" "<<15<<endl;
    }
    for(int i=16;i<22;i++)
    {
        write<<"flower "<<i<<" "<<4<<endl;
    }
    for(int i=16;i<21;i++)
    {
        write<<"flower "<<i<<" "<<9<<endl;
    }
    for(int i=15;i<21;i++)
    {
        write<<"flower "<<i<<" "<<15<<endl;
    }
    for(int i=4;i<10;i++)
    {
        write<<"flower "<<15<<" "<<i<<endl;
    }
    for(int i=9;i<16;i++)
    {
        write<<"flower "<<21<<" "<<i<<endl;
    }
    for(int i=3;i<9;i++)
    {
        write<<"flower "<<13<<" "<<i<<endl;
    }
    for(int i=7;i<12;i++)
    {
        write<<"flower "<<i<<" "<<18<<endl;
    }
    write.close();
}

void write_in::write_fence(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"fence "<<1<<" "<<10<<endl;
    for(int i=5;i<12;i=i+2)
    {
        write<<"fence "<<i<<" "<<10<<endl;
    }
    for(int i=2;i<11;i=i+2)
    {
        write<<"fence "<<i<<" "<<9<<endl;
    }
    for(int i=4;i<11;i++)
    {
        write<<"fence "<<i<<" "<<14<<endl;
    }
    for(int i=2;i<11;i++)
    {
        write<<"fence "<<i<<" "<<16<<endl;
    }
    for(int i=4;i<11;i++)
    {
        write<<"fence "<<i<<" "<<3<<endl;
    }
    for(int i=1;i<17;i++)
    {
        write<<"fence "<<14<<" "<<i<<endl;
    }
    for(int i=15;i<19;i++)
    {
        write<<"fence "<<i<<" "<<16<<endl;
    }
    for(int i=20;i<24;i++)
    {
        write<<"fence "<<i<<" "<<16<<endl;
    }
    for(int i=2;i<10;i++)
    {
        write<<"fence "<<22<<" "<<i<<endl;
    }
    for(int i=16;i<22;i++)
    {
        write<<"fence "<<i<<" "<<5<<endl;
    }
    for(int i=17;i<22;i++)
    {
        write<<"fence "<<i<<" "<<8<<endl;
    }
    write<<"fence "<<4<<" "<<6<<endl;
    write<<"fence "<<4<<" "<<7<<endl;
    write<<"fence "<<4<<" "<<8<<endl;
    write.close();
}

void write_in::write_grave(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"grave "<<2<<" "<<13<<endl;
    write<<"grave "<<2<<" "<<14<<endl;
    write<<"grave "<<10<<" "<<15<<endl;
    write<<"grave "<<2<<" "<<4<<endl;
    write<<"grave "<<2<<" "<<5<<endl;
    write<<"grave "<<10<<" "<<6<<endl;
    write<<"grave "<<11<<" "<<2<<endl;
    write<<"grave "<<11<<" "<<3<<endl;
    write<<"grave "<<22<<" "<<12<<endl;
    write<<"grave "<<22<<" "<<13<<endl;
    write<<"grave "<<22<<" "<<14<<endl;
    write<<"grave "<<22<<" "<<15<<endl;
    write<<"grave "<<17<<" "<<3<<endl;
    write<<"grave "<<18<<" "<<3<<endl;
    write<<"grave "<<19<<" "<<3<<endl;
    write<<"grave "<<19<<" "<<14<<endl;
    write<<"grave "<<1<<" "<<18<<endl;
    write<<"grave "<<23<<" "<<18<<endl;
    write<<"grave "<<4<<" "<<11<<endl;
    write<<"grave "<<4<<" "<<13<<endl;
    write<<"grave "<<2<<" "<<6<<endl;
    write<<"grave "<<2<<" "<<8<<endl;
    write.close();
}

void write_in::wrtie_pend(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"MONSTER"<<endl;
    write.close();
}

void write_in::write_monster(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"monster "<<18<<" "<<13<<endl;
    write<<"monster "<<6<<" "<<3<<endl;
    write.close();
}


void write_in::write_end(string fileName){
    write.open(fileName.c_str(),ios::app);
    write<<"EOF"<<endl;
    write.close();
}
