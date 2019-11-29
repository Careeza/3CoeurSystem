# include "gameScene.h"

CS_Asset::CS_Assets()
{
    size = new (SDL_Rect);
}

~CS_Assets()
{
    delete size;
    delete texture;
}

void            CS_Asset::createAsset(SDL_Renderer *render, std::string source, float w, float h)
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

    size->w = Tools->transformWidth(w);
    size->h = Tools->transformHeight(h);
}

void            CS_Asset::addAsset(int zIndexSource, float x, float y)
{
    zIndex = zIndexSource;

    size->x = Tools->transformX(x);
    size->y = Tools->transformY(y);
}

SDL_Texture     *CS_Asset::QueryTexture()
{
    return (texture);
}

SDL_Rect        *CS_Asset::QuerySize()
{
    return (size);
}

t_assetName     CS_Asset::QueryName()
{
    return (name);
}

int             QueryZIndex()
{
    return (zIndex);
}