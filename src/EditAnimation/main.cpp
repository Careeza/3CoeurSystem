#include "editAnimation.h"

TTF_Font    *CS_Police::font = NULL;

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, CS_EditAnimationSetting& settings, t_actionValue *value)
{
    CS_Timer        timer;
    CS_KeyControl   event;
    CS_Camera       *camera;
    t_action        action;
    t_actionTable   actionTable;

    CS_Timer        time;
    int             t1;
    int             t2;
    int             deltaTMS;

    int             xMouse;
    int             yMouse;

    xMouse = 0;
    yMouse = 0;
    time.start();
    t1 = 0;
    t2 = 0;
    camera = settings.QueryGameScene()->QueryCamera();
    while (!settings.QueryCloseRequest())
    {
        deltaTMS = t2-t1;
        t1 = time.get_ticks();
        timer.start();
        while (event.loadEvenement(settings.QueryGameScene()))
        {
//            std::cout << "boucle here 2" << std::endl;
            if (!bouttonManagement2(event, settings, rend))
                mouseAction(event, settings, xMouse, yMouse);
            actionKeyManagement(event, value, &actionTable, &action);
            escapeKeyManagement(event, settings, rend);
        }
        transformActionTable(&actionTable);
        fillAction(&actionTable, &action);
        useAction2(&action, settings);

        if (!settings.isPaused())
        {
            settings.QueryGameScene()->QueryMC()->updateFrame(deltaTMS);
            settings.QueryGameScene()->QueryMC()->getFrame();
        }
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        SDL_Delay(fmax(0, (1000 / (float)settings.QueryFps()) - timer.get_ticks()));
        t2 = time.get_ticks();
    }
}

int     main(int argc, char **argv)
{
    SDL_Window              *window;
    SDL_Renderer            *render;
    CS_Renderer             rend;
    CS_KeyControl           *event;
    CS_Police               initFont;
    CS_EditAnimationSetting settings;
    t_actionValue           value;
    
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