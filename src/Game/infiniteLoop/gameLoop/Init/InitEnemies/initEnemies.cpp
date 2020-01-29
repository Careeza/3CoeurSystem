# include "game.h"

CS_Enemies      *initEnemies(SDL_Renderer *render)
{
    CS_Enemies  *enemies;

    enemies = new (CS_Enemies);

    enemies->loadEnemyBank(initBankEnemies(render));
    
    enemies->addAnEnemy(10, 10, Enfant1);
    enemies->addAnEnemy(20, 10, Enfant1);
//    enemies->addAnEnemy(20, 10, Enfant2);
//    enemies->addAnEnemy(30, 10, Enfant3);
//    enemies->addAnEnemy(40, 10, Enfant4);
//    enemies->addAnEnemy(50, 10, Enfant5);
//    enemies->addAnEnemy(60, 10, Enfant6);
    std::cout << "here" << std::endl;

    return (enemies);
}