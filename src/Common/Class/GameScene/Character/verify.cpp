# include "gameScene.h"

bool    CS_Character::VerifyRight()
{
    return (right);
}

bool    CS_Character::verifyAnimationEnd()
{
    return (animation->verifyAnimationEnd());
}

bool    CS_Character::MCIsMoine()
{
    return (moine);
}

bool    CS_Character::verifyOnGround()
{
    return (physic->verifyOnGround());
}
