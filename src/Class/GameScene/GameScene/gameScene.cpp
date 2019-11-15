# include "gameScene.h"

CS_GameScene    *init_gameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/gameBackground.jpg", 100, 100, 0, 0, 0);
    scene->loadMC();
    scene->loadEnemies();
    scene->CS_queryMC()->loadAnimation("noMove");
    return (scene);
}

CS_GameScene::CS_GameScene()
{
    MC = new(CS_Character);
    enemies = new(CS_Enemies);
}

CS_GameScene::~CS_GameScene()
{
    delete MC;
    delete enemies;
}