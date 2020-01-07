# include "gameScene.h"

CS_Animation        *staticMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MCstaticL.png", "resources/source/MainCharacter/MCstaticR.png");
    animation->setSize(20, 20);
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    return (animation);
}

CS_Animation        *walkMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/runLMC.png", "resources/source/MainCharacter/runRMC.png");
    animation->setSize(20, 20);
    animation->cutFrame(8, 8, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(600);

    return (animation);
}

CS_Animation        *sprintMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(SPRINT, true);
    animation->loadTexture(render, MCWALKL, MCWALKR);
    animation->setSize(10, 10);
    animation->cutFrame(6, 6, 1);
    animation->setSpeed(15, 0);
    animation->setAnimationTime(542);

    return (animation);
}

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(40);
    physic->setPosY(0);
    
    return (physic);
}

CS_Character        *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->addAnimation(render, staticMC);
    MC->addAnimation(render, walkMC);
    MC->addAnimation(render, sprintMC);
    MC->loadAnimation(STATIC);
    MC->loadPhysic(initPhysic());
    
    return (MC);
}