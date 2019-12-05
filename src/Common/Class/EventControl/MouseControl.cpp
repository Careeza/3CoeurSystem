#include "keyControl.h"

int     CS_KeyControl::getMouseActions(int &x, int &y)
{
    if (type == SDL_MOUSEMOTION)
    {
        x = event.motion.x;
        y = event.motion.y;

        return (MOUSE_MOTION);
    }
    else if (type == SDL_MOUSEBUTTONDOWN)
    {
        x = event.motion.x;
        y = event.motion.y;
        
        return (BOUTTON_PRESS);
    }
    else if (type == SDL_MOUSEBUTTONUP)
    {
        x = event.motion.x;
        y = event.motion.y;

        return (BOUTON_RELEASE);
    }
    else
    {
        return (NO_ACTION);
    }
}