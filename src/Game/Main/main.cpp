#include "common.h"
#include "game.h"

void    infiniteLoop(CS_Renderer render, t_actionValue *value)
{
    CS_KeyControl   event;
    CS_Timer        timer;
    int             i;

    while (!gameSettings.closeRequested)
    {
        timer.start();
        while (event.loadEvenement())
        {
            if (gameSettings.pos & (homeHome | menuMenu))
                bouttonManagement(event);
            if (gameSettings.pos == game)
                actionKeyManagement(event, value);
            escapeKeyManagement(event);
        }
        if (gameSettings.pos == game)
        {
            gameSettings.gameScene->CS_queryMC()->useAnimation();
                i = 0;
        }
        render.CS_dispScene();
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
}

void        initSettings(CS_Settings &settings, SDL_Window *window)
{
    int w;
    int h;

    SDL_GetWindowSize(window, &w, &h);
    settings.getWindowSize(w, h);
    settings.getCloseRequest(false);
    settings.getPauseRequest(false);
    settings.getFps(30);
    settings.getPosition(homeHome);

}

void        initTools()
{
    Tools->getWindowSize(w, h);
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
    //window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
    window = create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600);
    initSettings(settings, window);
    Tools->getWindowSize(settings.QueryWindowsWidth(), settings.QueryWindowsHeight());

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");
    
    render = init_renderer(window);

    /*
    gameSettings.gameScene = init_gameScene(render);
    gameSettings.home = init_home(render);
    gameSettings.menu = init_menu(render);
    gameSettings.controlGame = init_menuHotkeys(render);
    gameSettings.controlHome = init_homeHotkeys(render);
    gameSettings.saveMenu = init_play(render);
    gameSettings.homeVideo = init_homeVideo(render);
    gameSettings.menuVideo = init_menuVideo(render);
    gameSettings.homeSound = init_homeSound(render);
    gameSettings.menuSound = init_menuSound(render);
    gameSettings.current = gameSettings.home; */

    rend.CS_loadRenderer(render);
    event = new(CS_KeyControl);

    fillActionValue(&value);

    infiniteLoop(rend, &value);

    /*delete gameSettings.gameScene;
    delete gameSettings.home;
    delete gameSettings.menu;
    delete gameSettings.controlGame;
    delete gameSettings.controlHome;
    delete gameSettings.saveMenu;
    delete gameSettings.homeVideo;
    delete gameSettings.menuVideo;
    delete gameSettings.homeSound;
    delete gameSettings.menuSound;*/

    TTF_Quit();
    SDL_Quit();
    return(0);
}