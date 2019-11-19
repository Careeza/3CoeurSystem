#include "gameScene.h"

void            CS_Settings::getScene(SDL_Renderer *render)
{
    delete Scene;
    if (pos == homeHome)
        Scene = init_home(SDL_Renderer *render);
    else if (pos == homeVideo)
        Scene = init_homeVideo(SDL_Renderer *render);
    else if (pos == homeSound)
        Scene = init_homeSound(SDL_Renderer *render);
    else if (pos == homeHotkeys)
        Scene = init_homeHotkeys(SDL_Renderer *render);
    else if (pos == homeLevelSelect)
        Scene = init_play(SDL_Renderer *render);
    else if (pos == menuMenu)
        Scene = init_menu(SDL_Renderer *render);
    else if (pos == menuVideo)
        Scene = init_menuVideo(SDL_Renderer *render);
    else if (pos == menuSound)
        Scene = init_menuSound(SDL_Renderer *render);
    else
        std::cout << "something went wrong wtf boooom" << std::endl;
}

void            CS_Settings::getGameScene()
(

)