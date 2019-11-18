# include "gameScene.h"

CS_Animation    *staticMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, INTERRUPT);
    animation->loadTexture(render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png");
    animation->cutFrame(1, 1, 1);
    animation->setMovement(1, 0.0);

    return (animation);
}

CS_Animation    *walkMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, INTERRUPT);
    animation->loadTexture(render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    animation->cutFrame(5, 5, 1);
    animation->setMovement(5, 1.0, 1.0, 1.0, 1.0, 1.0);

    return (animation);
}
