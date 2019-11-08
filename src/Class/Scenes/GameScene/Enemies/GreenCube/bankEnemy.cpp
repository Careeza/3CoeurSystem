# include "gameScene.h"

void        loadNoMoveCubeGreen(SDL_Renderer *render, CS_Animation* &noMove)
{
    noMove = initAnimation("noMove");
    loadTexture(noMove, render, "resources/source/greenCube.png", "resources/source/greenCube.png");
    cutFrame(noMove, 1, 1, 1);
    setMovement(noMove, 1, 0.0);
}

/*void        loadAllenWalkerRed(SDL_Renderer *render, CS_Animation* &AllenWalker)
{
    AllenWalker = initAnimation("AllenWalker");
    loadTexture(AllenWalker, render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    cutFrame(AllenWalker, 5, 5, 1);
    setMovement(AllenWalker, 5, 1.0, 1.0, 1.0, 1.0, 1.0);
}*/

void        CS_Cube::loadBank(SDL_Renderer *render)
{
    setSize(size, 10, 10 * gameSettings.resolution, 45, 90 - (5 * gameSettings.resolution));
    bank->loadNoMove(render, loadNoMoveCubeGreen);
    /*bank->loadAllenWalker(render, loadAllenWalkerPlayer);*/
}
