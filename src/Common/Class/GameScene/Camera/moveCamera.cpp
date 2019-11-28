#include "gameScene.h"

void    CS_Camera::moveCamera(int xSource, int ySource)
{
    x = xSource;
    y = ySource;
}

void    CS_Camera::moveCamera2(int xSource, int ySource)
{
    x += xSource;
    y += ySource;
}
