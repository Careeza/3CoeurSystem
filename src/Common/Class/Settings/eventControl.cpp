#include "game.h"

int     bouttonManagement(CS_KeyControl& control, CS_Settings& settings, SDL_Renderer *render)
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
        return (0);
    }
    else if (buttonInfo == MOUSE_MOTION)
    {
        if (button->containsText())
            button->setZoom(ZOOMIN);
        button->setBrightness(true);
        // set zoomIn on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTTON_PRESS)
    {
        if (button->containsText())
            button->setZoom(ZOOMOUT);
        button->setBrightness(true);
        // set zoomOut on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTON_RELEASE)
    {
        if (button->containsText())
            button->setZoom(NOZOOM);
        button->setBrightness(false);
        button->useFonction(&settings, render);
        // use fonction
        return (0);
    }
    else
        return (0);
}