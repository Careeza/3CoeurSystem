#include "game.h"

CS_Scene    *init_menu(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Continue", 30, 12, 35, 10, 5, &levelSelectToGame);
    scene->writeTexte(-1, "Continue");

    scene->createButtonToScene("Hotkeys", 30, 12, 35, 27, 5, &menuToHotkeys);
    scene->writeTexte(-1, "Hotkeys");

    scene->createButtonToScene("Video", 30, 12, 35, 44, 5, &menuTovideo);
    scene->writeTexte(-1, "Video");

    scene->createButtonToScene("Sound", 30, 12, 35, 61, 5, &menuToSound);
    scene->writeTexte(-1, "Sound");

    scene->createButtonToScene("Save", 30, 12, 35, 78, 5, &goToHome);
    scene->writeTexte(-1, "Save & exit");

    
    return (scene);
}