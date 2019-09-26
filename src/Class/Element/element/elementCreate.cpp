#include "scene.h"

void            CS_Element::CS_CreateNoButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->CS_addNoButtonFromHand(color, render, w, h, x, y);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CS_CreateButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->CS_addButtonFromHand(color, render, w, h, x, y, f);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CS_CreateNoButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->CS_addNoButtonFromPng(route, render, w, h, x, y);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CS_CreateButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->CS_addButtonFromPng(route, render, w, h, x, y, f);
    loadBrightness(render, colorBrightness);
}

void        CS_Element::loadBorder(CS_Color colorSource, SDL_Renderer *render)
{
    border = new (CS_Border);
    dispBorder = true;
    border->CS_createTexture(colorSource, render);
    border->CS_createBorder(CS_queryElementSize());
}

void        CS_Element::loadBrightness(SDL_Renderer *render, CS_Color color)
{
    brightness = new (CS_Brightness);
    brightness->CS_initBright(render, color);
    brightness->addBrillance(CS_queryElementSize());
}


void            CS_Element::CS_addTextToElement(std::string comment, SDL_Renderer *render)
{
    text->CS_writeTexte(comment, CS_queryElementSize(), render);
}

void            CS_Element::CS_addTextToElementScaleW(std::string comment, SDL_Renderer *render)
{
    text->CS_writeTexteScaleW(comment, CS_queryElementSize(), render);
}
