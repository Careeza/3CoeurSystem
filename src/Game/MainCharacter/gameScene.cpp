# include "gameScene.h"

CS_Animation    *staticMC(SDL_Renderer *render);
CS_Animation    *walkMC(SDL_Renderer *render);

void            initMC(SDL_Renderer *render, CS_GameScene *scene)
{
    CS_Character *MC;

    scene->loadMC(2, staticMC, walkMC);
    MC = scene->CS_queryMC();
    MC->loadAnimation(STATIC);
    std::cout << Tools->QueryWindowResolution() << " <- game res" << std::endl;
    MC->setSize(10, 10 * Tools->QueryWindowResolution(), 45, 90 - (5 * Tools->QueryWindowResolution()));

}

CS_GameScene    *init_gameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/gameBackground.jpg", 100, 100, 0, 0, 0);
    initMC(render, scene);
    return (scene);
}

CS_GameScene::CS_GameScene()
{
    MC = new(CS_Character);
//    enemies = new(CS_Enemies);
}

CS_GameScene::~CS_GameScene()
{
    delete MC;
//    delete enemies;
}