#include "gameScene.h"


void    checkBorder(int w, int h, int &x, int &y, CS_GameScene *map)
{
    int BorderMaxX;
    int BorderMinX;

    //TODO Y AND H
    (void)y;
    (void)h;
    map->QueryBorne(BorderMinX, BorderMaxX);
//    std::cout << "the born are: MAX = " << BorderMaxX << " MIN = " << BorderMinX << std::endl;
//    std::cout << "the camera is here: X = " << x << " Y = " << y << std::endl;
    if (x < BorderMinX)
    {
//        std::cout << "x to small" << std::endl;
        x = BorderMinX;
    }
    if (x + w > BorderMaxX)
    {
//        std::cout << "x to big" << std::endl;
        x = BorderMaxX - w;
    }
}

void    moveWithTest(bool right, int w, int h, int& x, int &y, CS_GameScene *map)
{
    checkBorder(w, h, x, y, map);
    if (right)
    {
    }
    else
    {
    }
}