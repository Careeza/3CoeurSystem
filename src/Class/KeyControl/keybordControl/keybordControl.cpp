#include "keyControl.h"

int     CS_KeyControl::CS_getKeyboardActions(int& key)
{
    if (type == SDL_KEYDOWN)
    {
        key = event.key.keysym.scancode;
        return (CS_KEYDOWN);
        std::cout << "key DOWN !" << std::endl;
    }
    else if (type == SDL_KEYUP)
    {
        key = event.key.keysym.scancode;
        return (CS_KEYUP);
        std::cout << "key UP !" << std::endl;
    }
    else
    {
        key = 0;
        return (CS_NOKEY);
    }
}
