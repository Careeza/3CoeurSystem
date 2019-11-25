# include "gameScene.h"

CS_Animation    *staticMC(SDL_Renderer *render);
CS_Animation    *walkMC(SDL_Renderer *render);

CS_Character    *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->addAnimation(render, staticMC);
    MC->addAnimation(render, walkMC);
    MC->loadAnimation(STATIC);
    MC->setSize(10, 10 * Tools->QueryWindowResolution(), 45, 90 - (5 * Tools->QueryWindowResolution()));
    
    return (MC);
}

CS_Animation    *walkClone1(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    animation->cutFrame(5, 5, 1);
    animation->setMovement(5, 0.5, 0.5, 0.5, 0.5, 0.5);

    return (animation);
}

CS_Animation    *walkClone2(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    animation->cutFrame(5, 5, 1);
    animation->setMovement(5, 0.75, 0.75, 0.75, 0.75, 0.75);

    return (animation);
}

void                algoClone1(CS_Character *enemy, CS_Character *MC)
{
    int         enemyPos;
    int         MCPos;

    enemyPos = enemy->querySize()->x;
    MCPos = MC->querySize()->x;

    if (enemyPos > MCPos && (enemyPos - MCPos) > 100)
    {
        enemy->loadAnimation(WALK);
        enemy->setRight(false);
    }
    else if (enemyPos < MCPos && (MCPos - enemyPos) > 100)
    {
            enemy->loadAnimation(WALK);
            enemy->setRight(true);
    }
    else
    {
            enemy->loadAnimation(STATIC);
    }
    enemy->useAnimation();
}

void                algoClone2(CS_Character *enemy, CS_Character *MC)
{
    int         enemyPos;
    int         MCPos;

    enemyPos = enemy->querySize()->x;
    MCPos = MC->querySize()->x;

    if (enemyPos > MCPos && (enemyPos - MCPos) > 200)
    {
        enemy->loadAnimation(WALK);
        enemy->setRight(false);
    }
    else if (enemyPos < MCPos && (MCPos - enemyPos) > 200)
    {
            enemy->loadAnimation(WALK);
            enemy->setRight(true);
    }
    else
    {
            enemy->loadAnimation(STATIC);
    }
    enemy->useAnimation();
}

CS_Character        *initClone1(SDL_Renderer *render)
{
    CS_Character *clone;

    clone = new(CS_Character);

    clone->addAnimation(render, staticMC);
    clone->addAnimation(render, walkClone1);
    clone->loadAnimation(STATIC);
    clone->setSize(10, 10 * Tools->QueryWindowResolution(), 45, 90 - (5 * Tools->QueryWindowResolution()));
    
    return (clone);
}

CS_Character        *initClone2(SDL_Renderer *render)
{
    CS_Character *clone;

    clone = new(CS_Character);

    clone->addAnimation(render, staticMC);
    clone->addAnimation(render, walkClone2);
    clone->loadAnimation(STATIC);
    clone->setSize(10, 10 * Tools->QueryWindowResolution(), 45, 90 - (5 * Tools->QueryWindowResolution()));
    
    return (clone);
}

CS_Enemies      *initEnemies(SDL_Renderer *render)
{
    CS_Enemies *enemies;

    enemies = new (CS_Enemies);
    enemies->addEnemy(render, initClone1, algoClone1, 10, 90 - (5 * Tools->QueryWindowResolution()));
    enemies->addEnemy(render, initClone2, algoClone2, 85, 90 - (5 * Tools->QueryWindowResolution()));
    return (enemies);
}

CS_GameScene    *init_gameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/gameBackground.jpg", 100, 100, 0, 0, 0);
    scene->loadMC(initMC(render));
    scene->loadEnemies(initEnemies(render));

    return (scene);
}

CS_GameScene::CS_GameScene()
{
//    enemies = new(CS_Enemies);
}

CS_GameScene::~CS_GameScene()
{
    delete MC;
//    delete enemies;
}