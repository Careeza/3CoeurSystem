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

t_pos    loopGame(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_GameScene                *scene;
    t_action                    action;
    CS_Timer                    timer;
    t_pos                       pos;

    CS_KeyControl::resetAction(&action);
    scene = initGameScene(render->QueryRender());
    pos = game;

    int             deltaTMS;
    float           deltaTS;
    CS_Character    *MC;

    MC = scene->QueryMC();
    while (pos == game)
    {
        deltaTMS = timer.get_ticks();
        deltaTS = deltaTMS / (float)1000;
 
        timer.start();

        gameGetEvenement(scene, value, actionTable);
        gameEventProcessing(actionTable, &action);

        MC->updateFrame(deltaTMS);
        useAction(&action, MC, deltaTMS);
        pos = gameUseEvent(action, render, value, actionTable);
        MC->moveCharacter(deltaTS, -100000, 100000);
        MC->getFrame();

        parallaxManagement(scene->QueryParallax(), 0, 0);

//        MCManagement(settings, &action, xCamera, yCamera, deltaTS, deltaTMS);


        render->renderGameScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
    return (pos);
}