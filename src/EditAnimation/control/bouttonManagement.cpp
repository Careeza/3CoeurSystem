#include "editAnimation.h"

int     bouttonManagement2(CS_KeyControl& control, CS_EditAnimationSetting& settings, SDL_Renderer *render)
{
    static std::shared_ptr<CS_Element>      saveButton = NULL;
    std::shared_ptr<CS_Element>             button;
    int                                     buttonInfo;

    button = control.CS_getBoutton(buttonInfo);
    if (button != saveButton && buttonInfo != NO_ACTION)
    {
        if (saveButton != NULL)
        {
            if (saveButton->CS_haveText())
                saveButton->CS_setZoom(NOZOOM);
            saveButton->CS_setBrightness(false);
        }
        saveButton = button;
    }
    if (buttonInfo == NO_BOUTON)
    {
        // do nothing for the moment
        return (0);
    }
    else if (buttonInfo == MOUSE_MOTION)
    {
        if (button->CS_haveText())
            button->CS_setZoom(ZOOMIN);
        button->CS_setBrightness(true);
        // set zoomIn on
        // set brillance on
        return (1);
    }
    else if (buttonInfo == BOUTTON_PRESS)
    {
        if (button->CS_haveText())
            button->CS_setZoom(ZOOMOUT);
        button->CS_setBrightness(true);
        // set zoomOut on
        // set brillance on
        return (1);
    }
    else if (buttonInfo == BOUTON_RELEASE)
    {
        if (button->CS_haveText())
            button->CS_setZoom(NOZOOM);
        button->CS_setBrightness(false);
        button->CS_useFonction(&settings, render);
        // use fonction
        return (1);
    }
    else
        return (0);
}