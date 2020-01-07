# include "gameScene.h"

void    CS_Speed::updateSpeed(CS_Force force, float deltaT)
{
    force.usePhysic(vX, vY, deltaT);
}

void    CS_Speed::updateSpeed(int aXSource, int aYSource, float deltaT)
{
    vX += aXSource * deltaT;
    vY += aYSource * deltaT;
}


void    CS_Speed::moveObject(float &x, float &y, float deltaT)
{
    x += vX * deltaT;
    y += vY * deltaT;
}