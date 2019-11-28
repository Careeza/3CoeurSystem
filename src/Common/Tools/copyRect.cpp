#include "tools.h"

void    CS_Tools::copyRect(SDL_Rect *rectSource, SDL_Rect *rectDest)
{
    rectDest->w = rectSource->w;
    rectDest->h = rectSource->h;
    rectDest->x = rectSource->x;
    rectDest->y = rectSource->y;
}
