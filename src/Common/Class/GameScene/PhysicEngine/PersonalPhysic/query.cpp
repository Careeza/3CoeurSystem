# include "gameScene.h"

void    CS_PersonalPhysic::QueryPostion(int& xDest, int& yDest)
{
    position.QueryPostion(xDest, yDest);
}

int     CS_PersonalPhysic::QueryPostionX()
{
    return (position.QueryPostionX());
}

int     CS_PersonalPhysic::QueryPostionY()
{
    return (position.QueryPostionY());
}

float     CS_PersonalPhysic::QuerySpeedX()
{
    return (speed.QuerySpeedX());
}

float     CS_PersonalPhysic::QuerySpeedY()
{
    return (speed.QuerySpeedY());
}


void    CS_PersonalPhysic::QueryHitBox(int& wDest, int& hDest, int& xDest, int& yDest)
{
    int w;
    int h;
    int xDecale;
    int yDecale;

    hitbox->QuerySizePos(w, h, xDecale, yDecale);

    int x;
    int y;

    QueryPostion(x, y);

    wDest = w;
    hDest = h;
    xDest = x + xDecale;
    yDest = y + yDecale;
}

CS_HitBox   *CS_PersonalPhysic::QueryRawHitbox()
{
    return (hitbox);
}

void    CS_PersonalPhysic::QueryAttack(int& wDest, int& hDest, int& xDest, int& yDest)
{
    int w;
    int h;
    int xDecale;
    int yDecale;

    attack->QuerySizePos(w, h, xDecale, yDecale);

    int x;
    int y;

    QueryPostion(x, y);

    wDest = w;
    hDest = h;
    xDest = x + xDecale;
    yDest = y + yDecale;
}

CS_HitBox   *CS_PersonalPhysic::QueryRawAttack()
{
    return (attack);
}

int         CS_PersonalPhysic::QueryHP()
{
    return (hp);
}
