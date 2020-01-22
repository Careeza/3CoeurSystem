#include "game.h"

#define BORDERMINX 0
#define BORDERMAXX 1100


void    checkBorder(CS_PersonalPhysic *physic)
{
    int wHitbox;
    int hHitbox;
    int xHitbox;
    int yHitbox;

    physic->QueryHitBox(wHitbox, hHitbox, xHitbox, yHitbox);

    int y;
    int x;

    physic->QueryPostion(x, y);

    int decalX;

    decalX = xHitbox - x;
    if (xHitbox + wHitbox >= 100000)
        physic->setPosXPixel(100000 - wHitbox - decalX);
    else if (xHitbox < 0)
        physic->setPosXPixel(-decalX);
}


void    checkBorderCamera(CS_Camera *camera)
{
    int xCamera;
    int yCamera;

    camera->QueryCameraPosition(xCamera, yCamera);
    if (xCamera + Tools->QueryWindowWidth() >= 100000)
        camera->moveCamera(100000, 0);
    else if (xCamera < 0)
        camera->moveCamera(0, 0);
}

#define UC 2
#define DC 3
#define LC 1
#define RC 0

int     checkColision(int R1W, int R1H, int R1X, int R1Y, int R2W, int R2H, int R2X, int R2Y)
{
    int uDiff;
    int dDiff;
    int lDiff;
    int rDiff;

    uDiff = R2Y - R1Y;
    dDiff = (R1H + R1Y) - (R2H + R2Y);
    lDiff = R2X - R1X;
    rDiff = (R1W + R1X) - (R2W + R2X);

    lDiff *= 4;
    rDiff *= 4;

/*
    if (rDiff < 0)
        return (RC);
    if (lDiff < 0)
        return (LC);
    if (uDiff < 0)
        return (UC);
    if (dDiff < 0)
        return (DC); */

    int min = 0;
    if (uDiff < min)
        min = uDiff;
    if (dDiff < min)
        min = dDiff;
    if (lDiff < min)
        min = lDiff;
    if (rDiff < min)
        min = rDiff;
    
    if (min == uDiff)
        return (UC);
    else if (min == dDiff)
        return (DC);
    else if (min == lDiff)
        return (LC);
    else if (min == rDiff)
        return (RC);
    else
        return (UC);
}

void    checkPlateforme(CS_PersonalPhysic *physic, CS_OnScreen *onScreen)
{
    int wHitbox;
    int hHitbox;
    int xHitbox;
    int yHitbox;

    physic->QueryHitBox(wHitbox, hHitbox, xHitbox, yHitbox);

    int     y;
    int     x;

    physic->QueryPostion(x, y);

    int decalY;
    int decalX;

    decalY = yHitbox - y;
    decalX = xHitbox - x;

    CS_Asset    *asset;
    int         wAsset;
    int         hAsset;
    int         xAsset;
    int         yAsset;
    int         i;
    int         type;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);
        if (asset->QueryName() == Plateforme)
        {
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if ((xAsset <= xHitbox + wHitbox && xAsset + wAsset >= xHitbox && yAsset <= yHitbox + hHitbox && hAsset + yAsset >= yHitbox))
            {
                type = checkColision(wAsset, hAsset, xAsset, yAsset, wHitbox, hHitbox, xHitbox, yHitbox);
                if (type == UC)
                {
                    physic->setPosYPixel(yAsset - hHitbox - decalY);
                    physic->setOnGround(true);
                    physic->setSpeedY(0);
                }
                else if (type == DC)
                    physic->setPosYPixel(yAsset + hAsset - decalY);
                else if (type == LC)
                {
                    physic->setPosXPixel(xAsset - wHitbox - decalX);
                    std::cout << "CL" << std::endl;
                }
                else
                {
                    physic->setPosXPixel(xAsset + wAsset - decalX);
                    std::cout << "CR" << std::endl;
                }
            }

        }
        i++;
    }
}


void    checkGround(CS_PersonalPhysic *physic, CS_OnScreen *onScreen)
{
    int wHitbox;
    int hHitbox;
    int xHitbox;
    int yHitbox;

    physic->QueryHitBox(wHitbox, hHitbox, xHitbox, yHitbox);

    int     y;
    int     x;

    physic->QueryPostion(x, y);

    int decalY;

    decalY = yHitbox - y;

    CS_Asset    *asset;
    int         wAsset;
    int         hAsset;
    int         xAsset;
    int         yAsset;
    int         i;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);
        if (asset->QueryName() == Ground01)
        {
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if ((xAsset <= xHitbox + wHitbox && xAsset + wAsset >= xHitbox && yAsset <= yHitbox + hHitbox && hAsset + yAsset >= yHitbox))
            {
                physic->setPosYPixel(yAsset - hHitbox - decalY);
                physic->setOnGround(true);
                physic->setSpeedY(0);
                break ;
            }
            else
                physic->setOnGround(false);
        }
        else
            physic->setOnGround(false);
        i++;
    }
}

void    checkEnemies(CS_Enemies *enemies, CS_OnScreen *onScreen)
{
    int         i;
    CS_Enemy    *enemy;

    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        checkGround(enemy->QueryPhysic(), onScreen);
        if (enemy->QueryPhysic()->QueryPostionY() > Tools->QueryWindowHeight())
        {
        }
        i++;
    }
}

void    resolveAllAction(CS_GameScene *scene)
{
    CS_Character *MC;

    MC = scene->QueryMC();
    checkGround(MC->QueryPhysic(), scene->QueryOnScreen());
    checkPlateforme(MC->QueryPhysic(), scene->QueryOnScreen());
    checkBorder(MC->QueryPhysic());
    checkEnemies(scene->QueryEnemies(), scene->QueryOnScreen());
    MC->setOnGround(MC->QueryPhysic()->verifyOnGround());
    MC->updateJump();
    checkBorderCamera(scene->QueryCamera());
    scene->QueryOnScreen()->updateOnScreen(MC, scene->QueryAssets());

}