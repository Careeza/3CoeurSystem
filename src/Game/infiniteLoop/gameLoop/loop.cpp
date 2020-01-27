#include "game.h"

void    gameGetEvenement(CS_Scene *scene, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;


    while (event.loadEvenement(scene))
    {
        event.fillActionTable(actionTable, value);
    }
}

void    gameEventProcessing(t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl::transformActionTable(actionTable);
    CS_KeyControl::resetAction(action);
    action->escape = actionTable->escape;
    action->att = actionTable->att;
    if ((actionTable->right & KeyHoldPress) && (actionTable->left & KeyReleaseNoPress))
        action->right = actionTable->right;
    if ((actionTable->left & KeyHoldPress) && (actionTable->right & KeyReleaseNoPress))
        action->left = actionTable->left;
    action->dodge = actionTable->dodge;
    action->jump = actionTable->jump;
}

void    moveCamera(CS_Camera *camera)
{
    camera->moveCamera(Tools->QueryWindowWidth(), 0);
}

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
    
    time.start();
    while (pos == game)
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

        scene->QueryEnemies()->updateEnemies(MC, deltaTMS);
        scene->QueryProjectile()->updateProjectiles(deltaTMS);

        scene->QueryCamera()->moveCamera3(MC);

        resolveAllAction(scene);

        parallaxManagement(scene->QueryParallax(), scene->QueryCamera());

        render->renderGameScene(scene);
        render->dispScreen();

        wait = fmax(0, (1000 / (float)60 - timer.get_ticks()));
        SDL_Delay(wait);
    }
//    std::cout << "fps = " << ticks / (time.get_ticks() / 1000.0) << std::endl; 

    delete scene;
    return (pos);
}