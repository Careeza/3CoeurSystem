#include "gameScene.h"

void    CS_Layer::createLayer(std::string source, float speedSource)
{
    SDL_Surface *surfaceLayer;

    speed = speedSource;

    surfaceLayer = IMG_load(source.c_str());
    if (!surfaceLayer)
    {
        Tools->verbose(LEVEL1, "s", "error creating surface");
        exit (0);
    }
    layerTexture = SDL_CreateTextureFromSurface(render, surfaceLayer);
	SDL_FreeSurface(surfaceLayer);

    int imgWidth;
    int imgHeight;

    SDL_QueryTexture(Texture, NULL, NULL, &imgWidth, &imgHeight);

    int WindowWidth;
    int WindowHeight;

    WindowWidth = Tools->QueryWindowWidth();
    WindowHeight = Tools->QueryWindowHeight();

    int a;
    int b;

    a = WindowHeight / imgHeight;
    b = imgWidth * a;

    int Resolution;

    Resolution = b / WindowWidth;

    scopeWidth = imgWidth * Resolution;
    scopeHeight = imgHeight;
}