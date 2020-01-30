#include "game.h"

static void    moveCamera(CS_Camera *camera, CS_Character *MC, int deltaTMS, int& borderMin)
{
    int x;
    int y;

    camera->QueryCameraPosition(x, y);

    if (x >= Tools->transformWidth(278.0))
    {
        borderMin = Tools->transformWidth(278.2);
        camera->moveCamera3(MC);
    }
    else
        camera->moveCamera4(deltaTMS, true);
}

int     startLevel02(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_GameScene *scene, bool restart)
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
        MC->QueryPhysic()->setPosX(328);
        MC->QueryPhysic()->setPosY(74);
        MC->QueryPhysic()->setHP(5);

        enemies->deleteAllEnemy();

    }

    CS_Timer                    time;
    int                         ticks = 0;
    int                         wait;
    
    time.start();

    int     borderMin;
    int     borderMax;

    borderMin = Tools->transformWidth(0);
    borderMax = Tools->transformWidth(828.0);

    int monsterKill = 0;

    std::cout << "here = " << MC->QueryPhysic()->QueryHP() << std::endl;

    while (victory == 0 && MC->QueryPhysic()->QueryHP() > 0)
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

        moveCamera(scene->QueryCamera(), MC, deltaTMS, borderMin);

        resolveAllAction(scene, borderMin, borderMax);

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
