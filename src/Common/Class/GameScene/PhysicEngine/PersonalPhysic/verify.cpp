# include "gameScene.h"

bool    CS_PersonalPhysic::verifyOnGround()
{
    return (onGround);
}

bool    CS_PersonalPhysic::verifyBounciness()
{
    return (bounciness);
}

float       CS_PersonalPhysic::QueryGravity()
{
    return (gravity);
}
