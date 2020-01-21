# include "enemy.h"

void                CS_Enemy::QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest)
{
    animation->QuerySize(wDest, hDest);
    physic->QueryPostion(xDest, yDest);
}

void                CS_Enemy::QuerySize(int& wDest, int& hDest)
{
    animation->QuerySize(wDest, hDest);
}

void                CS_Enemy::QueryPos(int& xDest, int& yDest)
{
    physic->QueryPostion(xDest, yDest);
}

t_enemy             CS_Enemy::QueryName()
{
    return (name);
}

int                 CS_Enemy::QueryID()
{
    return (id);
}

CS_BankAnimation    *CS_Enemy::QueryAnimationBank()
{
    return (animationBank);
}


CS_Animation        *CS_Enemy::QueryAnimation()
{
    return (animation);
}

CS_PersonalPhysic   *CS_Enemy::QueryPhysic()
{
    return (physic);
}

SDL_Texture         *CS_Enemy::QueryTexture()
{
    return (texture);
}

SDL_Rect            *CS_Enemy::QueryFrame()
{
    return (frame);
}

t_enemyAction (*CS_Enemy::QueryAlgo())(CS_Character *MC, CS_PersonalPhysic *physic)
{
    return (algo);
}
