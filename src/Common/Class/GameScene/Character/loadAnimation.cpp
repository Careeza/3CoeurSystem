# include "gameScene.h"

void        CS_Character::loadAnimation(t_animation name)
{
    animation = bank->QueryAnimationByname(name);
    physic->setSpeedX(animation->QueryMovementX(right));
    animation->restartAnimation();
    if (animation == NULL)
    {
        std::cout << "Error can't load the animation" << std::endl;
        exit (0);
    }
}

void        CS_Character::loadPhysic(CS_PersonalPhysic *physicSource)
{
    physic = physicSource;
}