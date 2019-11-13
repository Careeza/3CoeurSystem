# include "gameScene.h"

CS_Enemies::CS_Enemies()
{

}

CS_Enemies::~CS_Enemies()
{
    
}

void        CS_Enemies::addEnemy(t_enemy type, SDL_Renderer *render)
{
    CS_Enemy    *enemy;

    enemy = new(CS_Enemy);
    enemy->addEnemy(type, render);
    enemies.push_back(enemy);
}

int         CS_Enemies::QueryNbEnemies()
{
    return (enemies.size());
}

CS_Enemy    *CS_Enemies::QueryEnemy(int index)
{
    SDL_Rect *rect;
    std::cout << "index = " << index << std::endl;
    rect = enemies[index]->queryFrame();
    std::cout << rect->w << std::endl;
    return (enemies[index]);
}