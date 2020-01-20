# include "gameScene.h"

void        CS_Character::loadAnimation(t_animation name)
{
    CS_Animation    *newAnimation;

    if (moine)
        newAnimation = bankMoine->QueryAnimationByname(name);
    else
        newAnimation = bankKitsune->QueryAnimationByname(name);
    if (newAnimation == NULL)
    {
        std::cout << "error in loadAnimation => MC" << std::endl;
        exit (0);
    }
    if (newAnimation != animation)
    {
        animation = newAnimation;
        animation->restartAnimation();
    }
    physic->setSpeedX(animation->QueryMovementX(right));
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