#include "game.h"

CS_Scene    *init_menuVideo(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Resolution", 38, 8, 31, 11, 5, &closeGame);
    scene->writeTexte(-1, "Resolution : 1920x1080");

    scene->createButtonToScene("Window", 38, 8, 31, 24, 5, &closeGame);
    scene->writeTexte(-1, "Window Mode : Windowed");

    scene->createButtonToScene("Vertical", 38, 8, 31, 37, 5, &closeGame);
    scene->writeTexte(-1, "Vertical Sync : Disabled");

    scene->createButtonToScene("Frame", 36, 8, 32, 50, 5, &closeGame);
    scene->writeTexte(-1, "Frame Rate : No Limit");

    scene->createButtonToScene("Brightness", 28, 8, 36, 63, 5, &closeGame);
    scene->writeTexte(-1, "Brightness : 50");

    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToMenu);
    scene->writeTexte(-1, "Back");

    return (scene);
}