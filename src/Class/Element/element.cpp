#include "scene.h"

CS_Element::CS_Element()
{
    elementIsButton = false;
    elementIsDisp = true;
    haveText = false;
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
}

bool            CS_Element::CS_isElementButton()
{
    return (elementIsButton);
}

bool            CS_Element::CS_isElementDisp()
{
    return(elementIsDisp);
}

int             CS_Element::CS_queryElementZIndex()
{
    return(elementZIndex);
}

SDL_Texture     *CS_Element::CS_queryElementTexture()
{
    if (CS_isElementButton())
    {
        return (elementButton->CS_queryNoButtonTexture());
    }
    else
    {
        return (elementNoButton->CS_queryNoButtonTexture());
    }
}

SDL_Rect         *CS_Element::CS_queryElementSize()
{
    if (CS_isElementButton())
    {
        return (elementButton->CS_QuerySize());
    }
    else
    {
        return (elementNoButton->CS_QuerySize());
    }
}

void            CS_Element::CS_setDisp(bool disp)
{
    elementIsDisp = disp;
}

void            CS_Element::CS_setZIndex(int z)
{
    elementZIndex = z;
}
        
void            CS_Element::CS_CreateNoButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->CS_addNoButtonFromHand(color, render, w, h, x, y);
}

void            CS_Element::CS_CreateButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->CS_addButtonFromHand(color, render, w, h, x, y, f);
}

void            CS_Element::CS_useFonction()
{
    if (elementIsButton)
        elementButton->CS_useFonction();
}

void            CS_Element::CS_resizeElement(float w, float h, float x, float y)
{
    if (elementIsButton)
        elementButton->CS_resize(w, h, x, y);
    else
        elementNoButton->CS_resize(w, h, x, y);

}

void            CS_Element::CS_resizeElementPixel(int w, int h, int x, int y)
{
    if (elementIsButton)
        elementButton->CS_resizePixel(w, h, x, y);
    else
        elementNoButton->CS_resizePixel(w, h, x, y);
}

