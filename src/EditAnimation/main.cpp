#include "editAnimation.h"

TTF_Font    *CS_Police::CS_font = NULL;

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, CS_EditAnimationSetting& settings, t_actionValue *value)
{
    CS_Timer        timer;
    CS_KeyControl   event;
    CS_Camera       *camera;
    t_actionTable   action;

    int             xMouse;
    int             yMouse;

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
                mouseAction(event, settings, xMouse, yMouse);
            actionKeyManagement(event, value, &action);
            escapeKeyManagement(event, settings, rend);
        }
        useAction2(&action, settings);

        if (!settings.isPaused())
        {
            settings.QueryGameScene()->CS_queryMC()->nextFrame();
            settings.QueryGameScene()->CS_queryMC()->getFrame();
        }
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
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
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");
    
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