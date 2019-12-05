#include "gameScene.h"

SDL_Texture *CS_Enemy::QueryTexture()
{
    return (enemy->QueryTexture());
}

void        CS_Enemy::QuerySize(int& w, int& h, int& x, int& y)
{
    enemy->QuerySizePos(w, h, x, y);
}

SDL_Rect    *CS_Enemy::QueryFrame()
{
    return (enemy->QueryFrame());
}