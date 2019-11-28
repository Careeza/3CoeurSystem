#include "gameScene.h"

void    CS_Layer::createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndexSource)
{
    SDL_Surface *surfaceLayer;

    surfaceLayer = IMG_Load(source.c_str());
    if (!surfaceLayer)
    {
        Tools->verbose(LEVEL1, "s", "error creating surface");
        exit (0);
    }
    layerTexture = SDL_CreateTextureFromSurface(render, surfaceLayer);
	SDL_FreeSurface(surfaceLayer);

    SDL_QueryTexture(layerTexture, NULL, NULL, &textureW, &textureH);

    int WindowWidth;
    int WindowHeight;

    WindowWidth = Tools->QueryWindowWidth();
    WindowHeight = Tools->QueryWindowHeight();

    float a;
    float b;

    a = WindowHeight / (float)textureH;
    b = textureW * a;

    float Resolution;

    Resolution = WindowWidth / (float)b;

    std::cout << "resolution = " << Resolution << std::endl;

    scopeWidth = textureW * Resolution;
    scopeHeight = textureH;

    scopeMain->w = scopeWidth;
    scopeMain->h = scopeHeight;
    scopeMain->x = 0;
    scopeMain->y = 0;

    scopeSecond->w = 0;
    scopeSecond->h = 0;
    scopeSecond->x = 0;
    scopeSecond->y = 0;

    sizeMain->w = WindowWidth;
    sizeMain->h = WindowHeight;
    sizeMain->x = 0;
    sizeMain->y = 0;

    sizeSecond->w = 0;
    sizeSecond->h = 0;
    sizeSecond->x = 0;
    sizeSecond->y = 0;

    speed = speedSource;
    zIndex = zIndexSource;
    needSecondScope = false;
}