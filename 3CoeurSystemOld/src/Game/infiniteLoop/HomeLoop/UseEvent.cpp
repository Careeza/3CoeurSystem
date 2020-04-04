#include "game.h"

t_pos   homeUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == exitButton)
        return (close);
    else if (buttonValue == levelSelectButton)
        return (levelSelect);
    else if (buttonValue == menuButton)
    {
        render->saveScreen();
        loopMenu(render, value, actionTable);
        return (home);
    }
    else
        return (home);
}

t_pos   homeUseEvent(t_action action, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    if (action.escape == KeyPress)
        return (close);
    return (homeUseButton(action.att, button, render, value, actionTable));
}
