# include "enemy.h"

CS_PersonalPhysic   *initPhysicEnemy(float x, float y)
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosX(x);
    physic->setPosY(y);
    
    return (physic);
}

CS_PersonalPhysic   *initPhysicEnemyPixel(int x, int y)
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosXPixel(x);
    physic->setPosYPixel(y);
    
    return (physic);
}

CS_Enemy        *copyEnemy(CS_Enemy *enemySource)
{
    CS_Enemy *newEnemy;

    newEnemy = new (CS_Enemy);

    newEnemy->initEnemyAnimationBank(enemySource->QueryAnimationBank());
    newEnemy->initAlgo(enemySource->QueryAlgo());

    return (newEnemy);
}

void        CS_Enemies::addAnEnemy(float x, float y, t_enemy name)
{
    CS_Enemy *newEnemy;

    newEnemy = copyEnemy(enemyBank->QueryEnemy(name));
    newEnemy->initEnemyPhysic(initPhysicEnemy(x, y));
    newEnemy->loadAnimation(WALK);
    newEnemy->getFrame();

    enemies.push_back(newEnemy);
    updateID();
}

void        CS_Enemies::addAnEnemyPixel(int x, int y, t_enemy name)
{
    CS_Enemy *newEnemy;

    newEnemy = copyEnemy(enemyBank->QueryEnemy(name));
    newEnemy->initEnemyPhysic(initPhysicEnemyPixel(x, y));
    newEnemy->loadAnimation(WALK);
    newEnemy->getFrame();

    enemies.push_back(newEnemy);
    updateID();
}