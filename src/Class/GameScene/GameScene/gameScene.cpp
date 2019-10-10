# include "gameScene.h"

CS_GameScene    *init_gameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/gameBackground.jpg", 100, 100, 0, 0, 0);
    return (scene);
}
