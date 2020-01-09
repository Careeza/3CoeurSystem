#include "game.h"

//bool    boucleDialogueBox()
//{
//        CS_Scene    *dialogueBox;

    //init diakogueBox

    //boucle infini
    /*
        même gestions des évènements et des actions que en dessous

        affichage 
    */
//}

/*
Save for the game
    CS_Timer        timer;
    CS_Timer        time;
    t_action        action;
    t_actionTable   actionTable;

    int             xCamera;
    int             yCamera;

    int             t1;
    int             t2;

    int             deltaTMS;

    int             fps = 0;;
    int             i = 1;

    float           deltaTS;

    time.start();
    t1 = 0;
    t2 = 0;
    initActionTable(&actionTable);
    resetAction(&action);

    while (!settings.QueryCloseRequest())
    {
        deltaTMS = t2-t1;
        if (deltaTMS != 0)
            fps += 1000 / (float)deltaTMS;
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
//            else
//                CameraMove(settings, &action, xCamera, yCamera);
            if (settings.QueryGameScene()->haveEnemies())
                enemyManagement(settings);
            if (settings.QueryGameScene()->haveParallax())
                parallaxManagement(settings, xCamera, yCamera);
        }
        render.renderAll(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        render.dispScreen();
//        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
        t2 = time.get_ticks();
        i++;
    }
    std::cout << "FPS = " << fps / (float)i << std::endl;

*/

void    infiniteLoop(CS_Renderer render, t_actionValue *value)
{
    t_pos           pos;
    t_actionTable   actionTable;

    pos = home;
    CS_KeyControl::initActionTable(&actionTable);
    while (pos != close)
    {
        if (pos == home)
            pos = boucleHome(&render, value, &actionTable);
        else if (pos == game)
        {}
        else if (pos == levelSelect)
        {}
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
//  window = create_window(0, "Game", 0, 0, 400, 225);
    SDL_GetWindowSize(window, &w, &h);

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
