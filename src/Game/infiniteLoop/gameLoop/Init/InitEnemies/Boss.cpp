# include "game.h"

CS_Animation        *walkBoss(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/Enemies/Enfants/Noir1runL.png", "resources/source/Enemies/Enfants/Noir1runR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(500);

    return (animation);
}

static CS_BankAnimation    *initBankAnimationBoss(SDL_Renderer *render)
{
    CS_BankAnimation *bank;

    bank = new (CS_BankAnimation);

    bank->addAnimation(render, walkBoss);

    return (bank);
}

t_enemyAction   initAlgoEnfantBoss(CS_Character *MC, CS_PersonalPhysic *physic)
{
    int xMC;
    int YMC;

    MC->QueryPos(xMC, YMC);

    int xEnemy;
    int yEnemy;

    physic->QueryPostion(xEnemy, yEnemy);

    if (xMC > xEnemy)
        return (WalkR);
    else
        return (WalkL);
}

CS_Enemy    *initEnfantBoss(SDL_Renderer *render)
{
    CS_Enemy    *enemy;

    enemy = new (CS_Enemy);

    enemy->initEnemyAnimationBank(initBankAnimationBoss(render));
    enemy->initAlgo(initAlgoEnfantBoss);
    enemy->setName(Boss);

    return (enemy);
}