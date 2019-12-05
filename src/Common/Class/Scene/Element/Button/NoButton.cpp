#include "scene.h"

CS_NoButton::CS_NoButton()
{
    buttonSize = new (SDL_Rect);
    Tools->setSize(buttonSize, 0, 0, 0, 0);
}

CS_NoButton::~CS_NoButton()
{
    delete buttonSize;
}

void    setNoButtonSize(float w, float h, float x, float y, SDL_Rect *buttonSize)
{
    Tools->verbose(LEVEL3, "s", "--start DEBUG Size--");
    Tools->verbose(LEVEL3, "sffff", "size receive =", w, h, x, y);
    Tools->setSize(buttonSize, w, h, x, y);
    Tools->verbose(LEVEL3, "sdddd", "size of the button =", buttonSize->w, buttonSize->h, buttonSize->x, buttonSize->y);
    Tools->verbose(LEVEL3, "s", "--end DEBUG Size--\n\n");
}

void    CS_NoButton::resizePixel(int w, int h, int x, int y)
{
    buttonSize->w = w;
    buttonSize->h = h;
    buttonSize->x = x;
    buttonSize->y = y;
}


void    CS_NoButton::resize(float w, float h, float x, float y)
{
    setNoButtonSize(w, h, x, y, buttonSize);
}

Uint32  setNoButtonColor(CS_Color colorSource, SDL_Surface *surface)
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

void    CS_NoButton::addNoButtonFromHand(CS_Color colorSource, SDL_Renderer *render, float w, float h, float x, float y)
{
    Uint32  color;

    setNoButtonSize(w, h, x, y, buttonSize);
    noButtonSurface = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);
    if (!noButtonSurface)
    {
        std::cout << "error creating surface" << std::endl;
        exit (0);
    }
    color = setNoButtonColor(colorSource, noButtonSurface);
    SDL_FillRect(noButtonSurface, NULL, color);
    if (!noButtonSurface)
    {
        std::cout << "error filling surface" << std::endl;
        exit (0);
    }
    noButtonTexture = SDL_CreateTextureFromSurface(render, noButtonSurface);
	SDL_FreeSurface(noButtonSurface);
}

void    CS_NoButton::addNoButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y)
{
    setNoButtonSize(w, h, x, y, buttonSize);
    noButtonSurface = IMG_Load(route.c_str());
    if (!noButtonSurface)
    {
        std::cout << "error creating surface" << std::endl;
        exit (0);
    }
    noButtonTexture = SDL_CreateTextureFromSurface(render, noButtonSurface);
	SDL_FreeSurface(noButtonSurface);
}


SDL_Texture *CS_NoButton::QueryNoButtonTexture()
{
    return (noButtonTexture);
}

SDL_Rect    *CS_NoButton::QuerySize()
{
    return (buttonSize);
}