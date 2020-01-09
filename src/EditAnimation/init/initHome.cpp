#include "editAnimation.h"

CS_Animation        *walkMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MCrunL.png", "resources/source/MainCharacter/MCrunR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(542);

    return (animation);
}

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(32.5);
    physic->setPosY(45);
    
    return (physic);
}

CS_Character    *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->addAnimation(render, walkMC);
    MC->loadAnimation(WALK);
    MC->getFrame();
    MC->loadPhysic(initPhysic());

    return (MC);
}

CS_GameScene    *init_home(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);
//    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);

    scene->createElementToScene("backGround", 75, 100, 0, 0, 0);
    scene->createElementToScene("backGround", 25, 100, 75, 0, 0);
    scene->addBorder(-1);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->createButtonToScene("Asset1", 12.5, 10, 75, 0, 1, &nextFrame);
    scene->writeTexte(-1, ">");
    scene->createButtonToScene("Asset2", 12.5, 10, 87.5, 0, 1, &previousFrame);
    scene->writeTexte(-1, "<");
    scene->createButtonToScene("Asset3", 12.5, 10, 75, 10, 1, &play);
    scene->writeTexte(-1, "Go");
    scene->createButtonToScene("Asset4", 12.5, 10, 87.5, 10, 1, &pause);
    scene->writeTexte(-1, "||");
    scene->createButtonToScene("Asset5", 12.5, 10, 75, 20, 1, &left);
    scene->writeTexte(-1, "left");
    scene->createButtonToScene("Asset6", 12.5, 10, 87.5, 20, 1, &right);
    scene->writeTexte(-1, "right");
    scene->createButtonToScene("Asset7", 12.5, 10, 75, 30, 1, &incraseFps);
    scene->writeTexte(-1, "+fps");
    scene->createButtonToScene("Asset8", 12.5, 10, 87.5, 30, 1, &decreaseFps);
    scene->writeTexte(-1, "-fps");
    scene->createButtonToScene("Asset9", 12.5, 10, 75, 40, 1, &incraseFps10);
    scene->writeTexteScaleW(-1, "++fps");
    scene->createButtonToScene("Asset10", 12.5, 10, 87.5, 40, 1, &decreaseFps10);
    scene->writeTexteScaleW(-1, "--fps");
    scene->createButtonToScene("Asset11", 12.5, 10, 75, 50, 1, &incraseFps100);
    scene->writeTexteScaleW(-1, "+++fps");
    scene->createButtonToScene("Asset12",  12.5, 10, 87.5, 50, 1, &decreaseFps100);
    scene->writeTexteScaleW(-1, "---fps");
    scene->setTextColor(0x00, 0x00, 0x00, 0xFF);
    scene->createButtonToSceneFromPng("Asset13", "resources/source/greenCube.png",  12.5, 10, 75, 60, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset14", "resources/source/greenCube.png",  12.5, 10, 87.5, 60, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset15", "resources/source/greenCube.png",  12.5, 10, 75, 70, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset16", "resources/source/greenCube.png",  12.5, 10, 87.5, 70, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset17", "resources/source/greenCube.png",  12.5, 10, 75, 80, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset18", "resources/source/greenCube.png",  12.5, 10, 87.5, 80, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset19", "resources/source/greenCube.png",  12.5, 10, 75, 90, 1, &closeGame);
    scene->createButtonToSceneFromPng("Asset20", "resources/source/greenCube.png",  12.5, 10, 87.5, 90, 1, &closeGame);

    scene->setSceneColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->createElementToScene("fps", 10, 10, 0, 0, 0);
    scene->writeTexte(-1, "542");

    scene->setBorneMap(0, 1000);
    scene->loadMC(initMC(render));
    scene->loadCamera(initCamera());

    return (scene);
}