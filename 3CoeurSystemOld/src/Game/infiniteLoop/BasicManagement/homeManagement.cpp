#include "game.h"

void    basicGetEvenement(CS_Scene *scene, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;

    while (event.loadEvenement(scene))
    {
        event.fillActionTable(actionTable, value);
    }
}

void    homeGetEvenement(CS_Scene *scene, std::shared_ptr<CS_Element>& button, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;


    while (event.loadEvenement(scene))
    {
        button = event.getButtonScene();
        event.fillActionTable(actionTable, value);
    }
}
