# include "enemy.h"

void                CS_Enemy::initEnemyAnimationBank(CS_BankAnimation *animationBankSource)
{
    animationBank = animationBankSource;
}

void                CS_Enemy::initEnemyPhysic(CS_PersonalPhysic *physicSource)
{
    physic = physicSource;
}

void                CS_Enemy::initAlgo(t_enemyAction (*algoSource)(CS_Character *MC, CS_PersonalPhysic *physic))
{
    algo = algoSource;
}
