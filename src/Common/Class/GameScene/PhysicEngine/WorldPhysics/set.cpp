# include "gameScene.h"

void        CS_WorldPhysics::setGravityPixel(float aX, float aY)
{
    gravity.setAccelerationXPixel(aX);
    gravity.setAccelerationYPixel(aY);
}

void        CS_WorldPhysics::setWindPixel(float aX, float aY)
{
    wind.setAccelerationXPixel(aX);
    wind.setAccelerationYPixel(aY);
}

void        CS_WorldPhysics::setGravity(float aX, float aY)
{
    gravity.setAccelerationX(aX);
    gravity.setAccelerationY(aY);
}

void        CS_WorldPhysics::setWind(float aX, float aY)
{
    wind.setAccelerationX(aX);
    wind.setAccelerationY(aY);
}
