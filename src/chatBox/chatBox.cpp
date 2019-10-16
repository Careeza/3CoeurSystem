#include "class.h"
#include "game.h"

void    escapeKeyManagementChatBox(CS_KeyControl event)
{
    int         key;
    int         info;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDLK_ESCAPE)
        gameSettings.closeRequested = true;
}

CS_Scene    *init_chatBox(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->CS_createElementToScene("filtre", 100, 100, 0, 0, 0);
    
    scene->CS_setBorderColor(0x00, 0x00, 0x00, 0xFF);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->CS_createElementToScene("filtre", 80, 15, 10, 42.5, 0);
    scene->CS_addBorder(-1);

    return (scene);
}

void    infiniteLoop(CS_Renderer render, t_actionValue *value)
{
    CS_KeyControl   event;
    CS_Timer        timer;

    while (!gameSettings.closeRequested)
    {
        timer.start();
        while (event.loadEvenement())
        {
            bouttonManagement(event);
            escapeKeyManagementChatBox(event);
        }
        render.CS_dispScene();
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
}

CS_settings gameSettings = {
    .window_width = 0, 
    .window_height = 0,
    .closeRequested = false,
    .pauseRequested = false,
    .fps = 60,
    .debug = true,
    .pos = homeHome
};

TTF_Font    *CS_Police::CS_font = NULL;


int     main(void)
{
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Police       initFont;
    t_actionValue   value;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
    
    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");

    SDL_GetWindowSize(window, &gameSettings.window_width, &gameSettings.window_height);
    gameSettings.resolution = gameSettings.window_width / (float)gameSettings.window_height;
    
    render = init_renderer(window);
    gameSettings.home = init_chatBox(render);
    gameSettings.current = gameSettings.home;

    rend.CS_loadRenderer(render);
    event = new(CS_KeyControl);

    fillActionValue(&value);

    infiniteLoop(rend, &value);
    return (0);
}