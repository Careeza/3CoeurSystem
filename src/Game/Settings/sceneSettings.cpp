#include "game.h"

void            CS_Settings::getScene(SDL_Renderer *render)
{
    delete Scene;
    if (pos == homeHome)
        Scene = init_home(render);
    else if (pos == homeVideo)
        Scene = init_homeVideo(render);
    else if (pos == homeSound)
        Scene = init_homeSound(render);
    else if (pos == homeHotkeys)
        Scene = init_homeHotkeys(render);
    else if (pos == homeLevelSelect)
        Scene = init_play(render);
    else if (pos == menuMenu)
        Scene = init_menu(render);
    else if (pos == menuVideo)
        Scene = init_menuVideo(render);
    else if (pos == menuSound)
        Scene = init_menuSound(render);
    else
        std::cout << "something went wrong wtf boooom" << std::endl;
}

void            CS_Settings::getGameScene(SDL_Renderer *render)
{

}