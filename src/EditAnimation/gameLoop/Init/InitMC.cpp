# include "gameScene.h"

CS_Animation        *staticKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2staticL.png", "resources/source/MainCharacter/Kitsune/MC2staticR.png");
    animation->setSize(40, 40);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    return (animation);
}

CS_Animation        *walkKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2HtoFandrunL.png", "resources/source/MainCharacter/Kitsune/MC2HtoFandrunR.png");
    animation->setSize(40, 40);
    animation->cutFrame(18, 18, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(1200, 12);

    return (animation);
}


CS_Animation        *fallMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(FALL, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCfallL.png", "resources/source/MainCharacter/Moine/MCfallR.png");
    animation->setSize(40, 40);
    animation->cutFrame(2, 2, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(200);

    return (animation);
}

CS_Animation        *jumpMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(JUMP, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCjumpL.png", "resources/source/MainCharacter/Moine/MCjumpR.png");
    animation->setSize(40, 40);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(300);

    return (animation);
}

CS_Animation        *staticMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCstaticL.png", "resources/source/MainCharacter/Moine/MCstaticR.png");
    animation->setSize(40, 40);
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    return (animation);
}

CS_Animation        *walkMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCrunL.png", "resources/source/MainCharacter/Moine/MCrunR.png");
    animation->setSize(40, 40);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(30, 0);
    animation->setAnimationTime(400);

    animation->setHitBox(0, true, 0.138889, 0.656944, 0.438368, 0.0930556);
    animation->setHitBox(1, true, 0.15625, 0.656944, 0.421875, 0.0930556);
    animation->setHitBox(2, true, 0.15625, 0.625, 0.421875, 0.125);
    animation->setHitBox(3, true, 0.229167, 0.594444, 0.385417, 0.155556);
    animation->setHitBox(4, true, 0.138889, 0.625, 0.438368, 0.125);


    animation->setHitBox(0, false, 0.138889, 0.656944, 0.438368, 0.0930556);
    animation->setHitBox(1, false, 0.15625, 0.656944, 0.421875, 0.0930556);
    animation->setHitBox(2, false, 0.15625, 0.625, 0.421875, 0.125);
    animation->setHitBox(3, false, 0.229167, 0.594444, 0.385417, 0.155556);
    animation->setHitBox(4, false, 0.138889, 0.625, 0.438368, 0.125);

    return (animation);
}

CS_Animation        *attackMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCpunchL.png", "resources/source/MainCharacter/Moine/MCpunchR.png");
    animation->setSize(40, 40);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0, 0);
    animation->setHitBox(0, true, 0.228299, 0.593056, 0.421007, 0.125);
    animation->setHitBox(1, true, 0.140625, 0.5625, 0.421007, 0.155556);
    animation->setHitBox(2, true, 0.140625, 0.593056, 0.421007, 0.125);
    animation->setAnimationTime(300);

    return (animation);
}

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(22.5);
    physic->setPosY(30);
    
    return (physic);
}

CS_Character        *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->setMC(KITSUNE);
    MC->addAnimation(render, staticKitsune);
    MC->addAnimation(render, walkKitsune);

    MC->setMC(MOINE);
    MC->addAnimation(render, staticMoine);
    MC->addAnimation(render, walkMoine);
    MC->addAnimation(render, attackMoine);
    MC->addAnimation(render, fallMoine);
    MC->addAnimation(render, jumpMoine);

    MC->loadAnimation(STATIC);
    MC->loadPhysic(initPhysic());
    
    return (MC);
}