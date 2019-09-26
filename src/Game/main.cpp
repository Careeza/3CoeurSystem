#include "class.h"
#include "game.h"

void    infiniteLoop(CS_Renderer render, CS_Menu menu)
{
    while (!gameSettings.closeRequested)
    {
        while (menu.event->loadEvenement())
        {
            if (menu.event->queryEventType() == SDL_QUIT)
            {
                gameSettings.closeRequested = true;
            }
            menu.CS_getMouseInfo();
            menu.getButton();
            menu.CS_useButton();
            menu.CS_addBrillance();
        }
        render.CS_dispScene();
    }
}

CS_settings gameSettings = {
    .window_width = 0, 
    .window_height = 0,
    .closeRequested = false,
    .pauseRequested = false,
    .fps = 60,
    .debug = true
};

TTF_Font    *CS_Police::CS_font = NULL;
SDL_Texture *CS_Brightness::texture = NULL;

int     main(void)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Menu         menu;

    CS_Police       initFont;
    CS_Brightness   initBrightness;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
    //window = create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800);

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");

    SDL_GetWindowSize(window, &gameSettings.window_width, &gameSettings.window_height);
    gameSettings.resolution = gameSettings.window_width / (float)gameSettings.window_height;
    
    render = init_renderer(window);
    gameSettings.home = init_scene(render);
    gameSettings.menu = init_scene1(render);
    gameSettings.control = init_scene2(render);
    gameSettings.current = gameSettings.home;

    initBrightness.CS_initBright(render);

    rend.CS_loadRenderer(render);
    rend.CS_loadScene(gameSettings.menu);


    event = new(CS_KeyControl);
    menu.CS_loadKeyControl(event);
    menu.CS_loadScene(gameSettings.menu);

    infiniteLoop(rend, menu);

    TTF_Quit();
    SDL_Quit();
    return(0);
}