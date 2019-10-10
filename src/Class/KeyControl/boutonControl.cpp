#include "keyControl.h"

std::shared_ptr<CS_Element>    getButton(CS_Scene *scene, int len, int x_mouse, int y_mouse)
{
    std::shared_ptr<CS_Element> button;
    SDL_Rect                    *size;

    while (len >= 0)
    {
        button = scene->CS_querySingleElement(len);
        if (button->CS_isElementButton() && button->CS_isElementDisp())
        {
            size = button->CS_queryElementSize();
            if (x_mouse >= size->x && x_mouse <= (size->x + size->w) && y_mouse >= size->y && y_mouse <= (size->y + size->h))
                break ;
        }
        len--;
    }
    if (len == -1)
        return(NULL);
    else
        return(button);
}

std::shared_ptr<CS_Element>     CS_KeyControl::CS_getBoutton(int& boutonInfo)
{
    std::shared_ptr<CS_Element> button;

    if (type == SDL_MOUSEMOTION)
    {
        button = getButton(scene, len, event.motion.x, event.motion.y);
        if (button == NULL)
            boutonInfo = NO_BOUTON;
        else
            boutonInfo = MOUSE_MOTION;
        return (button);
    }
    else if (type == SDL_MOUSEBUTTONDOWN)
    {
        button = getButton(scene, len, event.motion.x, event.motion.y);
        if (button == NULL)
            boutonInfo = NO_BOUTON;
        else
            boutonInfo = BOUTTON_PRESS;
        return (button);
    }
    else if (type == SDL_MOUSEBUTTONUP)
    {
        button = getButton(scene, len, event.motion.x, event.motion.y);
        if (button == NULL)
            boutonInfo = NO_BOUTON;
        else
            boutonInfo = BOUTON_RELEASE;
        return (button);
    }
    else
    {
        boutonInfo = NO_ACTION;
        return (NULL);
    }
}