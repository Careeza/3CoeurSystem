# include "gameScene.h"

CS_Animation    *staticMC(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(STATIC, INTERRUPT);
    animation->loadTexture(render, MCSTATICL, MCSTATICR);
    animation->cutFrame(4, 4, 1);
    animation->setMovement(4, 0.0, 0.0, 0.0, 0.0);

    return (animation);
}

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
