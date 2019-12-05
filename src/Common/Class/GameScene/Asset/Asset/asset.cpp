# include "gameScene.h"

CS_Asset::CS_Asset()
{
    w = 0;
    h = 0;
    x = 0;
    y = 0;
}

CS_Asset::~CS_Asset()
{
    SDL_DestroyTexture(texture);
}

void            CS_Asset::createAsset(SDL_Renderer *render, std::string source, t_assetName nameSource, float wSource, float hSource)
{
    SDL_Surface *surfaceAsset;

    surfaceAsset = IMG_Load(source.c_str());
    if (!surfaceAsset)
    {
        Tools->verbose(LEVEL1, "s", "error creating surface");
        exit (0);
    }
    texture = SDL_CreateTextureFromSurface(render, surfaceAsset);
	SDL_FreeSurface(surfaceAsset);

    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);

    name = nameSource;
}

void            CS_Asset::addAsset(int zIndexSource, float xSource, float ySource)
{
    zIndex = zIndexSource;

    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
}

void            CS_Asset::addAssetPixel(int zIndexSource, int xSource, int ySource)
{
    zIndex = zIndexSource;

    x = xSource;
    y = ySource;
}

void            CS_Asset::setTexture(SDL_Texture *textureSource)
{
    texture = textureSource;
}

void            CS_Asset::setName(t_assetName nameSource)
{
    name = nameSource;
}

void            CS_Asset::setSize(int wSource, int hSource)
{
    w = wSource;
    h = hSource;
}

void            CS_Asset::setID(int idSource)
{
    id = idSource;
}

int             CS_Asset::QueryID()
{
    return (id);
}

int             CS_Asset::QueryWidth()
{
    return (w);
}

int             CS_Asset::QueryHeight()
{
    return (h);
}


SDL_Texture     *CS_Asset::QueryTexture()
{
    return (texture);
}

void        CS_Asset::QuerySize(int& wDest, int& hDest, int& xDest, int &yDest)
{
    wDest = w;
    hDest = h;
    xDest = x;
    yDest = y;
}

t_assetName     CS_Asset::QueryName()
{
    return (name);
}

int             CS_Asset::QueryZIndex()
{
    return (zIndex);
}

CS_HitBox       *CS_Asset::QueryHitBox()
{
    return (hitBox);
}


void            CS_Asset::moveAsset(int xSource, int ySource, bool method)
{
    if (method == true)
    {
        x = xSource;
        y = ySource;
    }
    else
    {
        x += xSource;
        y += ySource;
    }
}

void            CS_Asset::resizeAsset(int wSource, int hSource, bool method)
{
    if (method == true)
    {
        w += wSource;
        h += hSource;
        x -= wSource / 2;
        y -= hSource / 2;
    }
    else
    {
        x += wSource / 2;
        y += hSource / 2;
    }
}

void            CS_Asset::printSize()
{
    std::cout << "size w = " << w / (float)Tools->QueryWindowWidth() * 100 << " size h = " << h / (float)Tools->QueryWindowHeight() * 100 << std::endl;
    std::cout << "size x = " << x / (float)Tools->QueryWindowWidth() * 100 << " size y = " << y / (float)Tools->QueryWindowHeight() * 100 << std::endl;
}
