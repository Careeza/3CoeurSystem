# include "gameScene.h"

void        loadNoMoveCubeGreen(SDL_Renderer *render, CS_Animation* &noMove)
{
    noMove = initAnimation("noMove");
    loadTexture(noMove, render, "resources/source/greenCube.png", "resources/source/greenCube.png");
    cutFrame(noMove, 1, 1, 1);
    setMovement(noMove, 1, 0.0);
    std::cout << "i am here = " << std::endl; 

}

void        loadAllenWalkerGreen(SDL_Renderer *render, CS_Animation* &AllenWalker)
{
    AllenWalker = initAnimation("AllenWalker");
    loadTexture(AllenWalker, render, "resources/source/greenCube.png", "resources/source/greenCube.png");
    cutFrame(AllenWalker, 1, 1, 1);
    setMovement(AllenWalker, 1, 0.75);
}

void        CS_CubeGreen::loadBank(SDL_Renderer *render)
{
    setSize(size, 10, 10 * gameSettings.resolution, 5, 90 - (5 * gameSettings.resolution));
    bank->loadNoMove(render, loadNoMoveCubeGreen);
    bank->loadAllenWalker(render, loadAllenWalkerGreen);
}