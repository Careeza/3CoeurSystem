#include "editMap.h"

TTF_Font    *CS_Police::font = NULL;

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

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, CS_EditMapSetting& settings, t_actionValue *value)
{
    CS_Timer        timer;
    CS_KeyControl   event;
    CS_Camera       *camera;
    t_actionTable   action;

    int             xCamera;
    int             yCamera;

    int             xMouse;
    int             yMouse;

    xCamera = 0;
    yCamera = 0;
    xMouse = 0;
    yMouse = 0;
    camera = settings.QueryGameScene()->QueryCamera();
    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryGameScene()))
        {
//            std::cout << "boucle here 2" << std::endl;
            if (!bouttonManagement2(event, settings, rend))
                mouseAction(event, settings, xMouse, yMouse, xCamera, yCamera);
            actionKeyManagement(event, value, &action);
            escapeKeyManagement(event, settings, rend);
        }
        useAction2(&action, settings);
        camera->QueryCameraPosition(xCamera, yCamera);
        parallaxManagement(settings, xCamera, yCamera);
        moveAssetSelected(&settings, xMouse + xCamera, yMouse);
//        std::cout << "boucle here 1" << std::endl;
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
//        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
}

int     main(int argc, char **argv)
{
    SDL_Window          *window;
    SDL_Renderer        *render;
    CS_Renderer         rend;
    CS_KeyControl       *event;
    CS_Police           initFont;
    CS_EditMapSetting   settings;
    t_actionValue       value;

    (void)argc;
    (void)argv;    
    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);

    TTF_Init();
    initFont.initPolice("resources/alterebro-pixel-font.ttf");
    
    render = init_renderer(window);

    initSettings(settings, window, render);

    rend.CS_loadRenderer(render);
    
    event = new(CS_KeyControl);

    fillActionValue(&value);

    infiniteLoop(rend, render, settings, &value);

    TTF_Quit();
    SDL_Quit();
    return (0);
}