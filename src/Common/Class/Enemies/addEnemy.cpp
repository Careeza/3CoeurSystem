# include "gameScene.h"

void        CS_Enemies::addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algo)(CS_Character *enemy, CS_Character *MC), float w, float h)
{
    CS_Enemy *enemy;

    enemy = new (CS_Enemy);
    enemy->addEnemy(render, create, algo);
    enemy->spawnEnemy(w, h);
    enemies.push_back(enemy);
}