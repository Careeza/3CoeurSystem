# include "gameScene.h"

void    CS_HitBox::setHitBoxSize(float wSource, float hSource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);
}

void    CS_HitBox::setHitBoxPos(float xSource, float ySource)
{
    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}

void    CS_HitBox::setHitBox(float wSource, float hSource, float xSource, float ySource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);
    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}