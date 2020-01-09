#include "keyControl.h"

std::shared_ptr<CS_Element>    getButtonSplit(CS_Scene *scene, int len, int x_mouse, int y_mouse)
{
    std::shared_ptr<CS_Element> button;
    SDL_Rect                    *size;

    while (len >= 0)
    {
        button = scene->QuerySingleElement(len);
        if (button->isElementButton() && button->isElementDisp() && button->isButtonEnable())
        {
            size = button->QueryElementSize();
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

std::shared_ptr<CS_Element>     CS_KeyControl::getButtonScene()
{
    std::shared_ptr<CS_Element> button;
    int                         x;
    int                         y;

    SDL_GetMouseState(&x, &y);
    button = getButtonSplit(scene, len, x, y);
    return (button);
}

t_buttonValue                   CS_KeyControl::useButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button)
{
    static std::shared_ptr<CS_Element>      saveButton = NULL;

    if (button != saveButton)
    {
        if (saveButton != NULL)
        {
            if (saveButton->containsText())
                saveButton->setZoom(NOZOOM);
            saveButton->setBrightness(false);
        }
        saveButton = button;
    }
    if (button != NULL)
    {
        if (mouse & KeyNoPress)
        {
            if (button->containsText())
                button->setZoom(ZOOMIN); //set zoomIn on
            button->setBrightness(true); // set brillance on
            return (noButton);
        }
        else if (mouse & KeyHoldPress)
        {
            if (button->containsText())
                button->setZoom(ZOOMOUT);
            button->setBrightness(true);
            return (noButton);
        }
        else if (mouse & KeyRelease)
        {
            if (button->containsText())
                button->setZoom(NOZOOM);
            button->setBrightness(false);
            return (button->useFonction());
        }
        else
        {
            std::cout << "weird error here" << std::endl;
            exit (0);
            return (noButton);
        }
    }
    else
    {
        return (noButton);
    }
}