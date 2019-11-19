#include "game.h"

void    escapeAction(CS_Settings& settings)
{
    if (settings.QueryPosition() == homeHome)
        dispDialogueBox(&settings);
    else if (settings.QueryPosition() == homeHotkeys)
        goToHome(&settings);
    else if (settings.QueryPosition() == homeVideo)
        goToHome(&settings);
    else if (settings.QueryPosition() == homeSound)
        goToHome(&settings);
    else if (settings.QueryPosition() == homeLevelSelect)
        goToHome(&settings);
    else if (settings.QueryPosition() == homeBox)
        hideDialogueBox(&settings);
    else if (settings.QueryPosition() == menuMenu)
        levelSelectToGame(&settings);
    else if (settings.QueryPosition() == menuHotkeys)
        goToMenu(&settings);
    else if (settings.QueryPosition() == menuVideo)
        goToMenu(&settings);
    else if (settings.QueryPosition() == menuSound)
        goToMenu(&settings);
    else if (settings.QueryPosition() == game)
        goToMenu(&settings);
    else
        std::cout << "lol you are kaki, Fred 2020" << std::endl;

}

void    escapeKeyManagement(CS_KeyControl event, CS_Settings& settings)
{
    int         key;
    int         info;
    static bool keyPress;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDLK_ESCAPE)
    {
        if (keyPress == false)
            escapeAction(settings);
        if (info == CS_KEYDOWN)
            keyPress = true;
        else
            keyPress = false;
    }
}