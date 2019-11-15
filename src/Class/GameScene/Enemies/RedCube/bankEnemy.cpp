# include "gameScene.h"

void        loadNoMoveCubeRed(SDL_Renderer *render, CS_Animation* &noMove)
{
    noMove = initAnimation("noMove");
    loadTexture(noMove, render, "resources/source/redCube.png", "resources/source/redCube.png");
    cutFrame(noMove, 1, 1, 1);
    setMovement(noMove, 1, 0.0);
    std::cout << "i am here = " << std::endl; 
}

void        loadAllenWalkerRed(SDL_Renderer *render, CS_Animation* &AllenWalker)
{
    AllenWalker = initAnimation("AllenWalker");
    loadTexture(AllenWalker, render, "resources/source/redCube.png", "resources/source/redCube.png");
    cutFrame(AllenWalker, 1, 1, 1);
    setMovement(AllenWalker, 1, 0.5);
}

void        CS_Cube::loadBank(SDL_Renderer *render)
{
    setSize(size, 10, 10 * gameSettings.resolution, 5, 90 - (5 * gameSettings.resolution));
    bank->loadNoMove(render, loadNoMoveCubeRed);
    bank->loadAllenWalker(render, loadAllenWalkerRed);
}