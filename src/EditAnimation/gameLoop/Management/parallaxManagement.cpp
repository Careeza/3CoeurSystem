#include "editAnimation.h"

void    parallaxManagement(CS_Parallax *parallax, CS_Camera *camera)
{

    CS_Layer        *layer;
    int             i;
    int             x;
    int             y;

    i = 0;
    camera->QueryCameraPosition(x, y);
    while (i < parallax->QueryNbLayers())
    {
        layer = parallax->QueryLayer(i);
        layer->moveLayer(x);
        i++;
    }
}
