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
    animation->loadTexture(render, "resources/source/MainCharacter/MCrunL.png", "resources/source/MainCharacter/MCrunR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(400);

    return (animation);
}

CS_Animation        *attackMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/MCpunchL.png", "resources/source/MainCharacter/MCpunchR.png");
    animation->setSize(20, 20);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(300);

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
    MC->addAnimation(render, attackMC);

    MC->loadAnimation(STATIC);
    MC->loadPhysic(initPhysic());
    
    return (MC);
}