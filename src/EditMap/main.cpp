#include "editMap.h"

TTF_Font    *CS_Police::CS_font = NULL;

void    escapeAction(CS_Settings& settings, SDL_Renderer *render)
{
    closeGame(&settings, render);
}

void    escapeKeyManagement(CS_KeyControl event, CS_Settings& settings, SDL_Renderer *render)
{
    int         key;
    int         info;
    static bool keyPress;
 
    info = event.CS_getKeyboardActions(key);
    if (key == SDLK_ESCAPE)
    {
        if (keyPress == false)
            escapeAction(settings, render);
        if (info == CS_KEYDOWN)
            keyPress = true;
        else
            keyPress = false;
    }
}

void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info)
{
    if (info == CS_KEYDOWN)
    {
        if (value->up == key)
            table->up = true;
        else if (value->down == key)
            table->down = true;
        else if (value->right == key)
            table->right = true;
        else if (value->left == key)
            table->left = true;
        else if (value->jump == key)
            table->jump = true;
        else if (value->dodge == key)
            table->dodge = true;
        else if (value->att == key)
            table->att = true;
        else if (value->att_sp == key)
            table->att_sp = true;
        else if (value->use == key)
            table->use = true;
        else if (value->spell_1 == key)
            table->spell_1 = true;
        else if (value->spell_2 == key)
            table->spell_2 = true;
    }
    else if (info == CS_KEYUP)
    {
        if (value->up == key)
            table->up = false;
        else if (value->down == key)
            table->down = false;
        else if (value->right == key)
            table->right = false;
        else if (value->left == key)
            table->left = false;
        else if (value->jump == key)
            table->jump = false;
        else if (value->dodge == key)
            table->dodge = false;
        else if (value->att == key)
            table->att = false;
        else if (value->att_sp == key)
            table->att_sp = false;
        else if (value->use == key)
            table->use = false;
        else if (value->spell_1 == key)
            table->spell_1 = false;
        else if (value->spell_2 == key)
            table->spell_2 = false;
    }
    else
    {}
}

void    fillActionValue(t_actionValue *value)
{
    value->up = SDLK_z;
    value->down = SDLK_s;
    value->right = SDLK_d;
    value->left = SDLK_q;
    value->jump = SDLK_SPACE;
    value->dodge = SDLK_LSHIFT;
    value->att = -1;
    value->att_sp = -1;
    value->use = SDLK_f;
    value->spell_1 = SDLK_a;
    value->spell_2 = SDLK_e;
}

void    resetActionTable(t_actionTable *table)
{
    table->up = false;
    table->down = false;
    table->right = false;
    table->left = false;
    table->jump = false;
    table->dodge = false;
    table->att = false;
    table->att_sp = false;
    table->use = false;
    table->spell_1 = false;
    table->spell_2 = false;
}

void    filtreActionTable(t_actionTable *table, t_actionTable *filtre)
{
    resetActionTable(filtre);
//    std::cout << "reset" << std::endl;
    if (table->right & !table->left)
        filtre->right = true;
    if (table->left & !table->right)
        filtre->left = true;
    filtre->dodge = table->dodge;
}


void    useAction2(t_actionTable *table, CS_Settings& settings)
{
    CS_Camera    *camera;

    camera = settings.QueryGameScene()->QueryCamera();
    if (table->right == true)
    {
//        std::cout << "press" << std::endl;
        camera->moveCamera2(25, 0);
    }
    else if (table->left == true)
    {
//        std::cout << "press" << std::endl;
        camera->moveCamera2(-25, 0);
    }
    else
    {
//        std::cout << "No press" << std::endl;
    }
}

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, t_actionTable *action)
{
    int                     key;
    int                     info;
    static t_actionTable    table;
    static int              i = 0;
 
    if (i == 0)
    {
        resetActionTable(&table);
        i++;
    }
    info = event.CS_getKeyboardActions(key);
    fillActionTable(&table, value, key, info);
    filtreActionTable(&table, action);
}

void    parallaxManagement(CS_Settings& settings, int xCamera, int yCamera)
{
    CS_Parallax     *parallax;
    CS_Layer        *layer;
    int             i;

    parallax = settings.QueryGameScene()->QueryParallax();
    i = 0;
    while (i < parallax->QueryNbLayers())
    {
        layer = parallax->QueryLayer(i);
        layer->moveLayer(xCamera);
        i++;
    }
}

void    moveAssetSelected(CS_Asset *asset);


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
    int             buttonInfo;

    camera = settings.QueryGameScene()->QueryCamera();
    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryGameScene()))
        {
//            std::cout << "boucle here 2" << std::endl;
            bouttonManagement2(event, settings, rend);
            buttonInfo = event.CS_getMouseActions(xMouse, yMouse);
            actionKeyManagement(event, value, &action);
            escapeKeyManagement(event, settings, rend);
        }
        camera->queryCameraPosition(xCamera, yCamera);
        useAction2(&action, settings);
        parallaxManagement(settings, xCamera, yCamera);
        moveAssetSelected();
//        std::cout << "boucle here 1" << std::endl;
        render.CS_dispScene(settings.QueryScene(), settings.QueryGameScene(), settings.QueryPosition());
        SDL_Delay(fmax(0, (1000 / 30) - timer.get_ticks()));
    }
}

CS_Camera       *initCamera()
{
    CS_Camera *camera;

    camera = new (CS_Camera);
    return (camera);
}

CS_Parallax     *initParallax(SDL_Renderer *render)
{
    CS_Parallax *parallax;


    parallax = new (CS_Parallax);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer0.png", 0.0625, 0);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer1.png", 0.125, 1);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer2.png", 0.25, 2);
    parallax->createLayer(render, "resources/source/FondNeige/FOND2/backgroundlayer3.png", 0.5, 3);

    return (parallax);
}

CS_GameScene    *init_home(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0xFF, 0xFF, 0xFF, 0xFF);
//    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToSceneFromPng("Asset1", "resources/source/assets/BigTree01.png", 12.5, 10, 75, 0, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset2", "resources/source/assets/BigTree02.png", 12.5, 10, 87.5, 0, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset3", "resources/source/assets/BigTree03.png", 12.5, 10, 75, 10, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset4", "resources/source/assets/BushTree01.png", 12.5, 10, 87.5, 10, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset5", "resources/source/assets/BushTree02.png", 12.5, 10, 75, 20, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset6", "resources/source/assets/BushTree03.png", 12.5, 10, 87.5, 20, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset7", "resources/source/assets/BushTree04.png", 12.5, 10, 75, 30, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset8", "resources/source/assets/Grass01.png", 12.5, 10, 87.5, 30, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset9", "resources/source/assets/Grass02.png", 12.5, 10, 75, 40, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset10", "resources/source/assets/Grass03.png",  12.5, 10, 87.5, 40, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset11", "resources/source/assets/Grass04.png",  12.5, 10, 75, 50, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset12", "resources/source/assets/Grass05.png",  12.5, 10, 87.5, 50, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset13", "resources/source/assets/Ground01.png",  12.5, 10, 75, 60, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset14", "resources/source/assets/MediumTree01.png",  12.5, 10, 87.5, 60, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset15", "resources/source/assets/MediumTree02.png",  12.5, 10, 75, 70, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset16", "resources/source/assets/MediumTree03.png",  12.5, 10, 87.5, 70, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset17", "resources/source/assets/SmallTree01.png",  12.5, 10, 75, 80, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset18", "resources/source/assets/SmallTree02.png",  12.5, 10, 87.5, 80, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset19", "resources/source/assets/SmallTree03.png",  12.5, 10, 75, 90, 1, &closeGame);
    scene->CS_createButtonToSceneFromPng("Asset20", "resources/source/assets/SmallTree04.png",  12.5, 10, 87.5, 90, 1, &closeGame);

    scene->loadParallax(initParallax(render));
    scene->loadCamera(initCamera());

    return (scene);
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
    settings.getPosition(game);
    Tools->getWindowSize(settings.QueryWindowsWidth(), settings.QueryWindowsHeight());
    settings.initGameScene(init_home(render));
//    settings.initGameScene(render);
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