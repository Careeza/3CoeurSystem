#include "gameScene.h"

SDL_Texture *CS_Enemy::queryTexture()
{
    return (enemy->queryTexture());
}

SDL_Rect    *CS_Enemy::querySize()
{
    return (enemy->querySize());
}

SDL_Rect    *CS_Enemy::queryFrame()
{
    return (enemy->queryFrame());
}