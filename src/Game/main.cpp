#include "game.h"

bool    boucleDialogueBox()
{
    CS_Scene    *dialogueBox;

    //init diakogueBox

    //boucle infini
    /*
        même gestions des évènements et des actions que en dessous

        affichage 
    */
}

// Exemple de render possible
/*

    => Start by creating the texture and switching the render target

    SDL_Texture *Screen

    Screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCES_TARGET, windowW, windowH);

    SDL_SetRenderTarget(renderer, texture); // => On va dessiner sur la texture

    => Lors du render faire 

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(render, screen, NULL, NULL);
    SDL_SetRenderTarget(renderer, texture);

*/

void    boucleHome() // => need le render et les settings et la texture screen
{
    CS_Scene    *BackGround;
    CS_Scene    *home;
    CS_Scene    *homeKey;

    //initHome
    //initHomeKey

    // boucle infi
    /*
        gestion des evenements () => Une gestion basique uniqument des boutons !
            => refactor des fonctions des boutons ?
            => Renvoie une valeur dans un tableau ?
                => Ex bouton 1 leads to input 'z'

        utulisation si nécessaire de l'action
            => Z is pressed so do this
                => Z need a verification (dialogue box)
                    => set dialogue box aff a true + disable all the other evenemnt

        affichage en fonction => Refactor du render plus précis
        => Afficher une scènes (idée afficher groupe de scène)
            => affAllScene(int nbr scene, ...);

            => is home aff ? 
                => aff home
            => is homeKey aff ?
                => aff key
    */

    delete home;
    delete homeKey;
}

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, t_actionValue *value, CS_Settings& settings, SDL_Texture *screen)
{
    CS_Timer        timer;
    CS_Timer        time;
    t_action        action;
    t_actionTable   actionTable;

    int             xCamera;
    int             yCamera;

    int             t1;
    int             t2;

    int             deltaTMS;
    float           deltaTS;

    time.start();
    t1 = 0;
    t2 = 0;
    initActionTable(&actionTable);
    resetAction(&action);

    while (!settings.QueryCloseRequest())
    {
        deltaTMS = t2-t1;
        deltaTS = deltaTMS / (float)1000;
        t1 = time.get_ticks();
        timer.start();
        eventManagement(settings, rend, value, &actionTable, &action);
        if (settings.QueryPosition() == game)
        {
            transformActionTable(&actionTable);
            fillAction(&actionTable, &action);
            if (settings.QueryGameScene()->haveMC())
                MCManagement(settings, &action, xCamera, yCamera, deltaTS, deltaTMS);
            else
                CameraMove(settings, &action, xCamera, yCamera);
            if (settings.QueryGameScene()->haveEnemies())
                enemyManagement(settings);
            if (settings.QueryGameScene()->haveParallax())
                parallaxManagement(settings, xCamera, yCamera);
        }
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        render.CS_dispScene2(screen);
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

void    initGame(CS_Settings& settings, SDL_Renderer* &render, CS_Renderer& rend, SDL_Texture* &screen)
{
    SDL_Window      *window;
    CS_Police       initFont;
    int w;
    int h;

    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
//  window = create_window(0, "Game", 0, 0, 400, 225);
    SDL_GetWindowSize(window, &w, &h);

    TTF_Init();
    initFont.initPolice("resources/alterebro-pixel-font.ttf");

    render = init_renderer(window);

    screen = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCESS_TARGET, w, h);

    SDL_SetRenderTarget(render, screen); // => On va dessiner sur la texture
    
    initSettings(settings, window, render);
    rend.CS_loadRenderer(render);
}

int     main(int argc, char **argv)
{
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_Settings     settings;
    t_actionValue   value;
    SDL_Texture     *screen;

    (void)argc;
    (void)argv;

    init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    initGame(settings, render, rend, screen);
    fillActionValue(&value);

    infiniteLoop(rend, render, &value, settings, screen);

    TTF_Quit();
    SDL_Quit();
    return(0);
}
