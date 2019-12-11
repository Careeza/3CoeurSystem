#include "game.h"

CS_Scene    *init_home(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);

    std::cout << "play = ";
    scene->createButtonToScene("Play", 12, 6, 0, 52, 5, &homeToLevelSelect);
    scene->writeTexte(-1, "Play");

    scene->createButtonToScene("Hotkeys", 12, 6, 0, 60, 5, &homeToHotkeys);
    scene->writeTexte(-1, "Hotkeys");

    scene->createButtonToScene("Video", 12, 6, 0, 68, 5, &homeToVideo);
    scene->writeTexte(-1, "Video");

    scene->createButtonToScene("Sound", 12, 6, 0, 76, 5, &homeToSound);
    scene->writeTexte(-1, "Sound");

    scene->createButtonToScene("Exit game", 12, 6, 0, 84, 5, &dispDialogueBox);
    scene->writeTexte(-1, "Exit game");

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 40);

    scene->createElementToScene("dialogue", 50, 50, 25, 25, 41);
    scene->addBorder(-1);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 0x00);
    scene->createElementToScene("Question", 50, 10, 25, 35, 42);
    scene->writeTexte(-1, "Are you sure ?");

    scene->createButtonToScene("YES", 20, 10, 28.3, 55, 42, &closeGame);
    scene->addBorder(-1);
    scene->writeTexte(-1, "Yes");

    scene->createButtonToScene("NO", 20, 10, 51.6, 55, 42, &hideDialogueBox);
    scene->addBorder(-1);
    scene->writeTexte(-1, "No");

    scene->setDisp(false, scene->QueryIndexByName("filtre"));
    scene->setDisp(false, scene->QueryIndexByName("dialogue"));
    scene->setDisp(false, scene->QueryIndexByName("Question"));
    scene->setDisp(false, scene->QueryIndexByName("YES"));
    scene->setDisp(false, scene->QueryIndexByName("NO"));
    
    return (scene);
}