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


void    CS_Camera::moveCamera3(CS_Character *MC)
{
    int wMC;
    int hMC;
    int xMC;
    int yMC;

    MC->QuerySizePos(wMC, hMC, xMC, yMC);
    x = xMC - (Tools->QueryWindowWidth() / 2) + (wMC / 2);
    y = 0;
}