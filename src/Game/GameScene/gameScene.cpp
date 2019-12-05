# include "gameScene.h"

CS_Animation    *staticMC(SDL_Renderer *render);
CS_Animation    *walkMC(SDL_Renderer *render);

CS_Animation    *sprintMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(SPRINT, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKR);
    animation->cutFrame(6, 6, 1);
    animation->setMovement(6, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5);

    return (animation);
}

CS_Character    *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->addAnimation(render, staticMC);
    MC->addAnimation(render, walkMC);
    MC->addAnimation(render, sprintMC);
    MC->loadAnimation(STATIC);
    MC->setSizePos(10, 10, 45, 90);
    
    return (MC);
}

CS_Animation    *walkClone(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKL);
    animation->cutFrame(6, 6, 1);
    animation->setMovement(6, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

    return (animation);
}

CS_Animation    *walkClone2(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKL);
    animation->cutFrame(6, 6, 1);
    animation->setMovement(6, 1.25, 1.25, 1.25, 1.25, 1.25, 1.25);

    return (animation);
}

void                algoFuite(CS_Character *enemy, CS_Character *MC)
{
    int         enemyPos;
    int         MCPos;
    int         i;

    enemy->QueryPos(enemyPos, i);
    MC->QueryPos(MCPos, i);

    enemy->loadAnimation(WALK);
    enemy->setRight(false);
//    enemy->useAnimation();
}

void                algoClone1(CS_Character *enemy, CS_Character *MC)
{
    int         enemyPos;
    int         MCPos;
    int         i;

    enemy->QueryPos(enemyPos, i);
    MC->QueryPos(MCPos, i);


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
//    enemy->useAnimation();
}

void                algoClone2(CS_Character *enemy, CS_Character *MC)
{
    int         enemyPos;
    int         MCPos;
    int         i;

    enemy->QueryPos(enemyPos, i);
    MC->QueryPos(MCPos, i);


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
}

CS_Character        *initClone1(SDL_Renderer *render)
{
    CS_Character *clone;

    clone = new(CS_Character);

    clone->addAnimation(render, staticMC);
    clone->addAnimation(render, walkClone);
    clone->loadAnimation(STATIC);
    clone->setSizePos(10, 10, 45, 90);
    
    return (clone);
}

CS_Character        *initClone2(SDL_Renderer *render)
{
    CS_Character *clone;

    clone = new(CS_Character);

    clone->addAnimation(render, staticMC);
    clone->addAnimation(render, walkClone2);
    clone->loadAnimation(STATIC);
    clone->setSizePos(10, 10, 45, 90);
    
    return (clone);
}

CS_Enemies      *initEnemies(SDL_Renderer *render)
{
    CS_Enemies  *enemies;
    int         i;

    i = 10;
    enemies = new (CS_Enemies);

    enemies->addEnemy(render, initClone1, algoFuite, 30, 90);
/*    while (i < 95)
    {
        if (rand() % 2 == 0)
            enemies->addEnemy(render, initClone1, algoFuite, i, 90);
        else
            enemies->addEnemy(render, initClone2, algoFuite, i, 90);
        i += 2;
    }*/

    return (enemies);
}

CS_Parallax     *initParallax(SDL_Renderer *render)
{
    CS_Parallax *parallax;


    parallax = new (CS_Parallax);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer0.png", 0.0625, 0);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer1.png", 0.125, 1);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer2.png", 0.25, 2);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer3.png", 0.5, 3);

    return (parallax);
}

CS_Camera       *initCamera()
{
    CS_Camera *camera;

    camera = new (CS_Camera);
    return (camera);
}

CS_GameScene    *init_gameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/gameBackground.jpg", 100, 100, 0, 0, 0);
    scene->setBorneMap(-100000, 100000);
    scene->loadMC(initMC(render));
    scene->loadEnemies(initEnemies(render));
    scene->loadParallax(initParallax(render));
    scene->loadCamera(initCamera());

    return (scene);
}