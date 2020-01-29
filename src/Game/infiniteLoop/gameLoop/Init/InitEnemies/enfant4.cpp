# include "game.h"

CS_Animation        *walkEnfant4(SDL_Renderer *render)
{
    CS_Animation    *animation;

    animation = new (CS_Animation);

    animation->newAnimation(WALK, true);
    animation->loadTexture(render, "resources/source/Enemies/Enfants/Noire1runL.png", "resources/source/Enemies/Enfants/Noire1runR.png");
    animation->setSize(20, 20);
    animation->cutFrame(5, 5, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(500);

    animation->setHitBox(true, 0.106771, 0.5, 0.436632, 0.215278);
    animation->setHitBox(false, 0.105903, 0.5, 0.454861, 0.218056);

    return (animation);
}

static CS_BankAnimation    *initBankAnimation4(SDL_Renderer *render)
{
    CS_BankAnimation *bank;

    bank = new (CS_BankAnimation);

    bank->addAnimation(render, walkEnfant4);

    return (bank);
}

t_enemyAction   initAlgoEnfant4(CS_Character *MC, CS_PersonalPhysic *physic)
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

CS_Enemy    *initEnfant4(SDL_Renderer *render)
{
    CS_Enemy    *enemy;

    enemy = new (CS_Enemy);

    enemy->initEnemyAnimationBank(initBankAnimation4(render));
    enemy->initAlgo(initAlgoEnfant4);
    enemy->setName(Enfant4);

    return (enemy);
}