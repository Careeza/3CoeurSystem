#include "scene.h"

CS_Border::CS_Border()
{
    rectUp = new (SDL_Rect);
    rectDown = new (SDL_Rect);
    rectRight = new (SDL_Rect);
    rectLeft = new (SDL_Rect);

    borderSize_w = 3;
    borderSize_h = 3;
}

CS_Border::~CS_Border()
{
    delete rectUp;
    delete rectDown;
    delete rectRight;
    delete rectLeft;
    SDL_DestroyTexture(texture);
}

void        CS_Border::ChangeSettings(int w, int h)
{
    borderSize_w = w;
    borderSize_h = h;
}
