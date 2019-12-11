#include "game.h"

CS_Scene    *init_play(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setBorderColor(0x00, 0x00, 0x00, 180);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 255);
    scene->setSceneColor(0x00, 0x00, 0x00, 127);
    scene->setBrightnessColor(0x00, 0x00, 0x00, 80);

    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);


    scene->createButtonToSceneFromPng("Continue", "resources/source/FondJeu2.png", 25, 30, 37.5, 35, 5, &levelSelectToGame);
    scene->writeTexteScaleW(-1, "Continue");
    scene->addBorder(-1);


    scene->createButtonToSceneFromPng("New", "resources/source/NewGame.png", 25, 30, 7.5, 35, 5, &levelSelectToGame);
    scene->writeTexteScaleW(-1, "New Game");
    scene->addBorder(-1);


    scene->createButtonToSceneFromPng("Load", "resources/source/FondJeu2.png", 25, 30, 67.5, 35, 5, &levelSelectToGame);
    scene->writeTexteScaleW(-1, "Load Game");
    scene->addBorder(-1);

    scene->setSceneColor(0x00, 0x00, 0x00, 0x00);
    scene->setBrightnessColor(0xFF, 0xFF, 0xFF, 80);
    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->writeTexte(-1, "Back");

    return (scene);
}