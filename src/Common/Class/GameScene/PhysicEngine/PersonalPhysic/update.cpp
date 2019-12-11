# include "gameScene.h"

void    CS_PersonalPhysic::updateSpeed(float deltaT)
{
    if (gravity)
        speed.updateSpeed(WorldPhysics->QueryGravity(), deltaT);
}

void    CS_PersonalPhysic::updatePosition(float deltaT)
{
    position.updatePosition(speed, deltaT);
}