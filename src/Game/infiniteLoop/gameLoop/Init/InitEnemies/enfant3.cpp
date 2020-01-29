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

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

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