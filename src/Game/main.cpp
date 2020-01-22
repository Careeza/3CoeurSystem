#include "game.h"

void    infiniteLoop(CS_Renderer render, t_actionValue *value)
{
    t_pos           pos;
    t_actionTable   actionTable;

    pos = game;
    CS_KeyControl::initActionTable(&actionTable);
//    logoCinematics(&render, value, &actionTable);
//    homeCinematics(&render, value, &actionTable);
    while (pos != close)
    {
        if (pos == home)
            pos = loopHome(&render, value, &actionTable);
        else if (pos == levelSelect)
            pos = loopLevelSelect(&render, value, &actionTable);
        else if (pos == game)
            pos = loopGame(&render, value, &actionTable);
    }
}

void    initGame(CS_Renderer& rend)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Police       initFont;
    int w;
    int h;

    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI);
//    window = create_window(SDL_WINDOW_ALLOW_HIGHDPI, "Game", 0, 0, 1920, 1080);
    SDL_GL_GetDrawableSize(window, &w, &h);

    Tools->getWindowSize(w, h);

    TTF_Init();
    initFont.initPolice("resources/alterebro-pixel-font.ttf");

    render = init_renderer(window);
    rend.loadRenderer(render);
}

int     main(int argc, char **argv)
{
    CS_Renderer     render;
    t_actionValue   value;

    (void)argc;
    (void)argv;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    initGame(render);
    CS_KeyControl::fillActionValue(&value);

    infiniteLoop(render, &value);

    TTF_Quit();
    SDL_Quit();
    return(0);
}
