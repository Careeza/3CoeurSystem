# include "gameScene.h"

void    CS_PersonalPhysic::updateSpeed(int deltaT)
{
    speed.updateSpeed(WorldPhysics->QueryGravity(), deltaT);
}

void    CS_PersonalPhysic::updatePosition(int deltaT)
{
    position.updatePosition(speed, deltaT);
}