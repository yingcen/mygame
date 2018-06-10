#include "write_win.h"
#include <iostream>
#include <fstream>
using namespace std;

extern fstream _win;

void write_win::write_flower(string fileName){
     _win.open(fileName.c_str(),ios::app);
     for(int i=5;i<10;i++)
     {
         _win<<"flower "<<2<<" "<<i<<endl;
         _win<<"flower "<<10<<" "<<i<<endl;
     }
     for(int i=10;i<14;i++)
     {
         _win<<"flower "<<3<<" "<<i<<endl;
         _win<<"flower "<<9<<" "<<i<<endl;
     }
     for(int i=6;i<14;i++)
     {
         _win<<"flower "<<5<<" "<<i<<endl;
         _win<<"flower "<<7<<" "<<i<<endl;
     }
     _win<<"flower "<<4<<" "<<14<<endl;
     _win<<"flower "<<6<<" "<<5<<endl;
     _win<<"flower "<<8<<" "<<14<<endl;
     _win<<"flower "<<13<<" "<<5<<endl;
     for(int i=7;i<15;i++)
     {
         _win<<"flower "<<13<<" "<<i<<endl;
     }
     for(int i=5;i<15;i++)
     {
         _win<<"flower "<<16<<" "<<i<<endl;
         _win<<"flower "<<20<<" "<<i<<endl;
     }
     for(int i=16;i<21;i++)
     {
         _win<<"flower "<<i<<" "<<5<<endl;
     }
     _win.close();
}


void write_win::write_end(string fileName){
    _win.open(fileName.c_str(),ios::app);
    _win<<"EOF"<<endl;
    _win.close();
}
