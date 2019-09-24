#include "game.h"

CS_KeyControl::CS_KeyControl()
{
    buttons = 0;
    mouse_x = 0;
    mouse_y = 0;
    static_x = -1;
    static_y = -1;
    keyPress = false;
}

int    CS_KeyControl::loadEvenement()
{
    return (SDL_PollEvent(&event));
}

int     CS_KeyControl::queryEventType()
{
    type = event.type;
    return (event.type);
}

int     CS_KeyControl::getMouseActions(int& x, int& y)
{
    if (type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;
        x = mouse_x;
        y = mouse_y;
        // TODO
        return (CS_MOTION);
    }
    if (type == SDL_MOUSEBUTTONDOWN && keyPress == false)
    {
        keyPress = true;
        static_x = event.button.x;
        static_y = event.button.y;
        x = static_x;
        y = static_y;
        return (CS_MOUSE_DOWN);
    }
    else if (type == SDL_MOUSEBUTTONUP)
    {
        keyPress = false;
        return (CS_MOUSE_UP);
    }
    return (0);
}