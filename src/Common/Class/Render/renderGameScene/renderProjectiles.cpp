#include "render.h"

void    CS_Renderer::renderProjectiles(CS_Projectiles *projectiles, int cameraX, int cameraY)
{
    CS_Projectile   *projectile;
    SDL_Texture     *texture;
    SDL_Rect        *frame;
    SDL_Rect        size;
    int             i;

    i = 0;

    while (i < projectiles->QueryNbProjectile())
    {
        projectile = projectiles->QueryProjectile(i);
        texture = projectile->QueryTexture();
        frame = projectile->QueryFrame();
        projectile->QuerySizePos(size.w, size.h, size.x, size.y);
        size.x -= cameraX;
        size.y -= cameraY;
        SDL_RenderCopy(render, texture, frame, &size);
        i++;
    }
}
