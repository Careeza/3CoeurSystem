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
        button = gameSettings.current->CS_querySingleElement(i);
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
    static std::shared_ptr<CS_Element> save = NULL;

    if (save != button)
    {
        if (button != NULL)
        {
            if (save != NULL)
                save->CS_setBrightness(false);
            button->CS_setBrightness(true);
            save = button;
        }
        else
        {
            save->CS_setBrightness(false);
            save = NULL;
        }
    }
}


void    CS_Menu::CS_useButton()
{
    if (buttons == CS_MOUSE_DOWN)
        if (button != NULL)
            button->CS_useFonction();
}