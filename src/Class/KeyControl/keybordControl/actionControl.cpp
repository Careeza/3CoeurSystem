#include "keyControl.h"

void    action(int key, CS_Character *MC)
{
    if (key == SDL_SCANCODE_Q)
    {
        MC->right = false;
    }
    else if (key == SDL_SCANCODE_D)
    {
        MC->right = true;
    }
}

void    actionKeyManagement(CS_KeyControl event)
{
    int         key;
    int         info;
    static bool keyPress;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDL_SCANCODE_ESCAPE)
    {
        if (keyPress == false)
            action(key);
        if (info == CS_KEYDOWN)
            keyPress = true;
        else
            keyPress = false;
    }
}