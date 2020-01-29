# include "gameScene.h"

void    CS_PersonalPhysic::updateSpeed(int deltaT)
{
    CS_Force    force;
    float       ax;
    float       ay;

    force = WorldPhysics->QueryGravity();
    ax = force.QueryAX();
    ay = force.QueryAY();

    ax *= gravity;
    ay *= gravity;

    speed.updateSpeed(ax, ay, deltaT);
}

void    CS_PersonalPhysic::updatePosition(CS_GameScene *scene, int deltaT)
{
    if (position.updatePosition(scene, hitbox, speed, deltaT))
    {
        onGround = true;
        setSpeedY(0); //HOTFIX don't know if work
    }
    else
        onGround = false;
}

void    CS_PersonalPhysic::updateImmunity(int deltaT)
{
//    std::cout << "imune = " << immunity << std::endl;
    immunity -= deltaT;
}
