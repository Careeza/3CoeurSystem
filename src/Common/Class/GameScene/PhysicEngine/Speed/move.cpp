# include "gameScene.h"

void    CS_Speed::updateSpeed(CS_Force force)
{

}

void    CS_Speed::updateSpeed(int aXSource, int aYSource)
{
    vX += aXSource;
    vY += aYSource;
}


void    CS_Speed::moveObject(int &x, int &y)
{
    x += vX;
    y += vY;
}