# include "gameScene.h"

void    CS_Position::QueryPostion(int& xDest, int& yDest)
{
    xDest = x;
    yDest = y;
}

int     CS_Position::QueryPostionX()
{
    return (x);
}

int     CS_Position::QueryPostionY()
{
    return (y);
}

bool    CS_Position::verifyOnGround()
{
    return (onGround);
}