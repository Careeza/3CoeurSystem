#include "gameScene.h"

void    CS_Camera::moveCamera(int xSource, int ySource)
{
    x = (xSource + x) / 2;
    y = (ySource + y) / 2;
}

void    CS_Camera::moveCamera2(int xSource, int ySource, CS_GameScene *map)
{
    x += xSource;
    y += ySource;
//    verifyHitbox(Tools->QueryWindowWidth(), Tools->QueryWindowHeight(), x, y, map);
}

#define Decalage 300

/*void    CS_Camera::moveCamera3(CS_Character *MC, float deltaT)
{
    int xMC;
    int yMC;

    MC->QueryPos(xMC, yMC);

    int velocity;
    int distance;
    int WindowW;

    WindowW = Tools->QueryWindowWidth();
    if (MC->VerifyRight())
        distance = (x + WindowW / 2) - (xMC + Decalage);
    else
        distance = (x + WindowW / 2) - (xMC - Decalage);
    velocity = (distance / Decalage) * VELOCITY;
    x += velocity * deltaT;
}
*/


void    CS_Camera::moveCamera3(CS_Character *MC, float deltaT)
{
    int xMC;
    int yMC;

    MC->QueryPos(xMC, yMC);

    int vX;
    int vY;

    vY = 0;
    vX = MC->QueryMoveX();

    //std::cout << vX << " << VX" << std::endl;

    int velocity;
    int distance;
    int WindowW;

    WindowW = Tools->QueryWindowWidth();
    if (vY == 0)
        distance = (x + WindowW / 2) - (xMC + Decalage);
    else
        distance = (x + WindowW / 2) - (xMC - Decalage);
    velocity = (distance / Decalage) * vX;
    x += vX * deltaT;
}

/*void    CS_Camera::moveCamera3(int posX, int yPos, CS_GameScene *map)
{
    static int speedX;
    static int speedY;

    (void)y;
    if (x > )
    {
        x 
    }
    else if (x > )
    {

    }
    else if (x < )
    {

    }
    else if (x < )
    {

    }
    else
    {
        moveWithTest(xSource > 0, Tools->QueryWindowWidth(), Tools->QueryWindowHeight(), x, y, map);
    }
}*/