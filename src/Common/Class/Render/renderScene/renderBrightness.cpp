#include "render.h"

void    CS_Renderer::renderBrightness(CS_Brightness *brightness)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = brightness->QueryTexture();
    size = brightness->QuerySize();
    SDL_RenderCopy(render, texture, NULL, size);
}