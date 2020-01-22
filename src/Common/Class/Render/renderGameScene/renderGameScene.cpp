#include "render.h"

void    renderOnScreen(CS_OnScreen *onScreen, SDL_Renderer *render, int cameraX, int cameraY)
{
    SDL_Rect    rect;
    CS_Asset    *asset;

    int i;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);
        asset->QuerySize(rect.w, rect.h, rect.x, rect.y);
        rect.x -= cameraX;
        rect.y -= cameraY;
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
        SDL_RenderFillRect(render, &rect);
        i++;
    }
}

void    CS_Renderer::renderGameScene(CS_GameScene *gameScene)
{
    CS_Camera       *camera;
    int             cameraX;
    int             cameraY;

    camera = gameScene->QueryCamera();
    camera->QueryCameraPosition(cameraX, cameraY);

    if (gameScene->haveParallax())
        renderParallax(gameScene->QueryParallax());
    if (gameScene->haveAssets())
    {
        renderAssets(gameScene->QueryAssets(), cameraX, cameraY);
        renderOnScreen(gameScene->QueryOnScreen(), render, cameraX, cameraY);
    }

//    render(gameScene, render);

    if (gameScene->haveMC())
    {
        renderProjectiles(gameScene->QueryProjectile(), cameraX, cameraY);
        renderMC(gameScene->QueryMC(), cameraX, cameraY);
    }
    if (gameScene->haveEnemies())
        renderEnemy(gameScene->QueryEnemies(), cameraX, cameraY);
}