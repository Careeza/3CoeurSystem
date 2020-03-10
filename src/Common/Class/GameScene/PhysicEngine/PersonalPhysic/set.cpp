# include "gameScene.h"

void    CS_PersonalPhysic::setBounciness(bool bouncinessSource)
{
    bounciness = bouncinessSource;
}

void    CS_PersonalPhysic::setGravity(float gravitySource)
{
    gravity = gravitySource;
}

void    CS_PersonalPhysic::setSpeedX(float speedX)
{
    speed.setSpeedXPixel(speedX);
}

void    CS_PersonalPhysic::setSpeedY(float speedY)
{
    speed.setSpeedYPixel(speedY);
}

void    CS_PersonalPhysic::setPosX(float posX)
{
    position.setPositionX(posX);
}

void    CS_PersonalPhysic::setPosY(float posY)
{
    position.setPositionY(posY);
}
void    CS_PersonalPhysic::setPosXPixel(int posX)
{
    position.setPositionXPixel(posX);
}

void    CS_PersonalPhysic::setPosYPixel(int posY)
{
    position.setPositionYPixel(posY);
}

void        CS_PersonalPhysic::setHitBox(CS_HitBox *hitboxSource)
{
    hitbox = hitboxSource;
}

void        CS_PersonalPhysic::setAttack(CS_HitBox *attackSource)
{
    attack = attackSource;
}

void        CS_PersonalPhysic::setHP(int hpSource)
{
    hp = hpSource;
}

void        CS_PersonalPhysic::increaseHP(int hpSource)
{
    hp += hpSource;
}

void        CS_PersonalPhysic::hitHP(int hpSource)
{
    if (immunity <= 0)
    {
        increaseHP(-hpSource);
        immunity = 150;
    }
}

void        CS_PersonalPhysic::healHP(int hpSource)
{
    increaseHP(hpSource);
}