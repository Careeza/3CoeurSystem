#include "render.h"

CS_Renderer::CS_Renderer()
{
}

CS_Renderer::~CS_Renderer()
{
    SDL_DestroyTexture(screen);
    SDL_DestroyTexture(screenSave);
}

void    CS_Renderer::loadRenderer(SDL_Renderer *renderSource)
{
    int w;
    int h;

    render = renderSource;

    w = 1920;
    h = 1080;
    screen = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    screenSave = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    
    SDL_SetRenderTarget(render, screen); // => On va dessiner sur la texture
}