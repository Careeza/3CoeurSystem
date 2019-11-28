#include "game.h"

int     bouttonManagement(CS_KeyControl& control, CS_Settings& settings, SDL_Renderer *render)
{
    static std::shared_ptr<CS_Element>      saveButton = NULL;
    std::shared_ptr<CS_Element>             button;
    int                                     buttonInfo;

    button = control.CS_getBoutton(buttonInfo);
    if (button != saveButton && buttonInfo != NO_ACTION)
    {
        if (saveButton != NULL)
        {
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
        button->CS_setZoom(ZOOMIN);
        button->CS_setBrightness(true);
        // set zoomIn on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTTON_PRESS)
    {
        button->CS_setZoom(ZOOMOUT);
        button->CS_setBrightness(true);
        // set zoomOut on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTON_RELEASE)
    {
        button->CS_setZoom(NOZOOM);
        button->CS_setBrightness(false);
        button->CS_useFonction(&settings, render);
        // use fonction
        return (0);
    }
    else
        return (0);
}