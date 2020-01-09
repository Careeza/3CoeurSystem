# include "gameScene.h"

bool    CS_Character::VerifyRight()
{
    return (right);
}

bool    CS_Character::verifyAnimationEnd()
{
    return (animation->verifyAnimationEnd());
}