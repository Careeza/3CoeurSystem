#include "gameScene.h"

void    CS_Camera::moveCamera(int xSource, int ySource)
{
    x = xSource;
    y = ySource;
}

void    CS_Camera::moveCamera2(int xSource, int ySource, CS_GameScene *map)
{
    x += xSource;
    y += ySource;
    moveWithTest(xSource > 0, Tools->QueryWindowWidth(), Tools->QueryWindowHeight(), x, y, map);
}