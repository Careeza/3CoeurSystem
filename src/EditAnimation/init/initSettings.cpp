#include "editAnimation.h"


void        initSettings(CS_EditAnimationSetting &settings, SDL_Window *window, SDL_Renderer *render)
{
    int w;
    int h;

    SDL_GetWindowSize(window, &w, &h);
    std::cout << "w = " << w << " h = " << h << std::endl;
    settings.getWindowSize(w, h);
    settings.getCloseRequest(false);
    settings.getPauseRequest(false);
    settings.getFps(60);
    settings.setFpsAnimation(1000);
    settings.getPosition(game);
    Tools->getWindowSize(settings.QueryWindowsWidth(), settings.QueryWindowsHeight());
    settings.initGameScene(init_home(render));
//    settings.initGameScene(render);
}