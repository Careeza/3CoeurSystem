#include "game.h"

t_pos   loopGame(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_GameScene                *scene;
    t_action                    action;

    CS_KeyControl::resetAction(&action);
    scene = initGameScene(render->QueryRender());

    t_pos                       pos = game;
    int                         stage = 1;
    
    while (pos == game)
    {
        if (stage == 1)
            stage = startLevel01(render, value, actionTable, scene);
//        if (stage == 1)
//            stage = startLevel1(render, value, actionTable, scene);
        if (stage == -1)
            pos = home;
        if (stage < -1)
            stage = gameOver(render, value, actionTable, stage);
    }

    delete scene;

    return (pos);
}