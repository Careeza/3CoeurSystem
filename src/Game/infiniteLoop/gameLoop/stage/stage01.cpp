#include "game.h"

int     gameUseEventStage(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer)
{
    if (action.escape == KeyPress)
    {
        timer->pause();
        render->saveScreen();
        if (loopMenu(render, value, actionTable))
        {
            timer->unpause();
            return (-1);
        }
        else
        {
            timer->unpause();
            return (0);
        }
    }
    return (0);
}

int     KillMonster(CS_Enemies *enemies, CS_Camera *camera)
{
    int         i;
    int         hp;
    int         monsterKill = 0;
    CS_Enemy    *enemy;

    int         y;
    int         x;

    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        hp = enemy->QueryHP();
        if (hp == -1)
        {
            enemies->deleteEnemy(i);
            monsterKill++;
        }
        enemy->QueryPos(x, y);
        if (y > 1080)
        {
            enemies->deleteEnemy(i);
        }
        i++;
    }

    int     nb_alea;

    camera->QueryCameraPosition(x, y);
    y = Tools->transformHeight(74);
    x += 1920;
    nb_alea = rand() % 6;
    if (enemies->QueryNbEnemies() < 6)
    {
        if (nb_alea == 0)
            enemies->addAnEnemyPixel(x, y, Enfant2);
        if (nb_alea == 1)
            enemies->addAnEnemyPixel(x, y, Enfant3);
        if (nb_alea == 2)
            enemies->addAnEnemyPixel(x, y, Enfant4);
        if (nb_alea == 3)
            enemies->addAnEnemyPixel(x, y, Enfant5);
        if (nb_alea == 4)
            enemies->addAnEnemyPixel(x, y, Enfant6);
        if (nb_alea == 5)
            enemies->addAnEnemyPixel(x, y, Enfant1);
    }
    return (monsterKill);
}

int     startLevel01(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_GameScene *scene, bool restart)
{
    int                         victory = 0;
    t_action                    action;
    CS_Timer                    timer;

    CS_KeyControl::resetAction(&action);


    int             deltaTMS;
    CS_Character    *MC;
    CS_Enemies      *enemies;

    MC = scene->QueryMC();

    enemies = scene->QueryEnemies();

    if (restart)
    {
        MC->QueryPhysic()->setPosX(10);
        MC->QueryPhysic()->setPosY(20);
        MC->QueryPhysic()->setHP(5);

        enemies->deleteAllEnemy();

        enemies->addAnEnemy(100, 74, Enfant6);
        enemies->addAnEnemy(110, 74, Enfant5);
        enemies->addAnEnemy(120, 74, Enfant4);
        enemies->addAnEnemy(130, 74, Enfant3);
        enemies->addAnEnemy(140, 74, Enfant2);
        enemies->addAnEnemy(150, 74, Enfant1);
    }

    CS_Timer                    time;
    int                         ticks = 0;
    int                         wait;
    
    time.start();

    int     borderMin;
    int     borderMax;

    borderMin = 0;
    borderMax = Tools->transformWidth(278.0);

    int monsterKill = 0;

    while (victory == 0 && monsterKill < 10 && MC->QueryPhysic()->QueryHP() > 0)
    {
        ticks++;
        deltaTMS = timer.get_ticks();
 
        timer.start();

        gameGetEvenement(scene, value, actionTable);
        gameEventProcessing(actionTable, &action);

        MC->updateFrame(deltaTMS);
        useAction(&action, scene);
        victory = gameUseEventStage(action, render, value, actionTable, &timer);
        MC->moveCharacter(deltaTMS, scene);
        MC->getFrame();

        scene->QueryEnemies()->updateEnemies(MC, scene, deltaTMS);
        scene->QueryProjectile()->updateProjectiles(scene, deltaTMS);

        scene->QueryCamera()->moveCamera3(MC);

        resolveAllAction(scene, borderMin, borderMax);

        monsterKill += KillMonster(enemies, scene->QueryCamera());

        parallaxManagement(scene->QueryParallax(), scene->QueryCamera());

        render->renderGameScene(scene);
        render->dispScreen();

        std::cout << "here = " << MC->QueryPhysic()->QueryHP() << std::endl;

        wait = fmax(0, (1000 / (float)60 - timer.get_ticks()));
//        std::cout << "wait = " << wait << std::endl;
        SDL_Delay(wait);
    }

    if (victory == -1)
        return (-1);
    if (MC->QueryPhysic()->QueryHP() <= 0)
        return (-2);
    else
        return (2);
}
