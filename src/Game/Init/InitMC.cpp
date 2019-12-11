# include "gameScene.h"

CS_Animation        *staticMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, INTERRUPT);
    animation->loadTexture(render, MCSTATICL, MCSTATICR);
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0);
    animation->setSize(10, 10);

    return (animation);
}

CS_Animation        *walkMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKR);
    animation->cutFrame(6, 6, 1);
    animation->setSpeed(1);
    animation->setSize(10, 10);

    return (animation);
}

CS_Animation        *sprintMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(SPRINT, INTERRUPT);
    animation->loadTexture(render, MCWALKL, MCWALKR);
    animation->cutFrame(6, 6, 1);
    animation->setSpeed(1.5);
    animation->setSize(10, 10);

    return (animation);
}

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(45);
    physic->setPosY(90);
    
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
    MC->setPos(45, 90);
    
    return (MC);
}