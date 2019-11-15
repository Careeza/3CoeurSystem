# include "gameScene.h"

CS_Enemy::CS_Enemy()
{

}

CS_Enemy::~CS_Enemy()
{
}

SDL_Texture     *CS_Enemy::queryTexture()
{
    return(enemy->queryTexture());
}

SDL_Rect        *CS_Enemy::querySize()
{
    return(enemy->querySize());
}

SDL_Rect        *CS_Enemy::queryFrame()
{
    return(enemy->queryFrame());
}

void            CS_Enemy::addEnemy(t_enemy type, SDL_Renderer *render)
{
    CS_Cube         *redCube;
    CS_CubeGreen    *greenCube;

    EnemyType = type;
    std::cout << "add enemy" << std::endl;
    if (type & CubeRouge)
    {
        redCube = new (CS_Cube);
        redCube->loadBank(render);
        redCube->loadAnimation("AllenWalker");
        redCube->useAnimation();
        enemy = redCube;
    }
    if (type & CuveVert)
    {
        greenCube = new (CS_CubeGreen);
        greenCube->loadBank(render);
        greenCube->loadAnimation("AllenWalker");
        greenCube->useAnimation();
        enemy = greenCube;
    }
}

void            IA(CS_CommonEnemy *enemy)
{
    SDL_Rect    *MC;
    SDL_Rect    *Cube;

    Cube = enemy->querySize();
    MC = gameSettings.gameScene->CS_queryMC()->querySize();
    if (Cube->x > MC->x)
    {
        enemy->setRight(false);
    }
    else
    {
        enemy->setRight(true);
    }
}

void            CS_Enemy::reloadParam()
{
    IA(enemy);
    enemy->useAnimation();
}

