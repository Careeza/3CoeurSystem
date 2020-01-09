#include "game.h"

CS_Scene    *initMenu(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Continue", 30, 12, 35, 27, 5, &returnFalse);
    scene->writeTexte(-1, "Continue");

    scene->createButtonToScene("Credits", 30, 12, 35, 44, 5, &returnTrue);
    scene->writeTexte(-1, "Credits");

    scene->createButtonToScene("Save", 30, 12, 35, 61, 5, &returnTrue);
    scene->writeTexte(-1, "Save & exit");
    
    return (scene);
}