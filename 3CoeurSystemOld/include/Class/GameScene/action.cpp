


//LAYER

CS_Layer::CS_Layer()
{

}

CS_Layer::~CS_Layer()
{
    SDL_DestroyTexture(texture);
}

void    CS_Layer::createLayer(SDL_Renderer *render, std::string route, int w, int h, int x, int y, int zIndex, float speed)
{
    SDL_Surface *surfaceLayer;

    surfaceLayer = IMG_Load(route.c_str());
    if (!surfaceLayer)
    {
        std::cout << "error creating texture" << std::endl;
        exit (0);
    }
    texture = SDL_CreateTextureFromSurface(render, surfaceLayer);
	SDL_FreeSurface(surfaceLayer);

    this->w = w;
    this->h = h;
    this->x = x;
    this->y = y;

    this->zIndex = zIndex;
    this->speed = speed;
}

void    CS_Layer::QuerySizePos(int& w, int& h, int& x, int& y)
{
    w = this->w;
    h = this->h;
    x = this->x;
    y = this->y;
}

void    CS_Layer::QuerySize(int& w, int& h)
{
    w = this->w;
    h = this->h;
}

void    CS_Layer::QueryPos(int& x, int& y)
{
    x = this->x;
    y = this->y;
}

float   CS_Layer::QuerySpeed()
{
    return (speed);
}

int     CS_Layer::QueryZindex()
{
    return (zIndex);
}


//PARALLAX

CS_Parallax::CS_Parallax()
{

}

CS_Parallax::~CS_Parallax()
{
    int indexk;

    index = layers.size() - 1;
    while (index <= 0)
    {
        delete layers[index];
        layers.pop_back()
        index--;
    }
}

void        CS_Parallax::createLayer(SDL_Renderer *render, std::string route, int w, int h, int x, int y, int zIndex, float speed);
{
    CS_Layer        *layer;
    unsigned long   i;

    layer = new (CS_Layer);
    layer->createLayer(render, route, w, h, x, y, zIndex, speed);

    i = 0;
    while (i < layers.size() && zIndex >= layers[i]->QueryZindex())
        i++;
    layers.emplace(layers.begin() + i, layer);
}

int         CS_Parallax::QueryNbLayers()
{
    return (layers.size());
}

CS_Layer    *CS_Parallax::QueryLayer(int index)
{
    return (layers[index]);
}


//MAP

CS_Map::CS_Map()
{
    xMax = 1920;
    xMin = 0;

    yMin = 1080;
    yMax = 0;

    onScreen = new (CS_OnScreen);
    parallax = new (CS_Parallax);
    assets = new (CS_Assets);
}

CS_Map::~CS_Map()
{
    delete onScreen;
    delete parallax;
    delete assets;
}


void            CS_Map::setBorneX(int xMin, int xMax)
{
    this->xMin = xMin;
    this->xMax = xMax;
}

void            CS_Map::setBorneY(int yMin, int yMax)
{
    this->yMin = yMin;
    this->yMax = yMax;
}

void            CS_Map::loadOnScreen(CS_OnScreen *onScreen)
{
    delete this->onScreen;
    this->onScreen = onScreen;
}

void            CS_Map::loadParallax(CS_Parallax *parallax)
{
    delete this->parallax;
    this->parallax = parallax;
}

void            CS_Map::loadAssets(CS_Assets *assets)
{
    delete this->assets;
    this->assets = assets;
}


//CAMERA

CS_Camera::CS_Camera()
{
    x = 0;
    y = 0;
}


CS_Camera::~CS_Camera()
{

}

void    CS_Camera::setCameraPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void    CS_Camera::moveCamera(int x, int y, bool flag = false, int deltaT = 0, int speed = 0)
{
    if (!flag)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        //DEFINE AVEC LES VITESSES POUR DEPLACEMENT EN X ET EN Y OU VITESSE ENVOYER 
    }
}

void    CS_Camera::QueryCameraPosition(int& x, int& y)
{
    x = this->x;
    y = this->y;
}

int     CS_Camera::QueryCameraPositionX()
{
    return (x);
}

int     CS_Camera::QueryCameraPositionY()
{
    return (y);
}

//GAME SCENE

CS_GameScene::CS_GameScene()
{
    camera = new (CS_Camera);
    camera->setCameraPosition(0, 0);

}

CS_GameScene::~CS_GameScene()
{
    delete camera;
    delete map;
}


void    CS_GameScene::loadCamera(CS_Camera *camera)
{
    delete this->camera;

    this->camera = camera;
}

void            CS_GameScene::loadMap(CS_Map *map)
{
    delete this->map;

    this->map = map;
}


CS_Camera       *CS_GameScene::QueryCamera()
{
    return(camera);
}

CS_Map          *CS_GameScene::QueryMap()
{
    return (map);
}

//TODO 
/*
    CS_Police       initFont;

    TTF_Init();
    initFont.initPolice("resources/alterebro-pixel-font.ttf");
*/