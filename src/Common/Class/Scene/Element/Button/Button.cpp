#include "scene.h"

CS_Button::CS_Button()
{
    buttonFunction = NULL;
}

CS_Button::~CS_Button()
{
//    std::cout << "destruction du Nobutton" << std::endl;
//    delete buttonSize;
}

t_buttonValue   CS_Button::useFonction()
{
    return ((*buttonFunction)());
}

void            CS_Button::addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, t_buttonValue (*f)())
{
    addNoButtonFromHand(color, render, w, h, x, y);
    buttonFunction = f;
}

void            CS_Button::addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, t_buttonValue (*f)())
{
    addNoButtonFromPng(route, render, w, h, x, y);
    buttonFunction = f;
}

SDL_Texture     *CS_Button::QueryButtonTexture()
{
    return (noButtonTexture);
}
