#include "class.h"
#include "game.h"

CS_Scene    *init_scene(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    scene->CS_initBrillance();
    scene->CS_setSceneColor(0, 0, 255, 255);
    scene->CS_createButtonToScene(40, 70, 30, 30, 4, &Function1);

    return (scene);
}