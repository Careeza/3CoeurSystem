# include "enemy.h"

void                CS_Enemy::initEnemyAnimationBank(CS_BankAnimation *animationBankSource)
{
    animationBank = animationBankSource;
}

void                CS_Enemy::initEnemyPhysic(CS_PersonalPhysic *physicSource)
{
    physic = physicSource;
}
