# include "gameScene.h"

void    CS_HitBox::setHitBoxSizePixel(int wSource, int hSource)
{
    w = wSource;
    h = hSource;
}

void    CS_HitBox::setHitBoxPosPixel(int xSource, int ySource)
{
    x = xSource;
    y = ySource;
}

void    CS_HitBox::setHitBoxPixel(int wSource, int hSource, int xSource, int ySource)
{
    w = wSource;
    h = hSource;
    x = xSource;
    y = ySource;
}
