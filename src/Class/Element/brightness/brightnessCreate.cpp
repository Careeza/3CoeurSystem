#include "scene.h"

void            CS_Brightness::CS_initBright(SDL_Renderer *render, CS_Color color)
{
    surface = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);
    if (!surface)
    {
        std::cout << "error creating surface" << std::endl;
        exit (0);
    }
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, color.CS_queryRed(), color.CS_queryGreen(), color.CS_queryBlue(), color.CS_queryAlpha()));
    if (!surface)
    {
        std::cout << "error filling surface" << std::endl;
        exit (0);
    }
    texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

void            CS_Brightness::addBrillance(SDL_Rect *size)
{
    rect->w = size->w;
    rect->h = size->h;
    rect->x = size->x;
    rect->y = size->y;
}