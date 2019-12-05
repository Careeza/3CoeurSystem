#include "editAnimation.h"

CS_Animation    *walkMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKR);
    animation->cutFrame(6, 6, 1);
    animation->setMovement(6, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

    return (animation);
}

CS_Character    *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->addAnimation(render, walkMC);
    MC->loadAnimation(WALK);
    MC->setSizePos(10, 10, 32.5, 45);
    MC->getFrame();
    
    return (MC);
}

CS_GameScene    *init_home(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->CS_setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);
//    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);

    scene->CS_createElementToScene("backGround", 75, 100, 0, 0, 0);
    scene->CS_createElementToScene("backGround", 25, 100, 75, 0, 0);
    scene->CS_addBorder(-1);
    scene->CS_createButtonToSceneFromPng("Asset1", "resources/source/greenCube.png", 12.5, 10, 75, 0, 1, &nextFrame);
    scene->CS_createButtonToSceneFromPng("Asset2", "resources/source/greenCube.png", 12.5, 10, 87.5, 0, 1, &previousFrame);
    scene->CS_createButtonToSceneFromPng("Asset3", "resources/source/greenCube.png", 12.5, 10, 75, 10, 1, &play);
    scene->CS_createButtonToSceneFromPng("Asset4", "resources/source/greenCube.png", 12.5, 10, 87.5, 10, 1, &pause);
    scene->CS_createButtonToSceneFromPng("Asset5", "resources/source/greenCube.png", 12.5, 10, 75, 20, 1, &left);
    scene->CS_createButtonToSceneFromPng("Asset6", "resources/source/greenCube.png", 12.5, 10, 87.5, 20, 1, &right);
    scene->CS_createButtonToSceneFromPng("Asset7", "resources/source/greenCube.png", 12.5, 10, 75, 30, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset8", "resources/source/greenCube.png", 12.5, 10, 87.5, 30, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset9", "resources/source/greenCube.png", 12.5, 10, 75, 40, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset10", "resources/source/greenCube.png",  12.5, 10, 87.5, 40, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset11", "resources/source/greenCube.png",  12.5, 10, 75, 50, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset12", "resources/source/greenCube.png",  12.5, 10, 87.5, 50, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset13", "resources/source/greenCube.png",  12.5, 10, 75, 60, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset14", "resources/source/greenCube.png",  12.5, 10, 87.5, 60, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset15", "resources/source/greenCube.png",  12.5, 10, 75, 70, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset16", "resources/source/greenCube.png",  12.5, 10, 87.5, 70, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset17", "resources/source/greenCube.png",  12.5, 10, 75, 80, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset18", "resources/source/greenCube.png",  12.5, 10, 87.5, 80, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset19", "resources/source/greenCube.png",  12.5, 10, 75, 90, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset20", "resources/source/greenCube.png",  12.5, 10, 87.5, 90, 1, &closeGame);

    scene->setBorneMap(0, 1000);
    scene->loadMC(initMC(render));
    scene->loadCamera(initCamera());

    return (scene);
}