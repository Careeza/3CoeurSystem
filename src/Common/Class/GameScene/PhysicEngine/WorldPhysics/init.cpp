# include "gameScene.h"

CS_WorldPhysics::CS_WorldPhysics()
{
    gravity.setAccelerationXPixel(0);
    gravity.setAccelerationYPixel(0);
    wind.setAccelerationXPixel(0);
    wind.setAccelerationYPixel(0);    
}

CS_WorldPhysics::~CS_WorldPhysics()
{
    
}
