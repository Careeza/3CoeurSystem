#include "common.h"
#include "game.h"

void    eventManagement(CS_Settings& settings, SDL_Renderer *rend, t_actionValue *value, t_actionTable *action)
{
    CS_KeyControl   event;

    while (event.loadEvenement(settings.QueryScene()))
    {
        if (settings.QueryPosition() & (homeHome | menuMenu))
            bouttonManagement(event, settings, rend);
        if (settings.QueryPosition() == game)
            actionKeyManagement(event, value, action);
        escapeKeyManagement(event, settings, rend);
    }
}

void    MCManagement(CS_Settings& settings, t_actionTable *action, int& xCamera, int& yCamera)
{
    CS_Character    *MC;
    CS_Camera       *camera;

    useAction(action, settings);
    MC = settings.QueryGameScene()->CS_queryMC();
    MC->getFrame();
    MC->moveCharacter();

    camera = settings.QueryGameScene()->QueryCamera();
    camera->moveCamera2(MC->queryMoveX(), 0, settings.QueryGameScene());
    camera->queryCameraPosition(xCamera, yCamera);
}

void    CameraMove(CS_Settings& settings, t_actionTable *action, int& xCamera, int& yCamera)
{
    CS_Camera       *camera;

    useAction2(action, settings);
    camera = settings.QueryGameScene()->QueryCamera();
    camera->queryCameraPosition(xCamera, yCamera);
}

void    enemyManagement(CS_Settings& settings)
{
    CS_Enemies      *enemies;
    CS_Enemy        *enemy;
    int i;

    enemies = settings.QueryGameScene()->CS_queryEnemies();
    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        enemy->reloadParam(settings.QueryGameScene()->CS_queryMC());
        enemy->getFrame();
        enemy->moveCharacter();
    i++;
    }
}

void    parallaxManagement(CS_Settings& settings, int xCamera, int yCamera)
{
    CS_Parallax     *parallax;
    CS_Layer        *layer;
    int             i;

    (void)yCamera;
    parallax = settings.QueryGameScene()->QueryParallax();
    i = 0;
    while (i < parallax->QueryNbLayers())
    {
        layer = parallax->QueryLayer(i);
        layer->moveLayer(xCamera);
        i++;
    }
}

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, t_actionValue *value, CS_Settings& settings)
{
    CS_Timer        timer;
    t_actionTable   action;
    int             xCamera;
    int             yCamera;

    resetActionTable(&action);
    while (!settings.QueryCloseRequest())
    {
        timer.start();
        eventManagement(settings, rend, value, &action);
        if (settings.QueryPosition() == game)
        {
            if (settings.QueryGameScene()->haveMC())
                MCManagement(settings, &action, xCamera, yCamera);
            else
                CameraMove(settings, &action, xCamera, yCamera);
            if (settings.QueryGameScene()->haveEnemies())
                enemyManagement(settings);
            if (settings.QueryGameScene()->haveParallax())
                parallaxManagement(settings, xCamera, yCamera);
        }
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
//        SDL_Delay(fmax(0, (1000 / 60) - timer.get_ticks()));
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
    settings.initScene(init_home(render));
    settings.initGameScene(init_gameScene(render));
}

TTF_Font    *CS_Police::CS_font = NULL;

int     main(int argc, char **argv)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Police       initFont;
    CS_Settings     settings;
    t_actionValue   value;

    (void)argc;
    (void)argv;
    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
//    window = create_window(0, "Game", 0, 0, 2560, 1600);

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");
    
    render = init_renderer(window);

    initSettings(settings, window, render);

    rend.CS_loadRenderer(render);
    event = new(CS_KeyControl);

    fillActionValue(&value);

    infiniteLoop(rend, render, &value, settings);

    TTF_Quit();
    SDL_Quit();
    return(0);
}