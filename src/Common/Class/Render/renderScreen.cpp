#include "render.h"


void    CS_Renderer::dispScreen()
{
    SDL_SetRenderTarget(render, NULL);
    SDL_RenderCopy(render, screen, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_SetRenderTarget(render, screen);
}

void    CS_Renderer::saveScreen()
{
    SDL_SetRenderTarget(render, screenSave);
    SDL_RenderCopy(render, screen, NULL, NULL);
    SDL_SetRenderTarget(render, screen);    
}
