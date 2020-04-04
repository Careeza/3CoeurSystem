# include "gameScene.h"


CS_Animation        *staticMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMCstaticL.png", "resources/source/MainCharacter/MoineV2/NewMCstaticR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *walkMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMC1RunL.png", "resources/source/MainCharacter/MoineV2/NewMC1RunR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(300);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *jumpMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(JUMP, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMC1JumpUPL.png", "resources/source/MainCharacter/MoineV2/NewMC1JumpUPR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *dashMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(DASH, false);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMC1DashL.png", "resources/source/MainCharacter/MoineV2/NewMC1DashR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0.12, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *fallMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(FALL, true);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMC1JumpDownL.png", "resources/source/MainCharacter/MoineV2/NewMC1JumpDownR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *attackMoine(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/MoineV2/NewMCattackL.png", "resources/source/MainCharacter/MoineV2/NewMCattackR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(2, 2, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(150);


    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    animation->setAttack(false, 0.119792, 0.5, 0.336806, 0.218056);
    animation->setAttack(true, 0.111111, 0.5, 0.545139, 0.215278);

    return (animation);
}
