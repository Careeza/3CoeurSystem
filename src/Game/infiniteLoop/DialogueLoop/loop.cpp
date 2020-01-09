#include "game.h"

bool    boucleDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    CS_Scene                    *scene;
    t_action                    action;
    std::shared_ptr<CS_Element> button;
    CS_Timer                    timer;

    int                         answer = -1;

    CS_KeyControl::resetAction(&action);
    scene = initDialogue(render->QueryRender()); //initHomeKey

    while (answer == -1)
    {
        timer.start();

        homeGetEvenement(scene, button, value, actionTable);
        homeEventProcessing(actionTable, &action);
        answer = boucleUseEvent(action, button);

        render->renderScreenSave();
        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
    std::cout << "here" << std::endl;
    if (answer == 0)
        return (true);
    else
        return (false);
}