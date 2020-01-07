# include "gameScene.h"

void    CS_Position::updatePosition(CS_Speed speed, float deltaT)
{
    speed.moveObject(x, y, deltaT);
}

void    CS_Position::updatePosition(int vXSource, int vYSource, float deltaT)
{
    x += vXSource * deltaT;
    y += vYSource * deltaT;
}