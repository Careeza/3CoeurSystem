# include "gameScene.h"

void    CS_HitBox::moveX(int xSource)
{
    x += xSource;
}

void    CS_HitBox::moveY(int ySource)
{
    y += ySource;
}

void    CS_HitBox::extandW(int wSource)
{
    w += wSource;
}

void    CS_HitBox::extandH(int hSource)
{
    h += hSource;
}

void    CS_HitBox::extandSize(int wSource, int hSource)
{
    w += wSource;
    h += hSource;
}