#include "common.h"
#include "game.h"

void    infiniteLoop(CS_Renderer render, t_actionValue *value, CS_Settings& settings)
{
    CS_KeyControl   event;
    CS_Timer        timer;

    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryScene()))
        {
            if (settings.QueryPosition() & (homeHome | menuMenu))
                bouttonManagement(event, settings);
            if (settings.QueryPosition() == game)
                actionKeyManagement(event, value, settings);
            escapeKeyManagement(event, settings);
        }
        if (settings.QueryPosition() == game)
            settings.QueryGameScene()->CS_queryMC()->useAnimation();
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
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
    settings.initScene(render);
}

TTF_Font    *CS_Police::CS_font = NULL;

int     main(void)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Police       initFont;
    CS_Settings     settings;
    t_actionValue   value;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
//    window = create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600);

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");
    
    render = init_renderer(window);

    initSettings(settings, window, render);

    rend.CS_loadRenderer(render);
    event = new(CS_KeyControl);

    fillActionValue(&value);

    infiniteLoop(rend, &value, settings);

    TTF_Quit();
    SDL_Quit();
    return(0);
}