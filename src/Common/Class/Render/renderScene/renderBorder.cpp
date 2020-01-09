#include "render.h"

void    CS_Renderer::renderBorder(CS_Border *border)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = border->QueryTexture();
    size = border->QueryRectUp();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectDown();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectRight();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectLeft();
    SDL_RenderCopy(render, texture, NULL, size);
}