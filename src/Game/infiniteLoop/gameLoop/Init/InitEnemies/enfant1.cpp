# include "game.h"

CS_Animation        *walkEnfant1(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/Enemies/Enfants/Noir1runL.png", "resources/source/Enemies/Enfants/Noir1runR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0.015, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

CS_Animation        *deadEnfant(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(DEAD, false);
    animation->loadTexture(render, "resources/source/Enemies/Enfants/MobDeath.png", "resources/source/Enemies/Enfants/MobDeath.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(true, 0, 0, 0, 0);
    animation->setHitBox(false, 0, 0, 0, 0);

    return (animation);
}

static CS_BankAnimation    *initBankAnimation1(SDL_Renderer *render)
{
    CS_BankAnimation *bank;

    bank = new (CS_BankAnimation);

    bank->addAnimation(render, walkEnfant1);
    bank->addAnimation(render, deadEnfant);

    return (bank);
}

t_enemyAction   initAlgoEnfant1(CS_Character *MC, CS_PersonalPhysic *physic)
{
    if (physic->QueryHP() <= 0)
        return (Dead);

    int xMC;
    int yMC;
    int wMC;
    int hMC;

    MC->QuerySizePos(wMC, hMC, xMC, yMC);


    int xEnemy;
    int yEnemy;

    physic->QueryPostion(xEnemy, yEnemy);

    if (xMC > xEnemy)
        return (WalkR);
    else
        return (WalkL);
}

CS_Enemy    *initEnfant1(SDL_Renderer *render)
{
    CS_Enemy    *enemy;

    enemy = new (CS_Enemy);

    enemy->initEnemyAnimationBank(initBankAnimation1(render));
    enemy->initAlgo(initAlgoEnfant1);
    enemy->setName(Enfant1);

    return (enemy);
}
