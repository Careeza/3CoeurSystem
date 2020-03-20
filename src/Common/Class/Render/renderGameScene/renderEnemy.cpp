#include "render.h"

void    CS_Renderer::renderEnemy(CS_Enemies *enemies, int cameraX, int cameraY)
{
    CS_Enemy        *enemy;
    SDL_Texture     *texture;
    SDL_Rect        *frame;
    SDL_Rect        size;
    int             i;

    i = 0;

    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        texture = enemy->QueryTexture();
        frame = enemy->QueryFrame();
        enemy->QuerySizePos(size.w, size.h, size.x, size.y);
        size.x -= cameraX;
        size.y -= cameraY;

        SDL_SetRenderDrawColor(render, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawRect(render, &size);

        SDL_RenderCopy(render, texture, frame, &size);
        i++;
    }
}
