#include "editAnimation.h"

void    mouseAction(CS_KeyControl event, CS_EditAnimationSetting &settings, int& xMouse, int &yMouse)
{
    int             buttonInfo;

    (void)settings;
    buttonInfo = event.getMouseActions(xMouse, yMouse);
    if (buttonInfo == BOUTON_RELEASE)
    {
    }
}