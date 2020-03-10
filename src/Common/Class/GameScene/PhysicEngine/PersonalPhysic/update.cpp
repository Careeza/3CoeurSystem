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
    if (position.updateYAxis(scene, hitbox, speed.QuerySpeedY(), deltaT))
        setSpeedY(0);
    if (position.updateXAxis(scene, hitbox, speed.QuerySpeedX(), deltaT))
        setSpeedX(0);
}

void    CS_PersonalPhysic::updateImmunity(int deltaT)
{
//    std::cout << "imune = " << immunity << std::endl;
    immunity -= deltaT;
}
