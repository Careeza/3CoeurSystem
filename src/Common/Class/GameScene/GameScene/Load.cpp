#include "gameScene.h"

void    CS_GameScene::loadEnemies()
{
/*    enemies->addEnemy(CubeRouge, render);
    enemies->addEnemy(CuveVert, render);
    enemies->addEnemy(CubeRouge, render);*/
}

void    CS_GameScene::loadMC(int nbAnimation, ...)
{
    va_list         op;
    int             i;
    CS_Animation    *(*funct)(SDL_Renderer *render);

    i = 0;
    va_start(op, nbAnimation);
    while (i < nbAnimation)
    {
        funct = va_arg(op, CS_Animation*(*)(SDL_Renderer *render));
        MC->addAnimation(render, funct);
        std::cout << "here !" << std::endl;
        i++;
    }
    va_end(op);
}