#include "game.h"

CS_Scene    *initHome(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Play", 12, 6, 0, 52, 5, &closeGame);
    scene->writeTexte(-1, "Play");

    scene->createButtonToScene("Hotkeys", 12, 6, 0, 60, 5, &closeGame);
    scene->writeTexte(-1, "Hotkeys");

    scene->createButtonToScene("Exit game", 12, 6, 0, 68, 5, &closeGame);
    scene->writeTexte(-1, "Exit game");
    
    return (scene);
}