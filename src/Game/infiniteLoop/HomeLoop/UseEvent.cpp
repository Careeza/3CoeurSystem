#include "game.h"

t_pos   homeUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == exitButton)
        return (close);
    else
        return (home);
}

t_pos   homeUseEvent(t_action action, std::shared_ptr<CS_Element> button)
{
    if (action.escape == KeyPress)
        return (close);
    return (homeUseButton(action.att, button));
}