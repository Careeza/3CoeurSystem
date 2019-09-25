#include "class.h"
#include "game.h"

CS_Scene    *init_scene(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    scene->CS_initBrillance();
    
    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_setBorderColor(0, 0x64, 0x00, 0xFF);
    scene->CS_createElementToScene(90, 90, 5, 5, 4);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(53, 84, 40, 8, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_createButtonToScene(30, 12, 7.5, 8, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_createButtonToScene(30, 12, 7.5, 26, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_writeTexte(-1, "Settings");
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(30, 12, 7.5, 44, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_writeTexte(-1, "Resume");
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(30, 12, 7.5, 62, 5, &Function1);
    scene->CS_addBorder(-1);
    scene->CS_createButtonToScene(30, 12, 7.5, 80, 5, &Function1);
    scene->CS_addBorder(-1);

    return (scene);
}