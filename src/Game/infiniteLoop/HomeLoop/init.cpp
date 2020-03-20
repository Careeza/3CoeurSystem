#include "game.h"

CS_Scene    *initHome(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 255);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->createElementToSceneFromPng("Background", "resources/source/HomeJeu.png", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Play", 12, 6, 2, 74, 5, &goToLevelSelect);
    scene->writeTexte(-1, "Play");

    scene->createButtonToScene("Credits", 12, 6, 2, 82, 5, &goToMenu);
    scene->writeTexte(-1, "Credits");

    scene->createButtonToScene("Exit game", 12, 6, 2, 90, 5, &closeGame);
    scene->writeTexte(-1, "Exit game");
    
    return (scene);
}
