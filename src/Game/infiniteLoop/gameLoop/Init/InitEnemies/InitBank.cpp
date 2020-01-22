# include "game.h"

CS_EnemyBank    *initBankEnemies(SDL_Renderer *render)
{
    CS_EnemyBank    *bank;

    bank = new (CS_EnemyBank);

    bank->addEnemy(initEnfant1(render));
    bank->addEnemy(initEnfant2(render));
    bank->addEnemy(initEnfant3(render));
    bank->addEnemy(initEnfant4(render));
    bank->addEnemy(initEnfant5(render));
    bank->addEnemy(initEnfant6(render));

    return (bank);
}