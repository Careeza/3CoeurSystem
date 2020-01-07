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

CS_HitBox   *CS_PersonalPhysic::QueryHitBox()
{
    return (hitbox);
}