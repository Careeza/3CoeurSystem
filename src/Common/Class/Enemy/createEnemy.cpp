#include "gameScene.h"

void        CS_Enemy::addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algoSource)(CS_Character *enemy, CS_Character *MC))
{
    enemy = create(render);
    algo = algoSource;
}

void        CS_Enemy::spawnEnemy(float w, float h)
{
    SDL_Rect    *rect;

    rect = enemy->querySize();
    std::cout << rect->x << " -- " << rect->y <<  "--" << h << std::endl;
    rect->x = Tools->transformWidth(w);
    rect->y = Tools->transformHeight(h);
    std::cout << rect->x << " -- " << rect->y << std::endl;
}