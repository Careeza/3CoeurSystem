# include "gameScene.h"

void    CS_Speed::setSpeedX(float vXSource)
{
    vX = Tools->transformWidth(vXSource);
}

void    CS_Speed::setSpeedY(float vYSource)
{
    vY = Tools->transformHeight(vYSource);
}

void    CS_Speed::setSpeed(float vXSource, float vYSource)
{
    vX = Tools->transformWidth(vXSource);
    vY = Tools->transformHeight(vYSource);
    std::cout << "speed vX" << std::endl;
}


        
void    CS_Speed::setSpeedXPixel(float vXSource)
{
    vX = vXSource;
}

void    CS_Speed::setSpeedYPixel(float vYSource)
{
    vY = vYSource;
}

void    CS_Speed::setSpeedPixel(float vXSource, float vYSource)
{
    vX = vXSource;
    vY = vYSource;
}
