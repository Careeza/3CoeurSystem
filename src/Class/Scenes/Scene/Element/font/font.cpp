# include "scene.h"

CS_Police::CS_Police()
{
    CS_size = new (SDL_Rect);
    CS_zoomIn = new (SDL_Rect);
    CS_zoomOut = new (SDL_Rect);

    zoom = NOZOOM;
    CS_flags = ALIGN_CENTER;
    CS_marginX = 5;
    CS_marginY = 5;
}

CS_Police::~CS_Police()
{
    delete CS_size;
    delete CS_zoomIn;
    delete CS_zoomOut;
    SDL_DestroyTexture(texture);
}