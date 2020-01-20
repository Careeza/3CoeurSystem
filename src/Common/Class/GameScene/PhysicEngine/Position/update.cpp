# include "gameScene.h"

void    CS_Position::updatePosition(CS_Speed speed, int deltaT)
{
    speed.moveObject(x, y, deltaT);
}

void    CS_Position::updatePosition(float vXSource, float vYSource, int deltaT)
{
    x += vXSource * deltaT;
    y += vYSource * deltaT;
}