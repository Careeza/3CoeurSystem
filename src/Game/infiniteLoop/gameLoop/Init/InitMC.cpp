# include "gameScene.h"

CS_Animation        *staticKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2staticL.png", "resources/source/MainCharacter/Kitsune/MC2staticR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(0, true, 0.121528, 0.594444, 0.456597, 0.155556);
    animation->setHitBox(1, true, 0.121528, 0.563889, 0.456597, 0.186111);
    animation->setHitBox(2, true, 0.121528, 0.563889, 0.456597, 0.186111);
    animation->setHitBox(3, true, 0.121528, 0.563889, 0.456597, 0.186111);
    animation->setHitBox(4, true, 0.121528, 0.563889, 0.456597, 0.186111);

    animation->setHitBox(0, false, 0.121528, 0.594444, 0.421875, 0.155556);
    animation->setHitBox(1, false, 0.121528, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(2, false, 0.121528, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(3, false, 0.121528, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(4, false, 0.121528, 0.563889, 0.421875, 0.186111);

    return (animation);
}

CS_Animation        *walkKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2HrunL.png", "resources/source/MainCharacter/Kitsune/MC2HrunR.png");
    animation->setSize(20, 20);
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(400);

    animation->setHitBox(0, true, 0.157986, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(1, true, 0.175347, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(2, true, 0.175347, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(3, true, 0.229167, 0.669444, 0.402778, 0.155556);

    animation->setHitBox(0, false, 0.157986, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(1, false, 0.175347, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(2, false, 0.175347, 0.669444, 0.439236, 0.155556);
    animation->setHitBox(3, false, 0.229167, 0.669444, 0.402778, 0.155556);

    return (animation);
}

CS_Animation        *jumpKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(JUMP, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2jumpL.png", "resources/source/MainCharacter/Kitsune/MC2jumpR.png");
    animation->setSize(20, 20);
    animation->cutFrame(2, 2, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(200);

    animation->setHitBox(0, true, 0.121528, 0.563889, 0.456597, 0.186111);
    animation->setHitBox(1, true, 0.121528, 0.563889, 0.456597, 0.186111);

    animation->setHitBox(0, false, 0.121528, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(1, false, 0.104167, 0.563889, 0.421875, 0.186111);

    return (animation);
}

CS_Animation        *attackKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/Kitsune/MC2attackL.png", "resources/source/MainCharacter/Kitsune/MC2attackR.png");
    animation->setSize(20, 20);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(300);

    animation->setHitBox(0, true, 0.121528, 0.563889, 0.456597, 0.186111);
    animation->setHitBox(1, true, 0.104167, 0.563889, 0.473958, 0.186111);
    animation->setHitBox(2, true, 0.104167, 0.563889, 0.456597, 0.186111);

    animation->setHitBox(0, false, 0.121528, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(1, false, 0.104167, 0.563889, 0.421875, 0.186111);
    animation->setHitBox(2, false, 0.104167, 0.563889, 0.439236, 0.186111);

    return (animation);
}
CS_Animation        *jumpMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(JUMP, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCjumpL.png", "resources/source/MainCharacter/Moine/MCjumpR.png");
    animation->setSize(20, 20);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(0, true, 0.121528, 0.594444, 0.439236, 0.125);
    animation->setHitBox(1, true, 0.121528, 0.594444, 0.439236, 0.125);
    animation->setHitBox(2, true, 0.121528, 0.594444, 0.439236, 0.125);

    animation->setHitBox(0, false, 0.121528, 0.594444, 0.439236, 0.125);
    animation->setHitBox(1, false, 0.121528, 0.594444, 0.439236, 0.125);
    animation->setHitBox(2, false, 0.121528, 0.594444, 0.439236, 0.125);

    return (animation);
}

CS_Animation        *staticMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCstaticL.png", "resources/source/MainCharacter/Moine/MCstaticR.png");
    animation->setSize(20, 20);
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(0, true, 0.138889, 0.594444, 0.421875, 0.125);
    animation->setHitBox(1, true, 0.138889, 0.563889, 0.421875, 0.155556);
    animation->setHitBox(2, true, 0.138889, 0.533333, 0.421875, 0.186111);
    animation->setHitBox(3, true, 0.138889, 0.563889, 0.421875, 0.155556);

    animation->setHitBox(0, false, 0.138889, 0.594444, 0.439236, 0.125);
    animation->setHitBox(1, false, 0.138889, 0.563889, 0.439236, 0.155556);
    animation->setHitBox(2, false, 0.138889, 0.533333, 0.439236, 0.186111);
    animation->setHitBox(3, false, 0.138889, 0.563889, 0.439236, 0.155556);

    return (animation);
}

CS_Animation        *walkMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCrunL.png", "resources/source/MainCharacter/Moine/MCrunR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(400);

    animation->setHitBox(0, true, 0.138889, 0.655556, 0.4375, 0.0930556);
    animation->setHitBox(1, true, 0.15625, 0.655556, 0.421875, 0.0930556);
    animation->setHitBox(2, true, 0.15625, 0.655556, 0.421875, 0.0930556);
    animation->setHitBox(3, true, 0.229167, 0.655556, 0.385417, 0.0930556);
    animation->setHitBox(4, true, 0.138889, 0.655556, 0.4375, 0.0930556);

    animation->setHitBox(0, false, 0.138889, 0.655556, 0.4375, 0.0930556);
    animation->setHitBox(1, false, 0.15625, 0.655556, 0.421875, 0.0930556);
    animation->setHitBox(2, false, 0.15625, 0.655556, 0.421875, 0.0930556);
    animation->setHitBox(3, false, 0.229167, 0.655556, 0.385417, 0.0930556);
    animation->setHitBox(4, false, 0.138889, 0.655556, 0.4375, 0.0930556);

    return (animation);
}

CS_Animation        *attackMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/Moine/MCpunchL.png", "resources/source/MainCharacter/Moine/MCpunchR.png");
    animation->setSize(20, 20);
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(0, true, 0.140625, 0.594444, 0.420139, 0.125);
    animation->setHitBox(1, true, 0.140625, 0.561111, 0.420139, 0.155556);
    animation->setHitBox(2, true, 0.140625, 0.591667, 0.420139, 0.125);

    animation->setHitBox(0, false, 0.104167, 0.594444, 0.439236, 0.125);
    animation->setHitBox(1, false, 0.121528, 0.563889, 0.439236, 0.155556);
    animation->setHitBox(2, false, 0.138889, 0.594444, 0.439236, 0.125);

    return (animation);
}

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(20);
    physic->setPosY(10);
    
    return (physic);
}

CS_Character        *initMC(SDL_Renderer *render)
{
    CS_Character *MC;

    MC = new(CS_Character);

    MC->setMC(KITSUNE);
    MC->addAnimation(render, staticKitsune);
    MC->addAnimation(render, walkKitsune);
    MC->addAnimation(render, jumpKitsune);
    MC->addAnimation(render, attackKitsune);

    MC->setMC(MOINE);
    MC->addAnimation(render, staticMoine);
    MC->addAnimation(render, walkMoine);
    MC->addAnimation(render, attackMoine);
    MC->addAnimation(render, jumpMoine);

    MC->loadAnimation(STATIC);
    MC->loadPhysic(initPhysic());
    
    return (MC);
}