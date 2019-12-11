# include "gameScene.h"

void    CS_Force::usePhysic(int& vXDest, int& vYDest, float deltaT)
{
    vXDest += aX * deltaT;
    vYDest += aY * deltaT;
}