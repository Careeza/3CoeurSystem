# include "gameScene.h"

void    CS_Speed::updateSpeed(CS_Force force, int deltaT)
{
    force.usePhysic(vX, vY, deltaT);
}

void    CS_Speed::updateSpeed(float aXSource, float aYSource, int deltaT)
{
    vX += aXSource * deltaT;
    vY += aYSource * deltaT;
}


void    CS_Speed::moveObject(float &x, float &y, int deltaT)
{
    x += vX * (float)deltaT;
    y += vY * (float)deltaT;
}