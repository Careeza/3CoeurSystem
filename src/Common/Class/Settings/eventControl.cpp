#include "game.h"

/*t_buttonValue     bouttonManagement(CS_KeyControl& control)
{
    static std::shared_ptr<CS_Element>      saveButton = NULL;
    std::shared_ptr<CS_Element>             button;
    int                                     buttonInfo;

    button = control.getBoutton(buttonInfo);
    if (button != saveButton && buttonInfo != NO_ACTION)
    {
        if (saveButton != NULL)
        {
            if (saveButton->containsText())
                saveButton->setZoom(NOZOOM);
            saveButton->setBrightness(false);
        }
        saveButton = button;
    }
    if (buttonInfo == NO_BOUTON)
    {
        // do nothing for the moment
        return (noButton);
    }
    else if (buttonInfo == MOUSE_MOTION)
    {
        if (button->containsText())
            button->setZoom(ZOOMIN);
        button->setBrightness(true);
        return (noButton);
    }
    else if (buttonInfo == BOUTTON_PRESS)
    {
        if (button->containsText())
            button->setZoom(ZOOMOUT);
        button->setBrightness(true);
        return (noButton);
    }
    else if (buttonInfo == BOUTON_RELEASE)
    {
        if (button->containsText())
            button->setZoom(NOZOOM);
        button->setBrightness(false);
        return (button->useFonction());
    }
    else
        return (noButton);
}*/
