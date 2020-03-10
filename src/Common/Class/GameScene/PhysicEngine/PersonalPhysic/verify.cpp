# include "gameScene.h"

bool    CS_PersonalPhysic::verifyOnGround()
{
//    return (onGround);
    return (position.verifyOnGround());
}

bool    CS_PersonalPhysic::verifyBounciness()
{
    return (bounciness);
}

float       CS_PersonalPhysic::QueryGravity()
{
    return (gravity);
}
