# include "gameScene.h"

void    CS_Position::setPositionX(float xSource)
{
    x = Tools->transformWidth(xSource);
}

void    CS_Position::setPositionY(float ySource)
{
    y = Tools->transformHeight(ySource);
}

void    CS_Position::setPositionXPixel(float xSource)
{
    x = xSource;
}

void    CS_Position::setPositionYPixel(float ySource)
{
    y = ySource;
}
