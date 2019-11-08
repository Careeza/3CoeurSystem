# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render, void (*f)(SDL_Renderer *render, CS_Animation* &animation))
{
    f(render, noMove);
}

void        CS_BankAnimation::loadAllenWalker(SDL_Renderer *render, void (*f)(SDL_Renderer *render, CS_Animation* &animation))
{
    f(render, AllenWalker);
}


void        setSize(SDL_Rect *size, float w, float h, float x, float y)
{
    size->w = (w * gameSettings.window_width) / 100.0;
    size->h = (h * gameSettings.window_height) / 100.0;
    size->x = (x * gameSettings.window_width) / 100.0;
    size->y = (y * gameSettings.window_height) / 100.0;
}