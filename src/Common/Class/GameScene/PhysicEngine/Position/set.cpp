# include "gameScene.h"

void    CS_Position::setPositionX(float xSource)
{
    x = Tools->transformWidth(xSource);
}

void    CS_Position::setPositionY(float ySource)
{
    x = Tools->transformWidth(ySource);
}

void    CS_Position::setPositionXPixel(int xSource)
{
    x = xSource;
}

void    CS_Position::setPositionYPixel(int ySource)
{
    y = ySource;
}
