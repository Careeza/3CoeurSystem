#include "tools.h"

float   CS_Tools::transformWidth(float w)
{
    float res;
    res = (w * 1920) / 100.0;
    return (res);
}

float   CS_Tools::transformWidth(SDL_Rect *container, float w)
{
    float res;
    res = (w * container->w) / 100.0;
    return (res);
}
        
float   CS_Tools::transformHeight(float h)
{
    float res;
    res = (h * 1080) / 100.0;
    return (res);
}

float   CS_Tools::transformHeight(SDL_Rect *container, float h)
{
    float res;
    res = (h * container->h) / 100.0;
    return (res);
}

float   CS_Tools::transformX(float x)
{
    float res;
    res = (x * 1920) / 100.0;
    return (res);
}

float   CS_Tools::transformX(SDL_Rect *container, float x)
{
    float res;
    res = (x * container->w) / 100.0 + container->x;
    return (res);
}

float   CS_Tools::transformY(float y)
{
    float res;
    res = (y * 1080) / 100.0;
    return (res);
}

float   CS_Tools::transformY(SDL_Rect *container, float y)
{
    float res;
    res = (y * container->h) / 100.0 + container->y;
    return (res);
}
