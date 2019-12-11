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
    MC = settings.QueryGameScene()->QueryMC();
    MC->getFrame();
    MC->moveCharacter();

    camera = settings.QueryGameScene()->QueryCamera();
    std::cout << "MoveX = " << MC->QueryMoveX() << std::endl;
    camera->moveCamera2(MC->QueryMoveX(), 0, settings.QueryGameScene());
    camera->QueryCameraPosition(xCamera, yCamera);
}

void    CameraMove(CS_Settings& settings, t_actionTable *action, int& xCamera, int& yCamera)
{
    CS_Camera       *camera;

    useAction2(action, settings);
    camera = settings.QueryGameScene()->QueryCamera();
    camera->QueryCameraPosition(xCamera, yCamera);
}

void    enemyManagement(CS_Settings& settings)
{
    CS_Enemies      *enemies;
    CS_Enemy        *enemy;
    int i;

    enemies = settings.QueryGameScene()->QueryEnemies();
    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        enemy->reloadParam(settings.QueryGameScene()->QueryMC());
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
    CS_Timer        time;
    t_actionTable   action;
    int             xCamera;
    int             yCamera;
    int t1;
    int t2;
    int deltat;

    time.start();
    t1 = 0;
    t2 = 0;
    resetActionTable(&action);

    while (!settings.QueryCloseRequest())
    {
        deltat = t2-t1;
        t1 = time.get_ticks();
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
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
        t2 = time.get_ticks();
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

TTF_Font    *CS_Police::font = NULL;

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
    initFont.initPolice("resources/alterebro-pixel-font.ttf");

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
