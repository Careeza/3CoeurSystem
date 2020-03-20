#include "scene.h"

void        CS_Border::createRect(SDL_Rect *rect, int w, int h, int x, int y)
{
    rect->w = w;
    rect->h = h;
    rect->x = x;
    rect->y = y;
}

Uint32  setColor(CS_Color colorSource, SDL_Surface *surface)
{
    int     red;
    int     green;
    int     blue;
    int     alpha;
    Uint32  color;

    red = colorSource.QueryRed();
    green = colorSource.QueryGreen();
    blue = colorSource.QueryBlue();
    alpha = colorSource.QueryAlpha();
    color = SDL_MapRGBA(surface->format, red, green, blue, alpha);
    return (color);
}

void        CS_Border::createTexture(CS_Color colorSource, SDL_Renderer *render)
{
    Uint32  color;

    surface = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);
    if (!surface)
    {
        std::cout << "error creating surface" << std::endl;
        exit (0);
    }
    color = setColor(colorSource, surface);
    SDL_FillRect(surface, NULL, color);
    if (!surface)
    {
        std::cout << "error filling surface" << std::endl;
        exit (0);
    }
    texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

void        CS_Border::createBorder(SDL_Rect *elementSize)
{
    createRect(rectUp, elementSize->w + 2 * borderSize_w, borderSize_h, elementSize->x - borderSize_w, elementSize->y - borderSize_h);
    createRect(rectDown, elementSize->w + 2 * borderSize_w, borderSize_h, elementSize->x - borderSize_w, elementSize->y + elementSize->h);
    createRect(rectRight, borderSize_w, elementSize->h + borderSize_h * 2, elementSize->x + elementSize->w, elementSize->y - borderSize_h);
    createRect(rectLeft, borderSize_w, elementSize->h + borderSize_h * 2, elementSize->x - borderSize_w, elementSize->y - borderSize_h);
}
