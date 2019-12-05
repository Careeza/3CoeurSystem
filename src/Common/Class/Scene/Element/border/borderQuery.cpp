#include "scene.h"

SDL_Rect    *CS_Border::QueryRectUp()
{
    return (rectUp);
}

SDL_Rect    *CS_Border::QueryRectDown()
{
    return (rectDown);
}

SDL_Rect    *CS_Border::QueryRectRight()
{
    return (rectRight);
}

SDL_Rect    *CS_Border::QueryRectLeft()
{
    return (rectLeft);
}

SDL_Texture *CS_Border::QueryTexture()
{
    return (texture);
}