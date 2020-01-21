# include "game.h"

CS_EnemyBank    *initBankEnemies(SDL_Renderer *render)
{
    CS_EnemyBank    *bank;

    bank = new (CS_EnemyBank);

    bank->addEnemy(initEnfant1(render));

    return (bank);
}