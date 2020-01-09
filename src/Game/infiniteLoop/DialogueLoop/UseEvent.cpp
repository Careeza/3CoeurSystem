#include "game.h"

int boucleUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == trueButton)
        return (0);
    else if (buttonValue == falseButton)
        return (1);
    else
        return (-1);

}

int boucleUseEvent(t_action action, std::shared_ptr<CS_Element> button)
{
    if (action.escape == KeyPress)
        return (1);
    return (boucleUseButton(action.att, button));
}