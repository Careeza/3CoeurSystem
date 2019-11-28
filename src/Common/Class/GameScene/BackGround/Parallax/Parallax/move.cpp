#include "gameScene.h"

void        CS_Parallax::moveLayer(int index, int x)
{
    layers[index]->moveLayer(x);
}