#include "scene.h"

void    CS_Menu::CS_loadKeyControl(CS_KeyControl *control)
{
    event = control;
}

void    CS_Menu::CS_getMouseInfo()
{
    buttons = event->getMouseActions(x_mouse, y_mouse);
}

void    CS_Menu::getButton()
{
    int         i;

    i = gameSettings.current->CS_querySceneLen() - 1;
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
            {
                if (Lockbutton == NULL)
                    if (save->CS_haveText())
                        save->CS_setZoom(-ZOOM);
                save->CS_setBrightness(false);
            }
            if (button->CS_haveText())
                button->CS_setZoom(ZOOM);
            button->CS_setBrightness(true);
            save = button;
        }
        else
        {
            if (Lockbutton == NULL)
                if (save->CS_haveText())
                    save->CS_setZoom(-ZOOM);
            save->CS_setBrightness(false);
            save = NULL;
        }
    }
}


void    CS_Menu::CS_useButton()
{
    if (buttons == CS_MOUSE_DOWN)
        if (button != NULL)
        {
            Lockbutton = button;
            if (button->CS_haveText())
                button->CS_setZoom(-ZOOM * 2);
        }
    if (buttons == CS_MOUSE_UP)
        if (Lockbutton != NULL)
        {
            if (Lockbutton == button)
            {
                if (Lockbutton->CS_haveText())
                    Lockbutton->CS_setZoom(2 * ZOOM);
                Lockbutton->CS_useFonction();
                Lockbutton = NULL;
            }
            else
            {
                if (Lockbutton->CS_haveText())
                    Lockbutton->CS_setZoom(ZOOM);
                Lockbutton = NULL;
            }
        }
}