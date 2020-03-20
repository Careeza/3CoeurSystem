#include "common.h"

void    dialogueGetEvenement(CS_Scene *scene, std::shared_ptr<CS_Element>& button, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;


    while (event.loadEvenement(scene))
    {
        button = event.getButtonScene();
        event.fillActionTable(actionTable, value);
    }
}

void    dilaogueEventProcessing(t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl::transformActionTable(actionTable);
    CS_KeyControl::resetAction(action);
    action->escape = actionTable->escape;
    action->att = actionTable->att;
}

bool    loopDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
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

        dialogueGetEvenement(scene, button, value, actionTable);
        dilaogueEventProcessing(actionTable, &action);
        answer = dialogueUseEvent(action, button);

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
