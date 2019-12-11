# include "gameScene.h"

void        CS_Character::loadAnimation(t_animation name)
{
    CS_Animation            *tmp;

    tmp = bank->QueryAnimationByname(name);
    if (tmp != saveAnimation)
    {
        animation = tmp;
        animation->restartAnimation();
        saveAnimation = animation;
    }
    else
    {
        animation->nextFrame();
    }
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


void        CS_Character::setPas(float pasSource)
{
    std::cout << pasSource << std::endl;
    animation->setPas(pasSource);
}


void        CS_Character::setPos(float xSource, float ySource)
{
    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}