# include "gameScene.h"

CS_Camera       *initCamera()
{
    CS_Camera *camera;

    camera = new (CS_Camera);
    return (camera);
}