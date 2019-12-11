# include "gameScene.h"

void    CS_Position::updatePosition(CS_Speed speed)
{
    speed.moveObject(x, y);

}

void    CS_Position::updatePosition(int vXSource, int vYSource)
{
    x += vXSource;
    y += vYSource;
}