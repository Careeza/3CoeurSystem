#include "common.h"
#include "editMap.h"

TTF_Font    *CS_Police::CS_font = NULL;

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, CS_Settings& settings)
{
    CS_Timer        timer;
    CS_KeyControl   event;

    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryScene()))
        {
            if (settings.QueryPosition() & (homeHome | menuMenu))
                bouttonManagement(event, settings, rend);
        }
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
}

CS_Scene    *init_home(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->CS_createElementToScene("filtre", 80, 100, 0, 0, 40);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->CS_createButtonToScene("Exit game", 12, 6, 85, 84, 5, &closeGame);
    scene->CS_writeTexte(-1, "Exit game");

    return (scene);
}

void        initSettings(CS_Settings &settings, SDL_Window *window, SDL_Renderer *render)
{
    int w;
    int h;

    SDL_GetWindowSize(window, &w, &h);
    settings.getWindowSize(w, h);
    settings.getCloseRequest(false);
    settings.getPauseRequest(false);
    settings.getFps(30);
    settings.getPosition(homeHome);
    Tools->getWindowSize(settings.QueryWindowsWidth(), settings.QueryWindowsHeight());
    settings.initScene(init_home(render));
//    settings.initGameScene(render);
}

int     main(int argc, char **argv)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Police       initFont;
    CS_Settings     settings;
    
    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");
    
    render = init_renderer(window);

    initSettings(settings, window, render);

    rend.CS_loadRenderer(render);
    
    event = new(CS_KeyControl);

    infiniteLoop(rend, render, settings);

    TTF_Quit();
    SDL_Quit();
    return (0);
}