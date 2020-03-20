#include "render.h"

void    CS_Renderer::renderTexture(SDL_Texture *texture, SDL_Rect *frame, SDL_Rect *size)
{
    SDL_RenderCopy(render, texture, frame, size);
}

void    CS_Renderer::renderScreenSave()
{
    SDL_RenderCopy(render, screenSave, NULL, NULL);
}
