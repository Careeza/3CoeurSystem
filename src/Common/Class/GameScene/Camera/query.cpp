#include "gameScene.h"

void    CS_Camera::QueryCameraPosition(int& xDest, int& yDest)
{
    xDest = x;
    yDest = y;
}


int     CS_Camera::QueryCameraPositionX()
{
    return (x);
}

int     CS_Camera::QueryCameraPositionY()
{
    return (y);
}
