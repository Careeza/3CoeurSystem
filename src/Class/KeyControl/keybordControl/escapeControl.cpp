#include "keyControl.h"

void    escapeAction()
{
    if (gameSettings.pos == homeHome)
        dispDialogueBox();
    else if (gameSettings.pos == homeHotkeys)
        goToHome();
    else if (gameSettings.pos == homeVideo)
        goToHome();
    else if (gameSettings.pos == homeSound)
        goToHome();
    else if (gameSettings.pos == homeLevelSelect)
        goToHome();
    else if (gameSettings.pos == homeBox)
        hideDialogueBox();
    else if (gameSettings.pos == menuMenu)
        levelSelectToGame();
    else if (gameSettings.pos == menuHotkeys)
        goToMenu();
    else if (gameSettings.pos == menuVideo)
        goToMenu();
    else if (gameSettings.pos == menuSound)
        goToMenu();
    else if (gameSettings.pos == game)
        goToMenu();
    else
        std::cout << "lol you are kaki, Fred 2020" << std::endl;

}

void    escapeKeyManagement(CS_KeyControl event)
{
    int         key;
    int         info;
    static bool keyPress;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDLK_ESCAPE)
    {
        if (keyPress == false)
            escapeAction();
        if (info == CS_KEYDOWN)
            keyPress = true;
        else
            keyPress = false;
    }
}