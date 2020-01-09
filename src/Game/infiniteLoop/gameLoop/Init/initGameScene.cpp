# include "game.h"

CS_GameScene    *initGameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->loadRenderer(render);

    scene->setBorneMap(-100000, 100000);
    scene->loadMC(initMC(render));
    scene->loadEnemies(initEnemies(render));
    scene->loadParallax(initParallax(render));
    scene->loadCamera(initCamera());
    scene->loadAssets(initAssets(render));
    
    return (scene);
}