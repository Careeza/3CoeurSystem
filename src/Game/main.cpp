#include "common.h"
#include "game.h"

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, t_actionValue *value, CS_Settings& settings)
{
    CS_KeyControl   event;
    CS_Timer        timer;
    CS_Character    *MC;
    CS_Camera       *camera;
    CS_Enemies      *enemies;
    CS_Enemy        *enemy;

    CS_Parallax     *parallax;
    CS_Layer        *layer;

    int             xCamera;
    int             yCamera;

    SDL_Rect        *size;
    int             i;
    int             decalage;

    decalage = Tools->transformWidth(45);
    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryScene()))
        {
            if (settings.QueryPosition() & (homeHome | menuMenu))
            {
                bouttonManagement(event, settings, rend);
            }
            if (settings.QueryPosition() == game)
                actionKeyManagement(event, value, settings);
            escapeKeyManagement(event, settings, rend);
        }
        if (settings.QueryPosition() == game)
        {
            MC = settings.QueryGameScene()->CS_queryMC();
            MC->useAnimation();
            
            size = MC->querySize();
            camera = settings.QueryGameScene()->QueryCamera();
//            camera->moveCamera(size->x - decalage, 0);

            camera->queryCameraPosition(xCamera, yCamera);
            parallax = settings.QueryGameScene()->QueryParallax();
            i = 0;
            while (i < parallax->QueryNbLayers())
            {
                layer = parallax->QueryLayer(i);
                layer->moveLayer(xCamera);
                i++;
            }
            enemies = settings.QueryGameScene()->CS_queryEnemies();
            i = 0;
            while (i < enemies->QueryNbEnemies())
            {
                enemy = enemies->QueryEnemy(i);
                enemy->reloadParam(settings.QueryGameScene()->CS_queryMC());
                i++;
            }
        }
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

    infiniteLoop(rend, render, &value, settings);

    TTF_Quit();
    SDL_Quit();
    return(0);
}