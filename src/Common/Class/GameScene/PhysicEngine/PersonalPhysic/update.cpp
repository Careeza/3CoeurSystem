# include "gameScene.h"

void    CS_PersonalPhysic::updateSpeed(int deltaT)
{
    speed.updateSpeed(WorldPhysics->QueryGravity(), deltaT);
}

void    CS_PersonalPhysic::updatePosition(CS_GameScene *scene, int deltaT)
{
    if (position.updatePosition(scene, hitbox, speed, deltaT))
    {
        onGround = true;
        setSpeedY(0);
    }
    else
        onGround = false;
}