#include "scene.h"

CS_Element::CS_Element()
{
    elementIsButton = false;
    elementIsDisp = true;
    haveText = false;
    dispBrillance = false;
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
}

void            CS_Element::CS_useFonction()
{
    if (elementIsButton)
        elementButton->CS_useFonction();
}