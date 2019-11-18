#include "tools.h"

void    CS_Tools::setSize(SDL_Rect *size, float w, float h, float x, float y)
{
    size->w = (w * windowWidth) / 100.0;
    size->h = (h * windowHeight) / 100.0;
    size->x = (x * windowWidth) / 100.0;
    size->y = (y * windowHeight) / 100.0;
}

void    CS_Tools::setSize(SDL_Rect *size, SDL_Rect *container, float w, float h, float x, float y)
{
    size->w = (w * container->w) / 100.0;
    size->h = (h * container->h) / 100.0;
    size->x = (x * container->w) / 100.0 + container->x;
    size->y = (y * container->h) / 100.0 + container->y;
}

void    CS_Tools::setSize(SDL_Rect *size, int w, int h, int x, int y)
{
    size->w = w;
    size->h = h;
    size->x = x;
    size->y = y;
}