#include "common.h"

CS_Scene    *initDialogue(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createElementToScene("filtre", 100, 100, 0, 0, 40);

    scene->createElementToScene("dialogue", 50, 50, 25, 25, 41);
    scene->addBorder(-1);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 0x00);
    scene->createElementToScene("Question", 50, 10, 25, 35, 42);
    scene->writeTexte(-1, "Are you sure ?");

    scene->createButtonToScene("YES", 20, 10, 28.3, 55, 42, &returnTrue);
    scene->addBorder(-1);
    scene->writeTexte(-1, "Yes");

    scene->createButtonToScene("NO", 20, 10, 51.6, 55, 42, &returnFalse);
    scene->addBorder(-1);
    scene->writeTexte(-1, "No");
    
    return (scene);
}