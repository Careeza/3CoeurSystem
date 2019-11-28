#include "gameScene.h"

void        CS_Enemy::addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algoSource)(CS_Character *enemy, CS_Character *MC))
{
    enemy = create(render);
    algo = algoSource;
}

void        CS_Enemy::spawnEnemy(float xSource, float ySource)
{
    enemy->setPos(xSource, ySource);
}