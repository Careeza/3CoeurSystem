#include "gameScene.h"

CS_Layer    *CS_Parallax::QueryLayer(int index)
{
    return (layers[index]);
}

int         CS_Parallax::QueryNbLayers()
{
    return (layers.size());
}
