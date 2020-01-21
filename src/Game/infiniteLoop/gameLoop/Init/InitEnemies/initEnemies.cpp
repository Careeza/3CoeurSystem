# include "game.h"

CS_Enemies      *initEnemies(SDL_Renderer *render)
{
    CS_Enemies  *enemies;

    enemies = new (CS_Enemies);

    enemies->loadEnemyBank(initBankEnemies(render));
//    enemies->addAnEnemy(10, 10, Enfant1);
    std::cout << "here" << std::endl;

    return (enemies);
}