#include "common.h"
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

    if (table->up & !table->down)
        filtre->up = true;
    if (table->down & !table->up)
        filtre->down = true;

    filtre->dodge = table->dodge;
    filtre->jump = table->jump;
}


void    useAction2(t_actionTable *table, CS_Settings& settings)
{
    CS_Camera   *camera;
    CS_Asset    *asset;

    camera = settings.QueryGameScene()->QueryCamera();
    asset = settings.QueryGameScene()->QueryAssets()->QueryAsset(0);
    if (table->dodge == false)
    {
        if (table->right == true)
            asset->resizeAsset(2, 0, true);
        else if (table->left == true)
            asset->resizeAsset(-2, 0, true);
        else if (table->up == true)
            asset->resizeAsset(0, 2, true);
        else if (table->down)
            asset->resizeAsset(0, -2, true);
    }
    else
    {
        if (table->right == true)
            asset->resizeAsset(2, 0, false);
        else if (table->left == true)
            asset->resizeAsset(-2, 0, false);
        else if (table->up == true)
            asset->resizeAsset(0, 2, false);
        else if (table->down)
            asset->resizeAsset(0, -2, false);
    }

    static bool jump = false;

    if (table->jump)
    {
        if (!jump)
            asset->printSize();
        jump = true;
    }
    else
        jump = false;
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

void    infiniteLoop(CS_Renderer render, SDL_Renderer *rend, CS_Settings& settings, t_actionValue *value)
{
    CS_Timer        timer;
    CS_KeyControl   event;
    CS_Camera       *camera;
    t_actionTable   action;
    int             xCamera;
    int             yCamera;

    camera = settings.QueryGameScene()->QueryCamera();
    while (!settings.QueryCloseRequest())
    {
        timer.start();
        while (event.loadEvenement(settings.QueryGameScene()))
        {
//            std::cout << "boucle here 2" << std::endl;
            bouttonManagement(event, settings, rend);
            actionKeyManagement(event, value, &action);
            escapeKeyManagement(event, settings, rend);
        }
        camera->queryCameraPosition(xCamera, yCamera);
        useAction2(&action, settings);
        parallaxManagement(settings, xCamera, yCamera);
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

# define YBigTree01 0.0
# define XBigTree01 34.4

# define YBigTree02 0.0
# define XBigTree02 40.625

# define YBigTree03 0.0
# define XBigTree03 37.1

# define YBushTree01 87.1
# define XBushTree01 40.34

# define YBushTree02 86
# define XBushTree02 39.79

# define YBushTree03 84.7
# define XBushTree03 40

# define YBushTree04 91.8
# define XBushTree04 39.5

# define YGrass01 90.7
# define XGrass01 30.5

# define YGrass02 91.9
# define XGrass02 38.8

# define YGrass03 87.8
# define XGrass03 40.3

# define YGrass04 89.8
# define XGrass04 42.5

# define YGrass05 88
# define XGrass05 44.5

# define YGround01 96
# define XGround01 0

# define YMediumTree01 28.2
# define XMediumTree01 44.8

# define YMediumTree02 35.6
# define XMediumTree02 44.8

# define YMediumTree03 43.1
# define XMediumTree03 54

# define YSmallTree01 59.3
# define XSmallTree01 62.7

# define YSmallTree02 53.8
# define XSmallTree02 63

# define YSmallTree03 48
# define XSmallTree03 61.3

# define YSmallTree04 53.4
# define XSmallTree04 63.2

CS_AssetsBank   *initAssetsBankLevel1(SDL_Renderer *render)
{
    CS_AssetsBank *assetsBank;

    assetsBank = new (CS_AssetsBank);

    assetsBank->createAsset(render, "resources/source/assets/BigTree01.png", BigTree01, 30.4, 96);
    assetsBank->createAsset(render, "resources/source/assets/BigTree02.png", BigTree02, 18.75, 96);
    assetsBank->createAsset(render, "resources/source/assets/BigTree03.png", BigTree03, 25.4, 96);
    assetsBank->createAsset(render, "resources/source/assets/BushTree01.png", BushTree01, 10.5, 8.9);
    assetsBank->createAsset(render, "resources/source/assets/BushTree02.png", BushTree02, 11, 10);
    assetsBank->createAsset(render, "resources/source/assets/BushTree03.png", BushTree03, 9.4, 11.3);
    assetsBank->createAsset(render, "resources/source/assets/BushTree04.png", BushTree04, 10.9, 4.2);
    assetsBank->createAsset(render, "resources/source/assets/Grass01.png", Grass01, 33.3, 5.3);
    assetsBank->createAsset(render, "resources/source/assets/Grass02.png", Grass02, 2.4, 4.1);
    assetsBank->createAsset(render, "resources/source/assets/Grass03.png", Grass03, 6.9, 8.2);
    assetsBank->createAsset(render, "resources/source/assets/Grass04.png", Grass04, 5.5, 6.2);
    assetsBank->createAsset(render, "resources/source/assets/Grass05.png", Grass05, 5.8, 8);
    assetsBank->createAsset(render, "resources/source/assets/Ground01.png", Ground01, 10, 5.8);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree01.png", MediumTree01, 10, 67.8);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree02.png", MediumTree02, 10, 60.4);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree03.png", MediumTree03, 4.3, 52.9);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree01.png", SmallTree01, 2.8, 36.7);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree02.png", SmallTree02, 1.9, 42.2);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree03.png", SmallTree03, 3.75, 48);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree04.png", SmallTree04, 2.3, 42.6);

    return (assetsBank);
}

CS_Assets       *initAssets(SDL_Renderer *render)
{
    CS_Assets *assets;

    assets = new (CS_Assets);

    assets->loadBank(initAssetsBankLevel1(render));

    //assets->loadAsset(BigTree01, 1, XBigTree02, YBigTree01);
    //assets->loadAsset(BigTree02, 1, XBigTree02, YBigTree02);
    //assets->loadAsset(BigTree03, 1, XBigTree03, YBigTree03);
    //assets->loadAsset(BushTree01, 1, XBushTree01, YBushTree01);
    //assets->loadAsset(BushTree02, 1, XBushTree02, YBushTree02);
    //assets->loadAsset(BushTree03, 1, XBushTree03, YBushTree03);
    //assets->loadAsset(BushTree04, 1, XBushTree04, YBushTree04);
    //assets->loadAsset(Grass01, 1, XGrass01, YGrass01);
    //assets->loadAsset(Grass02, 1, XGrass02, YGrass02);
    //assets->loadAsset(Grass03, 1, XGrass03, YGrass03);
    //assets->loadAsset(Grass04, 1, XGrass04, YGrass04);
    //assets->loadAsset(Grass05, 1, XGrass05, YGrass05);
    //assets->loadAsset(MediumTree01, 1, XMediumTree01, YMediumTree01);
    //assets->loadAsset(MediumTree02, 1, XMediumTree02, YMediumTree02);
    //assets->loadAsset(MediumTree03, 1, XMediumTree03, YMediumTree03);
    //assets->loadAsset(SmallTree01, 1, XSmallTree01, YSmallTree01);
    //assets->loadAsset(SmallTree02, 1, XSmallTree02, YSmallTree02);
    //assets->loadAsset(SmallTree03, 1, XSmallTree03, YSmallTree03);
    //assets->loadAsset(SmallTree04, 1, XSmallTree04, YSmallTree04);

    assets->loadAsset(Ground01, 1, 0, 96);
    assets->loadAsset(Ground01, 1, 10, 96);
    assets->loadAsset(Ground01, 1, 20, 96);
    assets->loadAsset(Ground01, 1, 30, 96);
    assets->loadAsset(Ground01, 1, 40, 96);
    assets->loadAsset(Ground01, 1, 50, 96);
    assets->loadAsset(Ground01, 1, 60, 96);
    assets->loadAsset(Ground01, 1, 70, 96);
    assets->loadAsset(Ground01, 1, 80, 96);
    assets->loadAsset(Ground01, 1, 90, 96);

    return (assets);
}

CS_GameScene    *init_home(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);
    
    scene->loadParallax(initParallax(render));
    scene->loadAssets(initAssets(render));
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
    SDL_Window      *window;
    SDL_Renderer    *render;
    CS_Renderer     rend;
    CS_KeyControl   *event;
    CS_Police       initFont;
    CS_Settings     settings;
    t_actionValue   value;
    
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