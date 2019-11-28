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
    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset1", 12.5, 10, 75, 0, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit1");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset2", 12.5, 10, 87.5, 0, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit2");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset3", 12.5, 10, 75, 10, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit3");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset4", 12.5, 10, 87.5, 10, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit4");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset5", 12.5, 10, 75, 20, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit5");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset6", 12.5, 10, 87.5, 20, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit6");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset7", 12.5, 10, 75, 30, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit7");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset8", 12.5, 10, 87.5, 30, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit8");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset9", 12.5, 10, 75, 40, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit9");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset10", 12.5, 10, 87.5, 40, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit10");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset11", 12.5, 10, 75, 50, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit11");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset12", 12.5, 10, 87.5, 50, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit12");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset13", 12.5, 10, 75, 60, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit13");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset14", 12.5, 10, 87.5, 60, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit14");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset15", 12.5, 10, 75, 70, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit15");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset16", 12.5, 10, 87.5, 70, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit16");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset17", 12.5, 10, 75, 80, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit17");
    scene->CS_setSceneColor(0xFF, 0x00, 0x00, 127);
    scene->CS_createButtonToScene("Asset18", 12.5, 10, 87.5, 80, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit18");
    scene->CS_setSceneColor(0x00, 0xFF, 0x00, 127);
    scene->CS_createButtonToScene("Asset19", 12.5, 10, 75, 90, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit19");
    scene->CS_setSceneColor(0x00, 0x00, 0xFF, 127);
    scene->CS_createButtonToScene("Asset20", 12.5, 10, 87.5, 90, 1, &closeGame);
    scene->CS_writeTexte(-1, "Exit20");

    scene->CS_setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->CS_createButtonToScene("Exit game", 12, 6, 85, 94, 5, &closeGame);
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