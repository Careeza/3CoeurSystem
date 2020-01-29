# include "gameScene.h"

bool    CS_Position::updatePosition(CS_GameScene *scene, CS_HitBox *hitbox, CS_Speed speed, int deltaT)
{
    float vx;
    float vy;

    vx = speed.QuerySpeedX();
    vy = speed.QuerySpeedY();
    return (updatePosition(scene, hitbox, vx, vy, deltaT));
}

bool        CheckCollision(int w, int h, int x, int y, CS_GameScene *scene)
{
    bool            colision;
    CS_OnScreen     *onScreen;
    CS_Asset        *asset;

    colision = false;
    onScreen = scene->QueryOnScreen();

    int             i;
    int             w2;
    int             h2;
    int             x2;
    int             y2;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);

        asset->QuerySize(w2, h2, x2, y2);
        if ((x2 < x + w && x2 + w2 > x && y2 < y + h && h2 + y2 > y))
        {
            colision = true;
        }
        i++;
    }
    return (colision); 
}

int     adjustmentY(int w, int h, int x, int y, bool up, CS_GameScene *scene)
{
    int             adjustment;
    CS_OnScreen     *onScreen;
    CS_Asset        *asset;

    adjustment = 0;
    onScreen = scene->QueryOnScreen();

    int             i;
    int             wAsset;
    int             hAsset;
    int             xAsset;
    int             yAsset;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);

        asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
        if ((xAsset < x + w && xAsset + wAsset > x && yAsset < y + h && hAsset + yAsset > y))
        {
            if (up)
            {
                adjustment = yAsset - h - y;
                return (adjustment);
            }
            else
            {
                adjustment = yAsset + hAsset - y;
                return (adjustment);
            }
        }
        i++;
    }
    return (adjustment); 
}

int     adjustmentX(int w, int h, int x, int y, bool right, CS_GameScene *scene)
{
    int             adjustment;
    CS_OnScreen     *onScreen;
    CS_Asset        *asset;

    adjustment = 0;
    onScreen = scene->QueryOnScreen();

    int             i;
    int             wAsset;
    int             hAsset;
    int             xAsset;
    int             yAsset;

    i = 0;
    while (i < onScreen->QueryNbOnScreen())
    {
        asset = onScreen->QueryOnScreen(i);

        asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
        if ((xAsset < x + w && xAsset + wAsset > x && yAsset < y + h && hAsset + yAsset > y))
        {
            if (right)
            {
                adjustment = xAsset - w - x;
                return (adjustment);
            }
            else
            {
                adjustment = xAsset + wAsset - x;
                return (adjustment);
            }
        }
        i++;
    }
    return (adjustment);
}

bool    CS_Position::updatePosition(CS_GameScene *scene, CS_HitBox *hitbox, float vXSource, float vYSource, int deltaT)
{
    int     newX;
    int     newY;

    int     w;
    int     h;
    int     xDecale;
    int     yDecale;

    int     adjustment;

    bool    onGround = false;

    hitbox->QuerySizePos(w, h, xDecale, yDecale);


    newY = y + vYSource * deltaT;
    adjustment = adjustmentY(w, h, x + xDecale, newY + yDecale, vYSource > 0, scene);
    if (adjustment < 0)
        onGround = true;
    newY += adjustment;

    newX = x + vXSource * deltaT;
    adjustment = adjustmentX(w, h, newX + xDecale, newY + yDecale, vXSource > 0, scene);
    newX += adjustment;

    x = newX;
    y = newY;
    return (onGround);
}