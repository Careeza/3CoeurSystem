#include "render.h"

void    drawHitBox(CS_PersonalPhysic *physic, int cameraX, int cameraY, SDL_Renderer *render)
{
    SDL_Rect    rect;

    SDL_SetRenderDrawColor(render, 0x00, 0xFF, 0x00, 0xFF);
    physic->QueryHitBox(rect.w, rect.h, rect.x, rect.y);
    rect.x -= cameraX;
    rect.y -= cameraY;
    SDL_RenderDrawRect(render, &rect);
    SDL_SetRenderDrawColor(render, 0xFF, 0x00, 0x00, 0xFF);
    physic->QueryAttack(rect.w, rect.h, rect.x, rect.y);
    rect.x -= cameraX;
    rect.y -= cameraY;
    SDL_RenderDrawRect(render, &rect);
}

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
//    drawHitBox(MC->QueryPhysic(), cameraX, cameraY, render);
}