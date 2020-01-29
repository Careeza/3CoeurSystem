#include "game.h"

t_pos   loopGame(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_GameScene                *scene;
    t_action                    action;
    CS_Timer                    timer;
    t_pos                       pos;

    CS_KeyControl::resetAction(&action);
    scene = initGameScene(render->QueryRender());
    pos = game;

    int             deltaTMS;
    CS_Character    *MC;

    MC = scene->QueryMC();

    CS_Timer                    time;
    int                         ticks = 0;
    int                         wait;

    int                         stage = 1;
    
    time.start();

    while (pos == game)
    {
        if (stage == 1)
            stage = startLevel01(render, value, actionTable, scene);
//        if (stage == 1)
//            stage = startLevel1(render, value, actionTable, scene);
       if (stage == -1)
            pos = home;
    }

/*    while (pos == game)
    {
        ticks++;
        deltaTMS = timer.get_ticks();
 
        timer.start();

        gameGetEvenement(scene, value, actionTable);
        gameEventProcessing(actionTable, &action);

        MC->updateFrame(deltaTMS);
        useAction(&action, scene);
        pos = gameUseEvent(action, render, value, actionTable, &timer);
        MC->moveCharacter(deltaTMS, scene);
        MC->getFrame();

        scene->QueryEnemies()->updateEnemies(MC, scene, deltaTMS);
        scene->QueryProjectile()->updateProjectiles(scene, deltaTMS);

        scene->QueryCamera()->moveCamera3(MC);

        resolveAllAction(scene);

        parallaxManagement(scene->QueryParallax(), scene->QueryCamera());

        render->renderGameScene(scene);
        render->dispScreen();

        wait = fmax(0, (1000 / (float)60 - timer.get_ticks()));
        std::cout << "wait = " << wait << std::endl;
        SDL_Delay(wait);
    }
//    std::cout << "fps = " << ticks / (time.get_ticks() / 1000.0) << std::endl; */

    delete scene;
    return (pos);
}