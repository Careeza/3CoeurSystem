#include "scene.h"

void            CS_Element::CreateNoButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->addNoButtonFromHand(color, render, w, h, x, y);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CreateButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->addButtonFromHand(color, render, w, h, x, y, f);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CreateNoButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y)
{
    elementNoButton = new(CS_NoButton);
    elementIsButton = false;
    elementNoButton->addNoButtonFromPng(route, render, w, h, x, y);
    loadBrightness(render, colorBrightness);
}

void            CS_Element::CreateButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*))
{
    elementButton = new(CS_Button);
    elementIsButton = true;
    elementButton->addButtonFromPng(route, render, w, h, x, y, f);
    loadBrightness(render, colorBrightness);
}

void        CS_Element::loadBorder(CS_Color colorSource, SDL_Renderer *render)
{
    border = new (CS_Border);
    dispBorder = true;
    border->createTexture(colorSource, render);
    border->createBorder(QueryElementSize());
}

void        CS_Element::loadBrightness(SDL_Renderer *render, CS_Color color)
{
    brightness = new (CS_Brightness);
    brightness->initBright(render, color);
    brightness->addBrillance(QueryElementSize());
}


void            CS_Element::addTextToElement(std::string comment, SDL_Renderer *render)
{
    text->writeTexte(comment, QueryElementSize(), render);
    text->initZoomIn();
    text->initZoomOut();
}

void            CS_Element::addTextToElementScaleW(std::string comment, SDL_Renderer *render)
{
    text->writeTexteScaleW(comment, QueryElementSize(), render);
    text->initZoomIn();
    text->initZoomOut();
}

