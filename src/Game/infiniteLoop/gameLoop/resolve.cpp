#include "game.h"

void    checkBorder(CS_PersonalPhysic *physic, int bornMin, int bornMax)
{
    int wHitbox;
    int hHitbox;
    int xHitbox;
    int yHitbox;

    physic->QueryHitBox(wHitbox, hHitbox, xHitbox, yHitbox);

    int y;
    int x;

    physic->QueryPostion(x, y);

    int decalX;

    decalX = xHitbox - x;
    if (xHitbox + wHitbox >= bornMax)
        physic->setPosXPixel(bornMax - wHitbox - decalX);
    else if (xHitbox < bornMin)
        physic->setPosXPixel(bornMin - decalX);
}


void    checkBorderCamera(CS_Camera *camera, int bornMin, int bornMax)
{
    int xCamera;
    int yCamera;

    camera->QueryCameraPosition(xCamera, yCamera);
    if (xCamera + Tools->QueryWindowWidth() >= bornMax)
        camera->moveCamera(bornMax - Tools->QueryWindowWidth(), 0);
    else if (xCamera < bornMin)
        camera->moveCamera(bornMin, 0);
}

void    resolveEnemyAtt(CS_Character *MC, CS_Enemies *enemies)
{
    int         i;
    CS_Enemy    *enemy;

    int         wMC;
    int         hMC;
    int         xMC;
    int         yMC;

    i = 0;
    MC->QueryPhysic()->QueryHitBox(wMC, hMC, xMC, yMC);

    int         wEnemy;
    int         hEnemy;
    int         xEnemy;
    int         yEnemy;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        enemy->QueryPhysic()->QueryHitBox(wEnemy, hEnemy, xEnemy, yEnemy);
        if ((xMC <= xEnemy + wEnemy && xMC + wMC >= xEnemy && yMC <= yEnemy + hEnemy && hMC + yMC >= yEnemy))
        {
            MC->QueryPhysic()->hitHP(1);
        }
        i++;
    }    
}

void    resolveAttMC(CS_Character *MC, CS_Enemies *enemies)
{
    int         i;
    CS_Enemy    *enemy;

    int         wMC;
    int         hMC;
    int         xMC;
    int         yMC;

    i = 0;
    MC->QueryPhysic()->QueryAttack(wMC, hMC, xMC, yMC);

    int         wEnemy;
    int         hEnemy;
    int         xEnemy;
    int         yEnemy;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        enemy->QueryPhysic()->QueryHitBox(wEnemy, hEnemy, xEnemy, yEnemy);
        if ((xMC <= xEnemy + wEnemy && xMC + wMC >= xEnemy && yMC <= yEnemy + hEnemy && hMC + yMC >= yEnemy))
            enemy->QueryPhysic()->hitHP(2);
        i++;
    }
}

void    resolveAllyProjectile(CS_Projectiles *projectileSource, CS_Enemies *enemies)
{
    int             i;
    int             j;
    CS_Projectile   *projectile;
    
    int         wMC;
    int         hMC;
    int         xMC;
    int         yMC;

    CS_Enemy    *enemy;

    int         wEnemy;
    int         hEnemy;
    int         xEnemy;
    int         yEnemy;

    i = 0;
    while (i < projectileSource->QueryNbProjectile())
    {
        j = 0;
        projectile = projectileSource->QueryProjectile(i);
        if (projectile->QueryAlly())
        {
            projectile->QuerySizePos(wMC, hMC, xMC, yMC);
            while (j < enemies->QueryNbEnemies())
            {
                enemy = enemies->QueryEnemy(j);
                enemy->QueryPhysic()->QueryHitBox(wEnemy, hEnemy, xEnemy, yEnemy);
                if ((xMC <= xEnemy + wEnemy && xMC + wMC >= xEnemy && yMC <= yEnemy + hEnemy && hMC + yMC >= yEnemy))
                {
                    enemy->QueryPhysic()->hitHP(1);
                    projectileSource->deleteProjectile(i);
                    break;
                }
                j++;                
            }
        }
        i++;
    }
}

void    resolveAllAction(CS_GameScene *scene, int bornMin, int bornMax)
{
    CS_Character *MC;

    MC = scene->QueryMC();
    
    int x;
    int y;

    MC->setOnGround(MC->QueryPhysic()->verifyOnGround());
    MC->updateJump();

    checkBorderCamera(scene->QueryCamera(), bornMin, bornMax);

    scene->QueryCamera()->QueryCameraPosition(x, y);

    checkBorder(MC->QueryPhysic(), x, x + Tools->QueryWindowWidth());

    scene->QueryOnScreen()->updateOnScreen(MC, scene->QueryAssets());

    resolveAttMC(scene->QueryMC(), scene->QueryEnemies());
    resolveAllyProjectile(scene->QueryProjectile(), scene->QueryEnemies());

    resolveEnemyAtt(scene->QueryMC(), scene->QueryEnemies());
}