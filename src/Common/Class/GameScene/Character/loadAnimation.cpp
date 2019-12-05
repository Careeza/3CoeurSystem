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

void        CS_Character::setSizePos(float wSource, float hSource, float xSource, float ySource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);
    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}

void        CS_Character::setSize(float wSource, float hSource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);
}

void        CS_Character::setPos(float xSource, float ySource)
{
    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}