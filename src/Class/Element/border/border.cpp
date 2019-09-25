#include "scene.h"

CS_Border::CS_Border()
{
    rectUp = new (SDL_Rect);
    rectDown = new (SDL_Rect);
    rectRight = new (SDL_Rect);
    rectLeft = new (SDL_Rect);

    borderSize_w = 10;
    borderSize_h = 10;
}

CS_Border::~CS_Border()
{
    delete rectUp;
    delete rectDown;
    delete rectRight;
    delete rectLeft;
    SDL_DestroyTexture(texture);
}

void        CS_Border::CS_ChangeSettings(int w, int h)
{
    borderSize_w = w;
    borderSize_h = h;
}