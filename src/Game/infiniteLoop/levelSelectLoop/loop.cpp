#include "game.h"

t_pos    loopLevelSelect(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_Scene                    *scene;
    t_action                    action;
    std::shared_ptr<CS_Element> button;
    CS_Timer                    timer;
    t_pos                       pos;

    CS_KeyControl::resetAction(&action);
    scene = initLevelSelect(render->QueryRender()); //initHomeKey
    pos = levelSelect;

    while (pos == levelSelect)
    {
        timer.start();

        homeGetEvenement(scene, button, value, actionTable);
        homeEventProcessing(actionTable, &action);
        pos = levelSelectEvent(action, button);

        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
    return (pos);
}