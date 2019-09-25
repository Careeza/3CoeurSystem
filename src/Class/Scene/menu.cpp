#include "scene.h"

void    CS_Menu::CS_loadKeyControl(CS_KeyControl *control)
{
    event = control;
}

void    CS_Menu::CS_loadScene(CS_Scene *sceneSrc)
{
    scene = sceneSrc;
    sceneLen = sceneSrc->CS_querySceneLen();
}

void    CS_Menu::CS_getMouseInfo()
{
    buttons = event->getMouseActions(x_mouse, y_mouse);
}

bool    CS_Menu::CS_buttonClicked()
{
    if (buttons == CS_MOUSE_DOWN)
        return (false);
    return (false);
}

void    CS_Menu::getButton()
{
    int         i;

    i = sceneLen - 1;
    while (i >= 0)
    {
        button = scene->CS_querySingleElement(i);
        if (button->CS_isElementButton())
        {
            size = button->CS_queryElementSize();
            if (x_mouse >= size->x && x_mouse <= (size->x + size->w) && y_mouse >= size->y && y_mouse <= (size->y + size->h))
                break ;
        }
        i--;
    }
    if (i == -1)
        button = NULL;
}

void            CS_Menu::CS_addBrillance()
{
    static SDL_Rect *save = NULL;

    if (button == NULL)
    {
        scene->CS_setDispBrillance(false);
        save = NULL;
    }
    else if (save != size)
    {
        scene->resizeBrillance(size->w, size->h, size->x, size->y);
        scene->CS_setDispBrillance(true);
        save = size;
    }
}


void    CS_Menu::CS_useButton()
{
    if (buttons == CS_MOUSE_DOWN)
        if (button != NULL)
            button->CS_useFonction();
}