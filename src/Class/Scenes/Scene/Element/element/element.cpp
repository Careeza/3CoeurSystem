#include "scene.h"

CS_Element::CS_Element()
{
    elementIsButton = false;
    elementIsDisp = true;
    haveText = false;
    dispBrightness = false;
    dispBorder = false;
    elementZIndex = 0;
}

CS_Element::~CS_Element()
{
    SDL_DestroyTexture(CS_queryElementTexture());
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

void            CS_Element::CS_useFonction()
{
    if (elementIsButton)
        elementButton->CS_useFonction();
}