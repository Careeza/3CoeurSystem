#include "render.h"

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
        renderAssets(gameScene->QueryAssets(), cameraX, cameraY);

//    render(gameScene, render);

    if (gameScene->haveMC())
        renderMC(gameScene->QueryMC(), cameraX, cameraY);
    if (gameScene->haveEnemies())
        renderEnemy(gameScene->QueryEnemies(), cameraX, cameraY);
}