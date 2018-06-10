#ifndef TWO_WRITE_IN_H
#define TWO_WRITE_IN_H
#include<string>
using namespace std;

class two_write_in
{
public:
    two_write_in(){}
    void write_player(string fileName);
    void write_2ground(string fileName);
    void write_fence(string fileName);
    void write_stone(string fileName);
    void write_plant(string fileName);
    void write_grave(string fileName);
    void write_pend(string fileName);
    void write_monster(string fileName);
    void write_end(string fileName);

    void write_all(string fileName){
        write_player(fileName);
        write_2ground(fileName);
        write_fence(fileName);
        write_stone(fileName);
        write_plant(fileName);
        //write_monster(fileName);
        //write_flower(fileName);
        write_grave(fileName);
        write_pend(fileName);
        write_monster(fileName);
        write_end(fileName);
    }

};

#endif // TWO_WRITE_IN_H
