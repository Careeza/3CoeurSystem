#include "keyControl.h"

CS_KeyControl::CS_KeyControl()
{
}

int    CS_KeyControl::loadEvenement()
{
    int eventLoop;

    scene = gameSettings.current;
    len = scene->CS_querySceneLen() - 1;
    eventLoop = SDL_PollEvent(&event);
    type = event.type;
    return (eventLoop);
}

int     CS_KeyControl::CS_getKeyboardActions()
{
    if (type == SDL_KEYDOWN)
    {
        return (event.key.keysym.scancode);
        std::cout << "key DOWN !" << std::endl;
    }
    if (type == SDL_KEYUP)
    {
        return (event.key.keysym.scancode);
        std::cout << "key UP !" << std::endl;
    }
    return (0);
}

/* int     CS_KeyControl::getMouseActions(int& x, int& y)
{
    if (type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;
        x = mouse_x;
        y = mouse_y;
        // TODO
        return (CS_MOTION);
    }
    if (type == SDL_MOUSEBUTTONDOWN && keyPress == false)
    {
        keyPress = true;
        static_x = event.button.x;
        static_y = event.button.y;
        x = static_x;
        y = static_y;
        return (CS_MOUSE_DOWN);
    }
    else if (type == SDL_MOUSEBUTTONUP)
    {
        keyPress = false;
        return (CS_MOUSE_UP);
    }
    return (0);
}*/

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