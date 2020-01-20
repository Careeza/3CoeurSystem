#include "keyControl.h"

int     CS_KeyControl::getButton()
{
    return (event.button.button);
}

void    CS_KeyControl::updateMousePos()
{
    SDL_GetMouseState(&xMouse, &yMouse);
}

void    CS_KeyControl::getMousePos(int& xDest, int& yDest)
{
    xDest = xMouse;
    yDest = yMouse;
}