#include "gameScene.h"

void        CS_Parallax::createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndex)
{
    CS_Layer        *layer;
    unsigned long   i;

    layer = new (CS_Layer);
    layer->createLayer(render, source, speedSource, zIndex);

    i = 0;
    while (i < layers.size() && zIndex >= layers[i]->QueryZindex())
        i++;
    layers.emplace(layers.begin() + i, layer);
}