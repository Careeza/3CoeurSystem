#include "scene.h"

void            CS_Element::CS_CreateNoButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->CS_addNoButtonFromHand(color, render, w, h, x, y);
    loadBrightness();
}

void            CS_Element::CS_CreateButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->CS_addButtonFromHand(color, render, w, h, x, y, f);
    loadBrightness();
}

void        CS_Element::loadBorder(CS_Color colorSource, SDL_Renderer *render)
{
    border = new (CS_Border);
    dispBorder = true;
    border->CS_createTexture(colorSource, render);
    border->CS_createBorder(CS_queryElementSize());
}

void        CS_Element::loadBrightness()
{
    brightness = new (CS_Brightness);
    brightness->addBrillance(CS_queryElementSize());
}


void            CS_Element::CS_addTextToElement(std::string comment, SDL_Renderer *render)
{
    text->CS_writeTexte(comment, CS_queryElementSize(), render);
}