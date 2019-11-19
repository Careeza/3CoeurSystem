#include "tools.h"

int     CS_Tools::transformWidth(float w)
{
    int res;
    res = (w * windowWidth) / 100.0;
    return (res);
}

int     CS_Tools::transformWidth(SDL_Rect *container, float w)
{
    int res;
    res = (w * container->w) / 100.0;
    return (res);
}
        
int     CS_Tools::transformHeight(float h)
{
    int res;
    res = (h * windowHeight) / 100.0;
    return (res);
}

int     CS_Tools::transformHeight(SDL_Rect *container, float h)
{
    int res;
    res = (h * container->h) / 100.0;
    return (res);
}

int     CS_Tools::transformX(float x)
{
    int res;
    res = (x * windowWidth) / 100.0;
    return (res);
}

int     CS_Tools::transformX(SDL_Rect *container, float x)
{
    int res;
    res = (x * container->w) / 100.0 + container->x;
    return (res);
}

int     CS_Tools::transformY(float y)
{
    int res;
    res = (y * windowHeight) / 100.0;
    return (res);
}

int     CS_Tools::transformY(SDL_Rect *container, float y)
{
    int res;
    res = (y * container->h) / 100.0 + container->y;
    return (res);
}