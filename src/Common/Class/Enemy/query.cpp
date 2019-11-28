#include "gameScene.h"

SDL_Texture *CS_Enemy::queryTexture()
{
    return (enemy->queryTexture());
}

void        CS_Enemy::querySize(int& w, int& h, int& x, int& y)
{
    enemy->querySizePos(w, h, x, y);
}

SDL_Rect    *CS_Enemy::queryFrame()
{
    return (enemy->queryFrame());
}