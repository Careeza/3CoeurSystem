# include "gameScene.h"

void        CS_Character::loadAnimation(t_animation name)
{
    animation = bank->CS_queryAnimationByname(name);
    animation->restartAnimation();

    if (animation == NULL)
    {
        std::cout << "Error can't load the animation" << std::endl;
        exit (0);
    }
}

void        CS_Character::setSize(float w, float h, float x, float y)
{   
    Tools->setSize(size, w, h, x, y);
}
