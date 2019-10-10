#include "keyControl.h"

int     CS_KeyControl::CS_getKeyboardActions()
{
    if (type == SDL_KEYDOWN)
    {
        return (event.key.keysym.scancode);
        std::cout << "key DOWN !" << std::endl;
    }
    if (type == SDL_KEYUP)
    {
        return (event.key.keysym.scancode);
        std::cout << "key UP !" << std::endl;
    }
    return (0);
}
