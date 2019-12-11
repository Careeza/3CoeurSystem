#include "gameScene.h"


void    checkBorder(int w, int h, int &x, int &y, CS_GameScene *map)
{
    int BorderMaxX;
    int BorderMinX;

    //TODO Y AND H
    (void)y;
    (void)h;
    map->QueryBorne(BorderMinX, BorderMaxX);
    if (x < BorderMinX)
    {
        x = BorderMinX;
    }
    if (x + w > BorderMaxX)
    {
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