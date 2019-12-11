# include "gameScene.h"

CS_PersonalPhysic::CS_PersonalPhysic()
{
    onGround = false;
    bounciness = false;
    gravity = true;
    setSpeedX(0);
    setSpeedY(0);
    setPosXPixel(0);
    setPosYPixel(0);
}

CS_PersonalPhysic::~CS_PersonalPhysic()
{

}
