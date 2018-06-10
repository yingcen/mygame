#ifndef WRITE_IN_H
#define WRITE_IN_H
#include<string>
using namespace std;

class write_in
{
public:
    write_in(){}
    void write_player(string fileName);
    void write_ground(string fileName);
    void write_2ground(string fileName);
    void write_door(string fileName);
    void write_plant(string fileName);
    void write_stone(string fileName);
    void write_flower(string fileName);
    void write_fence(string fileName);
    void write_grave(string fileName);
    void wrtie_pend(string fileName);
    void write_monster(string fileName);
    void write_end(string fileName);


    void write_all(string fileName){
        write_player(fileName);
        write_ground(fileName);
        write_2ground(fileName);
        write_door(fileName);
        write_plant(fileName);
        write_stone(fileName);
        write_flower(fileName);
        write_fence(fileName);
        write_grave(fileName);
        wrtie_pend(fileName);
        write_monster(fileName);
        write_end(fileName);
    }
};

#endif // WRITE_IN_H
