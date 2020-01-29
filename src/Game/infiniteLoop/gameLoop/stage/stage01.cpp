#include "game.h"

int     gameUseEventStage01(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer)
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

int     KillMonster(CS_Enemies *enemies)
{
    int         i;
    int         hp;
    int         monsterKill = 0;
    CS_Enemy    *enemy;

    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        hp = enemy->QueryHP();
        if (hp == -3)
        {
            enemies->deleteEnemy(i);
            monsterKill++;
        }
        i++;
    }
    return (monsterKill);
}

int     startLevel01(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_GameScene *scene)
{
    int                         victory = 0;
    t_action                    action;
    CS_Timer                    timer;

    CS_KeyControl::resetAction(&action);


    int             deltaTMS;
    CS_Character    *MC;

    MC = scene->QueryMC();

    MC->QueryPhysic()->setPosX(20);
    MC->QueryPhysic()->setPosY(10);

    CS_Timer                    time;
    int                         ticks = 0;
    int                         wait;
    
    time.start();

    int     borderMin;
    int     borderMax;

    borderMin = 0;
    borderMax = Tools->transformWidth(1278.0);

    int monsterKill = 0;

    while (victory == 0 && monsterKill < 2)
    {
        ticks++;
        deltaTMS = timer.get_ticks();
 
        timer.start();

        gameGetEvenement(scene, value, actionTable);
        gameEventProcessing(actionTable, &action);

        MC->updateFrame(deltaTMS);
        useAction(&action, scene);
        victory = gameUseEventStage01(action, render, value, actionTable, &timer);
        MC->moveCharacter(deltaTMS, scene);
        MC->getFrame();

        scene->QueryEnemies()->updateEnemies(MC, scene, deltaTMS);
        scene->QueryProjectile()->updateProjectiles(scene, deltaTMS);

        scene->QueryCamera()->moveCamera3(MC);

        resolveAllAction(scene, borderMin, borderMax);

        monsterKill += KillMonster(scene->QueryEnemies());

        parallaxManagement(scene->QueryParallax(), scene->QueryCamera());

        render->renderGameScene(scene);
        render->dispScreen();

        wait = fmax(0, (1000 / (float)60 - timer.get_ticks()));
//        std::cout << "wait = " << wait << std::endl;
        SDL_Delay(wait);
    }

    if (victory == -1)
        return (-1);
    if (monsterKill >= 2)
        return (-2);
}
