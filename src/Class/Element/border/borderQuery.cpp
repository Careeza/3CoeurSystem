#include "scene.h"

SDL_Rect    *CS_Border::CS_queryRectUp()
{
    return (rectUp);
}

SDL_Rect    *CS_Border::CS_queryRectDown()
{
    return (rectDown);
}

SDL_Rect    *CS_Border::CS_queryRectRight()
{
    return (rectRight);
}

SDL_Rect    *CS_Border::CS_queryRectLeft()
{
    return (rectLeft);
}

SDL_Texture *CS_Border::CS_queryTexture()
{
    return (texture);
}