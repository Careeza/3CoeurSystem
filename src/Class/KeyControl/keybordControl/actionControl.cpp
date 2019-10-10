#include "keyControl.h"

void    action(int key)
{
    if (key == SDL_SCANCODE_Q)
    {
//        MC->right = false;
    }
    else if (key == SDL_SCANCODE_D)
    {
//        MC->right = true;
    }
}

void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info)
{
    if (info == CS_KEYDOWN)
    {
        if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
        else if (value-> == key)
            table-> = true;
    }
    else if (info == CS_KEYUP)
    {
        if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
        else if (value-> == key)
            table-> = false;
    }
    else
    {}
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