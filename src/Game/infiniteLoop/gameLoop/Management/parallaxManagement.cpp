#include "game.h"

void    parallaxManagement(CS_Parallax *parallax, int xCamera, int yCamera)
{

    CS_Layer        *layer;
    int             i;

    (void)yCamera;
    i = 0;
    while (i < parallax->QueryNbLayers())
    {
        layer = parallax->QueryLayer(i);
        layer->moveLayer(xCamera);
        i++;
    }
}