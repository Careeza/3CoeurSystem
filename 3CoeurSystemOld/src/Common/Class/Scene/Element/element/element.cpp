#include "scene.h"

CS_Element::CS_Element()
{
    enabaleButton = true;
    elementIsButton = false;
    elementIsDisp = true;
    haveText = false;
    dispBrightness = false;
    dispBorder = false;
    elementZIndex = 0;
}

CS_Element::~CS_Element()
{
    SDL_DestroyTexture(QueryElementTexture());
    if (elementIsButton)
        delete elementButton;
    else
        delete elementNoButton;
    if (haveText)
        delete text;
    if (dispBorder)
        delete border;
    delete brightness;
}

t_buttonValue   CS_Element::useFonction()
{
    if (elementIsButton)
        return (elementButton->useFonction());
    return (noButton);
}
