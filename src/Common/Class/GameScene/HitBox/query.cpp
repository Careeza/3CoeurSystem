# include "gameScene.h"

int     CS_HitBox::QueryW()
{
    return (w);
}

int     CS_HitBox::QueryH()
{
    return (h);
}

int     CS_HitBox::QueryX()
{
    return (x);
}

int     CS_HitBox::QueryY()
{
    return (y);
}

void    CS_HitBox::QuerySize(int& wDest, int& hDest)
{
    wDest = w;
    hDest = h;
}

void    CS_HitBox::QueryPos(int& xDest, int &yDest)
{
    xDest = x;
    yDest = y;
}

void    CS_HitBox::QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest)
{
    wDest = w;
    hDest = h;
    xDest = x;
    yDest = y;
}

float   CS_HitBox::QueryWProp()
{
    return(wProp);
}

float   CS_HitBox::QueryHProp()
{
    return (hProp);
}

float   CS_HitBox::QueryXProp()
{
    return (xProp);
}

float   CS_HitBox::QueryYProp()
{
    return (yProp);
}