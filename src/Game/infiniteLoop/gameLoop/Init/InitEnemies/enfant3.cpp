# include "game.h"

CS_Animation        *walkEnfant3(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/Enemies/Enfants/Noir3runL.png", "resources/source/Enemies/Enfants/Noir3runR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0.025, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(0, true, 0.104167, 0.469444, 0.473958, 0.280556);
    animation->setHitBox(1, true, 0.140625, 0.438889, 0.456597, 0.280556);
    animation->setHitBox(2, true, 0.104167, 0.469444, 0.456597, 0.311111);
    animation->setHitBox(3, true, 0.121528, 0.436111, 0.439236, 0.344444);
    animation->setHitBox(4, true, 0.121528, 0.469444, 0.439236, 0.311111);

    animation->setHitBox(0, false, 0.104167, 0.469444, 0.421875, 0.280556);
    animation->setHitBox(1, false, 0.140625, 0.438889, 0.402778, 0.280556);
    animation->setHitBox(2, false, 0.104167, 0.469444, 0.439236, 0.311111);
    animation->setHitBox(3, false, 0.121528, 0.436111, 0.439236, 0.344444);
    animation->setHitBox(4, false, 0.104167, 0.469444, 0.439236, 0.311111);

    return (animation);
}

static CS_BankAnimation    *initBankAnimation3(SDL_Renderer *render)
{
    CS_BankAnimation *bank;

    bank = new (CS_BankAnimation);

    bank->addAnimation(render, walkEnfant3);

    return (bank);
}

t_enemyAction   initAlgoEnfant3(CS_Character *MC, CS_PersonalPhysic *physic)
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

CS_Enemy    *initEnfant3(SDL_Renderer *render)
{
    CS_Enemy    *enemy;

    enemy = new (CS_Enemy);

    enemy->initEnemyAnimationBank(initBankAnimation3(render));
    enemy->initAlgo(initAlgoEnfant3);
    enemy->setName(Enfant3);

    return (enemy);
}