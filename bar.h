#ifndef BAR__H
#define BAR__H
#include<iostream>
#include<SDL.h>

using namespace std;
class bar
{
private:
    int z;
public:
    bar();
    int x,y;
    SDL_Rect barRect;
    void updatePos();
};
#endif
