# include "scene.h"

CS_Police::CS_Police()
{
    CS_size = new (SDL_Rect);
    CS_flags = ALIGN_CENTER;
    CS_marginX = 5;
    CS_marginY = 5;
}

CS_Police::~CS_Police()
{
    delete CS_size;
    SDL_DestroyTexture(texture);
}