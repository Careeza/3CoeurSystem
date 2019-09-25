#include "scene.h"

CS_Button::CS_Button()
{
    CS_buttonFunction = NULL;
}

CS_Button::~CS_Button()
{
//    std::cout << "destruction du Nobutton" << std::endl;
//    delete buttonSize;
}

void            CS_Button::CS_useFonction(void)
{
    (*CS_buttonFunction)();
}

void            CS_Button::CS_addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    CS_addNoButtonFromHand(color, render, w, h, x, y);
    CS_buttonFunction = f;
}

void            CS_Button::CS_addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void))
{
    CS_addNoButtonFromPng(route, render, w, h, x, y);
    CS_buttonFunction = f;
}

SDL_Texture     *CS_Button::CS_queryButtonTexture()
{
    return (noButtonTexture);
}