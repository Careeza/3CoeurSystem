# include "gameScene.h"

void    CS_HitBox::setW(float wSource)
{
    w = Tools->transformWidth(wSource);
}

void    CS_HitBox::setH(float hSource)
{
    h = Tools->transformHeight(hSource);
}

void    CS_HitBox::setX(float xSource)
{
    x = Tools->transformX(xSource);
}

void    CS_HitBox::setY(float ySource)
{
    y = Tools->transformY(ySource);
}
