#include "game.h"

void    escapeAction(CS_Settings& settings, SDL_Renderer *render)
{
    if (settings.QueryPosition() == homeHome)
        dispDialogueBox(&settings, render);
    else if (settings.QueryPosition() == homeHotkeys)
        goToHome(&settings, render);
    else if (settings.QueryPosition() == homeVideo)
        goToHome(&settings, render);
    else if (settings.QueryPosition() == homeSound)
        goToHome(&settings, render);
    else if (settings.QueryPosition() == homeLevelSelect)
        goToHome(&settings, render);
    else if (settings.QueryPosition() == homeBox)
        hideDialogueBox(&settings, render);
    else if (settings.QueryPosition() == menuMenu)
        levelSelectToGame(&settings, render);
    else if (settings.QueryPosition() == menuHotkeys)
        goToMenu(&settings, render);
    else if (settings.QueryPosition() == menuVideo)
        goToMenu(&settings, render);
    else if (settings.QueryPosition() == menuSound)
        goToMenu(&settings, render);
    else if (settings.QueryPosition() == game)
        goToMenu(&settings, render);
    else
        std::cout << "lol you are kaki, Fred 2020" << std::endl;

}

void    escapeKeyManagement(CS_KeyControl event, CS_Settings& settings, SDL_Renderer *render)
{
    int         key;
    int         info;
    static bool keyPress;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDLK_ESCAPE)
    {
        if (keyPress == false)
            escapeAction(settings, render);
        if (info == CS_KEYDOWN)
            keyPress = true;
        else
            keyPress = false;
    }
}