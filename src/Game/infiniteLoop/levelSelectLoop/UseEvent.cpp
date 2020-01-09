#include "game.h"

t_pos   levelSelectUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == gameButton)
        return (game);
    else if (buttonValue == homeButton)
        return (home);
    else
        return (levelSelect);
}

t_pos   levelSelectEvent(t_action action, std::shared_ptr<CS_Element> button)
{
    if (action.escape == KeyPress)
        return (home);
    return (levelSelectUseButton(action.att, button));
}