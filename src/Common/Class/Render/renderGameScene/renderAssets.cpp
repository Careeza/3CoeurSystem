#include "render.h"

void    CS_Renderer::renderAssets(CS_Assets *assets, int cameraX, int cameraY)
{
    CS_Asset        *asset;
    SDL_Texture     *texture;
    SDL_Rect        size;
    int             i;

    i = 0;

    while (i < assets->QueryNbAssets())
    {
        asset = assets->QueryAsset(i);
        texture = asset->QueryTexture();
        asset->QuerySize(size.w, size.h, size.x, size.y);
        size.x -= cameraX;
        size.y -= cameraY;
        SDL_RenderCopy(render, texture, NULL, &size);
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
//        SDL_RenderDrawRect(render, &size);
//        renderHitBox(asset->QueryHitBox(), render, &size, cameraX, cameraY);
        i++;
    }
}
