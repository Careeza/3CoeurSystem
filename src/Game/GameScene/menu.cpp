#include "common.h"
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

CS_Scene    *init_menuHotkeys(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("UP", 20, 6, 40, 7, 5, &closeGame);
    scene->writeTexte(-1, "UP : Z");

    scene->createButtonToScene("Down", 20, 6, 40, 15, 5, &closeGame);
    scene->writeTexte(-1, "DOWN : S");

    scene->createButtonToScene("Right", 20, 6, 40, 23, 5, &closeGame);
    scene->writeTexte(-1, "RIGHT : D");

    scene->createButtonToScene("Left", 20, 6, 40, 31, 5, &closeGame);
    scene->writeTexte(-1, "LEFT : Q");
    
    scene->createButtonToScene("Jump", 30, 6, 35, 39, 5, &closeGame);
    scene->writeTexte(-1, "JUMP : SPACE");

    scene->createButtonToScene("Dodge", 30, 6, 35, 47, 5, &closeGame);
    scene->writeTexte(-1, "DODGE : SHIFT");
    
    scene->createButtonToScene("Att", 20, 6, 40, 55, 5, &closeGame);
    scene->writeTexte(-1, "ATT : M1");

    scene->createButtonToScene("Att sp", 20, 6, 40, 63, 5, &closeGame);
    scene->writeTexte(-1, "ATT SP : M2");

    scene->createButtonToScene("Use", 20, 6, 40, 71, 5, &closeGame);
    scene->writeTexte(-1, "USE : F");

    scene->createButtonToScene("Spell 1", 20, 6, 40, 79, 5, &closeGame);
    scene->writeTexte(-1, "SPELL 1 : A");

    scene->createButtonToScene("Spell 2", 20, 6, 40, 86, 5, &closeGame);
    scene->writeTexte(-1, "SPELL 2 : E");

    scene->createButtonToScene("Exit", 20, 10, 77, 85, 5, &goToMenu);
    scene->writeTexte(-1, "EXIT");

    return (scene);
}

CS_Scene    *init_homeHotkeys(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->writeTexte(-1, "Play");

    scene->createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->writeTexte(-1, "Hotkeys");

    scene->createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->writeTexte(-1, "Video");

    scene->createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->writeTexte(-1, "Sound");

    scene->createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->writeTexte(-1, "Exit game");

    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Up", 20, 6, 40, 7, 5, &closeGame);
    scene->writeTexte(-1, "UP : Z");

    scene->createButtonToScene("Down", 20, 6, 40, 15, 5, &closeGame);
    scene->writeTexte(-1, "DOWN : S");

    scene->createButtonToScene("Right", 20, 6, 40, 23, 5, &closeGame);
    scene->writeTexte(-1, "RIGHT : D");

    scene->createButtonToScene("Left", 20, 6, 40, 31, 5, &closeGame);
    scene->writeTexte(-1, "LEFT : Q");
    
    scene->createButtonToScene("Jump", 30, 6, 35, 39, 5, &closeGame);
    scene->writeTexte(-1, "JUMP : SPACE");

    scene->createButtonToScene("Dodge", 30, 6, 35, 47, 5, &closeGame);
    scene->writeTexte(-1, "DODGE : SHIFT");
    
    scene->createButtonToScene("Att", 20, 6, 40, 55, 5, &closeGame);
    scene->writeTexte(-1, "ATT : M1");

    scene->createButtonToScene("Att sp", 20, 6, 40, 63, 5, &closeGame);
    scene->writeTexte(-1, "ATT SP : M2");

    scene->createButtonToScene("Use", 20, 6, 40, 71, 5, &closeGame);
    scene->writeTexte(-1, "USE : F");

    scene->createButtonToScene("Spell 1", 20, 6, 40, 79, 5, &closeGame);
    scene->writeTexte(-1, "SPELL 1 : A");

    scene->createButtonToScene("Spell 2", 20, 6, 40, 86, 5, &closeGame);
    scene->writeTexte(-1, "SPELL 2 : E");

    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->writeTexte(-1, "Back");

    return (scene);
}

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

CS_Scene    *init_homeVideo(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->writeTexte(-1, "Play");

    scene->createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->writeTexte(-1, "Hotkeys");

    scene->createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->writeTexte(-1, "Video");

    scene->createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->writeTexte(-1, "Sound");

    scene->createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->writeTexte(-1, "Exit game");

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

    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->writeTexte(-1, "Back");

    return (scene);
}

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

CS_Scene    *init_homeSound(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

    scene->createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->writeTexte(-1, "Play");

    scene->createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->writeTexte(-1, "Hotkeys");

    scene->createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->writeTexte(-1, "Video");

    scene->createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->writeTexte(-1, "Sound");

    scene->createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->writeTexte(-1, "Exit game");

    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Master", 30, 8, 35, 11, 5, &closeGame);
    scene->writeTexte(-1, "Master Volume : 100");

    scene->createButtonToScene("Music", 30, 8, 35, 24, 5, &closeGame);
    scene->writeTexte(-1, "Music Volume : 50");

    scene->createButtonToScene("Sound", 38, 8, 31, 37, 5, &closeGame);
    scene->writeTexte(-1, "Sound Effect Volume : 75");

    scene->createButtonToScene("Ambient", 40, 8, 30, 50, 5, &closeGame);
    scene->writeTexte(-1, "Ambient Sound Volume : 75");

    scene->createButtonToScene("Disable", 30, 8, 35, 63, 5, &closeGame);
    scene->writeTexte(-1, "Disable Sound : No");

    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_menuSound(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->setSceneColor(0x00, 0x00, 0x00, 175);
    scene->createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createButtonToScene("Master", 30, 8, 35, 11, 5, &closeGame);
    scene->writeTexte(-1, "Master Volume : 100");

    scene->createButtonToScene("Music", 30, 8, 35, 24, 5, &closeGame);
    scene->writeTexte(-1, "Music Volume : 50");

    scene->createButtonToScene("Sound", 38, 8, 31, 37, 5, &closeGame);
    scene->writeTexte(-1, "Sound Effect Volume : 75");

    scene->createButtonToScene("Ambient", 40, 8, 30, 50, 5, &closeGame);
    scene->writeTexte(-1, "Ambient Sound Volume : 75");

    scene->createButtonToScene("Disable", 30, 8, 35, 63, 5, &closeGame);
    scene->writeTexte(-1, "Disable Sound : No");

    scene->createButtonToScene("Back", 20, 10, 77, 85, 5, &goToMenu);
    scene->writeTexte(-1, "Back");

    return (scene);
}