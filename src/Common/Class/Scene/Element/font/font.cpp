# include "scene.h"

CS_Police::CS_Police()
{
    std::cout << "create Polcie" << std::endl;
    size = new (SDL_Rect);
    zoomIn = new (SDL_Rect);
    zoomOut = new (SDL_Rect);

    haveTexture = false;
    zoom = NOZOOM;
    flags = ALIGN_CENTER;
    marginX = 5;
    marginY = 5;
}

CS_Police::~CS_Police()
{
    std::cout << "deleteText" << std::endl;
    delete size;
    delete zoomIn;
    delete zoomOut;
    if (haveTexture)
        SDL_DestroyTexture(texture);
}