#include "render.h"

void    CS_Renderer::renderText(CS_Police *text)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = text->QueryTexte();
    size = text->QuerySize();
    SDL_RenderCopy(render, texture, NULL, size);
}
