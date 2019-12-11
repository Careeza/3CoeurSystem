# include "gameScene.h"

void    CS_PersonalPhysic::setOnGround(bool onGroundSource)
{
    onGround = onGroundSource;
}

void    CS_PersonalPhysic::setBounciness(bool bouncinessSource)
{
    bounciness = bouncinessSource;
}

void    CS_PersonalPhysic::setGravity(bool gravitySource)
{
    gravity = gravitySource;
}

void    CS_PersonalPhysic::setSpeedX(int speedX)
{
    speed.setSpeedXPixel(speedX);
}

void    CS_PersonalPhysic::setSpeedY(int speedY)
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