#include "game.h"

void    escapeAction(CS_Settings& settings)
{
    if (settings.QueryPosition() == homeHome)
        dispDialogueBox();
    else if (settings.QueryPosition() == homeHotkeys)
        goToHome();
    else if (settings.QueryPosition() == homeVideo)
        goToHome();
    else if (settings.QueryPosition() == homeSound)
        goToHome();
    else if (settings.QueryPosition() == homeLevelSelect)
        goToHome();
    else if (settings.QueryPosition() == homeBox)
        hideDialogueBox();
    else if (settings.QueryPosition() == menuMenu)
        levelSelectToGame();
    else if (settings.QueryPosition() == menuHotkeys)
        goToMenu();
    else if (settings.QueryPosition() == menuVideo)
        goToMenu();
    else if (settings.QueryPosition() == menuSound)
        goToMenu();
    else if (settings.QueryPosition() == game)
        goToMenu();
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