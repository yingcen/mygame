#ifndef WRITE_WIN_H
#define WRITE_WIN_H
#include<string>
using namespace std;


class write_win
{
public:
    write_win(){}
    void write_flower(string fileName);
    void write_end(string fileName);



    void write_all(string fileName){
        write_flower(fileName);
        write_end(fileName);
    }
};

#endif // WRITE_WIN_H
