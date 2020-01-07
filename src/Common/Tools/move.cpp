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
        x = BorderMinX;
    if (x + w > BorderMaxX)
        x = BorderMaxX - w;
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

void    checkBorder(int w, int BorderMinX, int BorderMaxX, CS_PersonalPhysic *physic)
{
    int x;

    x = physic->QueryPostionX();
    if (x < BorderMinX)
        physic->setPosXPixel(BorderMinX);
    if (x + w > BorderMaxX)
        physic->setPosXPixel(BorderMaxX - w);
}

void    checkGround(int h, CS_PersonalPhysic *physic)
{
    int y;

    y = physic->QueryPostionY();
    if (y + h > Tools->QueryWindowHeight())
    {
        physic->setPosYPixel(Tools->QueryWindowHeight() - h);
        physic->setOnGround(true);
        physic->setSpeedY(0);
    }
}

void    verifyHitbox(CS_PersonalPhysic *physic, int w, int h, int BorderMinX, int BorderMaxX)
{
    checkBorder(w, BorderMinX, BorderMaxX, physic);
    checkGround(h, physic);
}