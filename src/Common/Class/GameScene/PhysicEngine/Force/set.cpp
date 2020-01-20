# include "gameScene.h"

void    CS_Force::setAccelerationX(float aXsource)
{
    aX = Tools->transformWidth(aXsource);
}

void    CS_Force::setAccelerationY(float aYsource)
{
    aY = Tools->transformHeight(aYsource);
}

void    CS_Force::setAccelerationXPixel(float aXsource)
{
    aX = aXsource;
}

void    CS_Force::setAccelerationYPixel(float aYsource)
{
    aY = aYsource;
}