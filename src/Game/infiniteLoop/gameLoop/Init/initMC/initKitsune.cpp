# include "gameScene.h"

CS_Animation        *staticKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/MainCharacter/KitsuneV2/NewMC2staticL.png", "resources/source/MainCharacter/KitsuneV2/NewMC2staticR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *walkKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/MainCharacter/KitsuneV2/NewMC2runL.png", "resources/source/MainCharacter/KitsuneV2/NewMC2runR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(4, 4, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(400);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *jumpKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(JUMP, true);
    animation->loadTexture(render, "resources/source/MainCharacter/KitsuneV2/NewMC2jumpUPL.png", "resources/source/MainCharacter/KitsuneV2/NewMC2jumpUPR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(200);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *fallKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(FALL, true);
    animation->loadTexture(render, "resources/source/MainCharacter/KitsuneV2/NewMC2jumpDownL.png", "resources/source/MainCharacter/KitsuneV2/NewMC2jumpDownR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(300);


    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *attackKitsune(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(ATTACK, false);
    animation->loadTexture(render, "resources/source/MainCharacter/KitsuneV2/NewMC2attackL.png", "resources/source/MainCharacter/KitsuneV2/NewMC2attackR.png");
    animation->setSize(28, 14 * Tools->QueryWindowResolution());
    animation->cutFrame(3, 3, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(300);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}
