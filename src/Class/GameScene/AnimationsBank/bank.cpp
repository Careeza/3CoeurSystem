# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    noMove = initAnimation("noMove");
    loadTexture(noMove, render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png");
    cutFrame(noMove, 1, 1, 1);
    setMovement(noMove, 1, 0.0);
}

void        CS_BankAnimation::loadAllenWalker(SDL_Renderer *render)
{
    AllenWalker = initAnimation("AllenWalker");
    loadTexture(AllenWalker, render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    cutFrame(AllenWalker, 5, 5, 1);
    setMovement(AllenWalker, 5, 1.0, 1.0, 1.0, 1.0, 1.0);
}

void        setSize(SDL_Rect *size, float w, float h, float x, float y)
{
    size->w = (w * gameSettings.window_width) / 100.0;
    size->h = (h * gameSettings.window_height) / 100.0;
    size->x = (x * gameSettings.window_width) / 100.0;
    size->y = (y * gameSettings.window_height) / 100.0;
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    setSize(size, 10, 10 * gameSettings.resolution, 45, 90 - (5 * gameSettings.resolution));
    bank->loadNoMove(render);
    bank->loadAllenWalker(render);
}