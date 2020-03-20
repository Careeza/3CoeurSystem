#include "gameScene.h"


void    CS_Layer::moveLayer(int xSource)
{
    int     windowW;
    int     windowH;
    int     x;

    scopeX = xSource * speed;
    x = Tools->modulo(scopeX, textureW);

    windowW = 1920;
    windowH = 1080;

    if (x + scopeWidth > textureW)
    {
        scopeMain->w = scopeWidth - (x + scopeWidth - textureW);
        scopeMain->h = scopeHeight;
        scopeMain->x = x;
        scopeMain->y = 0;

        scopeSecond->w = x + scopeWidth - textureW;
        scopeSecond->h = scopeHeight;
        scopeSecond->x = 0;
        scopeSecond->y = 0;

        sizeMain->w = windowW * (scopeMain->w / (float)scopeWidth);
        sizeMain->h = windowH;
        sizeMain->x = 0;
        sizeMain->y = 0;

        sizeSecond->w = windowW - sizeMain->w;
        sizeSecond->h = windowH;
        sizeSecond->x = sizeMain->w;
        sizeSecond->y = 0;

        needSecondScope = true;
    }
    else
    {
        scopeMain->w = scopeWidth;
        scopeMain->h = scopeHeight;
        scopeMain->x = x;
        scopeMain->y = 0;

        sizeMain->w = windowW;
        sizeMain->h = windowH;
        sizeMain->x = 0;
        sizeMain->y = 0;

        needSecondScope = false;
    }
}
