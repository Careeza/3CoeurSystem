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

int     main(void)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Scene        *scene;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Menu         menu;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
    //window = create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2000, 800);
    SDL_GetWindowSize(window, &gameSettings.window_width, &gameSettings.window_height);
    gameSettings.resolution = gameSettings.window_width / (float)gameSettings.window_height;
    std::cout << gameSettings.resolution << std::endl;
    render = init_renderer(window);

    rend.CS_loadRenderer(render);
    scene = init_scene(render);
    rend.CS_loadScene(scene);

    event = new(CS_KeyControl);
    menu.CS_loadKeyControl(event);
    menu.CS_loadScene(scene);

    infiniteLoop(rend, menu);
    delete scene;
    return(0);
}