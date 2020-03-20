#include "render.h"

void    CS_Renderer::renderElement(std::shared_ptr<CS_Element> element)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = element->QueryElementTexture();
    size = element->QueryElementSize();
    SDL_RenderCopy(render, texture, NULL, size);
}
