#include "render.h"

void    CS_Renderer::renderMC(CS_Character *MC, int cameraX, int cameraY)
{
    SDL_Texture     *texture;
    SDL_Rect        *frame;
    SDL_Rect        size;    

    texture = MC->QueryTexture();
    frame = MC->QueryFrame();
    MC->QuerySizePos(size.w, size.h, size.x, size.y);
    size.x -= cameraX;
    size.y -= cameraY;

    SDL_RenderCopy(render, texture, frame, &size);
}