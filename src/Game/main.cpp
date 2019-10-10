#include "class.h"
#include "game.h"

void    keyGlobal(int key)
{
    if (key == SDL_SCANCODE_ESCAPE)
    {
	    if (gameSettings.pos == homeHome)
        {
        }
	    else if (gameSettings.pos == homeHotkeys)
            goToHome();
	    else if (gameSettings.pos == homeVideo)
            goToHome();
	    else if (gameSettings.pos == homeSound)
            goToHome();
	    else if (gameSettings.pos == homeLevelSelect)
            goToHome();
	    else if (gameSettings.pos == menuMenu)
            goToMenu();
	    else if (gameSettings.pos == menuHotkeys)
            goToMenu();
	    else if (gameSettings.pos == menuVideo)
            goToMenu();
	    else if (gameSettings.pos == menuSound)
            goToMenu();
	    else if (gameSettings.pos == game)
            goToMenu();
        else
            std::cout << "lol you are kaki, Fred 2020" << std::endl;
    }
    else
        ;
}

void    escapeKeyManagement(CS_KeyControl event)
{
    int key;
    
    key = event.CS_getKeyboardActions();
    keyGlobal(key);
}


void    infiniteLoop(CS_Renderer render)
{
    CS_KeyControl   event;

    while (!gameSettings.closeRequested)
    {
        while (event.loadEvenement())
        {
            if (gameSettings.pos & (homeHome | menuMenu))
                bouttonManagement(event);
            escapeKeyManagement(event);
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

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
    //window = create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600);

    TTF_Init();
    initFont.CS_initPolice("resources/alterebro-pixel-font.ttf");

    SDL_GetWindowSize(window, &gameSettings.window_width, &gameSettings.window_height);
    gameSettings.resolution = gameSettings.window_width / (float)gameSettings.window_height;
    
    render = init_renderer(window);
    gameSettings.gameScene = init_gameScene(render);
    gameSettings.home = init_home(render);
    gameSettings.menu = init_menu(render);
    gameSettings.controlGame = init_menuHotkeys(render);
    gameSettings.controlHome = init_homeHotkeys(render);
    gameSettings.saveMenu = init_play(render);
    gameSettings.homeVideo = init_homeVideo(render);
    gameSettings.menuVideo = init_menuVideo(render);
    gameSettings.homeSound = init_homeSound(render);
    gameSettings.menuSound = init_menuSound(render);
    gameSettings.current = gameSettings.home;
    gameSettings.currentGame = NULL;

    rend.CS_loadRenderer(render);
    event = new(CS_KeyControl);

    infiniteLoop(rend);

    TTF_Quit();
    SDL_Quit();
    return(0);
}