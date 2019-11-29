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

void            CS_Asset::createAsset(SDL_Renderer *render, std::string source, float wSource, float hSource)
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
}

void            CS_Asset::addAsset(int zIndexSource, float xSource, float ySource)
{
    zIndex = zIndexSource;

    x = Tools->transformX(xSource);
    y = Tools->transformY(ySource);
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