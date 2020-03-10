# include "gameScene.h"

CS_PersonalPhysic::CS_PersonalPhysic()
{
    immunity = 0;
    bounciness = false;
    gravity = 1;
    hp = 2;
    setSpeedX(0);
    setSpeedY(0);
    setPosXPixel(0);
    setPosYPixel(0);
}

CS_PersonalPhysic::~CS_PersonalPhysic()
{

}
