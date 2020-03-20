# include "gameScene.h"

void    CS_Force::usePhysic(float& vXDest, float& vYDest, int deltaT)
{
    vXDest += aX * deltaT;
    vYDest += aY * deltaT;
}
