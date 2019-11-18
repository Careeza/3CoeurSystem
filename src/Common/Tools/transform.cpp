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