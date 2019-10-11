#include "class.h"
#include "game.h"

CS_Scene    *init_home(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->CS_setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Play", 12, 6, 0, 52, 5, &homeToLevelSelect);
    scene->CS_writeTexte(-1, "Play");

    scene->CS_createButtonToScene("Hotkeys", 12, 6, 0, 60, 5, &homeToHotkeys);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createButtonToScene("Video", 12, 6, 0, 68, 5, &homeToVideo);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createButtonToScene("Sound", 12, 6, 0, 76, 5, &homeToSound);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createButtonToScene("Exit game", 12, 6, 0, 84, 5, &dispDialogueBox);
    scene->CS_writeTexte(-1, "Exit game");

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("filtre", 100, 100, 0, 0, 40);

    scene->CS_createElementToScene("dialogue", 50, 50, 25, 25, 41);
    scene->CS_addBorder(-1);
    
    scene->CS_setSceneColor(0x00, 0x00, 0x00, 0x00);
    scene->CS_createElementToScene("Question", 50, 10, 25, 35, 42);
    scene->CS_writeTexte(-1, "Are you sure ?");

    scene->CS_createButtonToScene("YES", 20, 10, 28.3, 55, 42, &closeGame);
    scene->CS_addBorder(-1);
    scene->CS_writeTexte(-1, "Yes");

    scene->CS_createButtonToScene("NO", 20, 10, 51.6, 55, 42, &hideDialogueBox);
    scene->CS_addBorder(-1);
    scene->CS_writeTexte(-1, "No");

    scene->CS_setDisp(false, scene->CS_queryIndexByName("filtre"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("dialogue"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("Question"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("YES"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("NO"));
    
    return (scene);
}

CS_Scene    *init_menu(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Continue", 30, 12, 35, 10, 5, &levelSelectToGame);
    scene->CS_writeTexte(-1, "Continue");

    scene->CS_createButtonToScene("Hotkeys", 30, 12, 35, 27, 5, &menuToHotkeys);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createButtonToScene("Video", 30, 12, 35, 44, 5, &menuTovideo);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createButtonToScene("Sound", 30, 12, 35, 61, 5, &menuToSound);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createButtonToScene("Save", 30, 12, 35, 78, 5, &goToHome);
    scene->CS_writeTexte(-1, "Save & exit");

    
    return (scene);
}

CS_Scene    *init_menuHotkeys(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("UP", 20, 6, 40, 7, 5, &closeGame);
    scene->CS_writeTexte(-1, "UP : Z");

    scene->CS_createButtonToScene("Down", 20, 6, 40, 15, 5, &closeGame);
    scene->CS_writeTexte(-1, "DOWN : S");

    scene->CS_createButtonToScene("Right", 20, 6, 40, 23, 5, &closeGame);
    scene->CS_writeTexte(-1, "RIGHT : D");

    scene->CS_createButtonToScene("Left", 20, 6, 40, 31, 5, &closeGame);
    scene->CS_writeTexte(-1, "LEFT : Q");
    
    scene->CS_createButtonToScene("Jump", 30, 6, 35, 39, 5, &closeGame);
    scene->CS_writeTexte(-1, "JUMP : SPACE");

    scene->CS_createButtonToScene("Dodge", 30, 6, 35, 47, 5, &closeGame);
    scene->CS_writeTexte(-1, "DODGE : SHIFT");
    
    scene->CS_createButtonToScene("Att", 20, 6, 40, 55, 5, &closeGame);
    scene->CS_writeTexte(-1, "ATT : M1");

    scene->CS_createButtonToScene("Att sp", 20, 6, 40, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "ATT SP : M2");

    scene->CS_createButtonToScene("Use", 20, 6, 40, 71, 5, &closeGame);
    scene->CS_writeTexte(-1, "USE : F");

    scene->CS_createButtonToScene("Spell 1", 20, 6, 40, 79, 5, &closeGame);
    scene->CS_writeTexte(-1, "SPELL 1 : A");

    scene->CS_createButtonToScene("Spell 2", 20, 6, 40, 86, 5, &closeGame);
    scene->CS_writeTexte(-1, "SPELL 2 : E");

    scene->CS_createButtonToScene("Exit", 20, 10, 77, 85, 5, &goToMenu);
    scene->CS_writeTexte(-1, "EXIT");

    return (scene);
}

CS_Scene    *init_homeHotkeys(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->CS_createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->CS_writeTexte(-1, "Play");

    scene->CS_createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->CS_writeTexte(-1, "Exit game");

    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Up", 20, 6, 40, 7, 5, &closeGame);
    scene->CS_writeTexte(-1, "UP : Z");

    scene->CS_createButtonToScene("Down", 20, 6, 40, 15, 5, &closeGame);
    scene->CS_writeTexte(-1, "DOWN : S");

    scene->CS_createButtonToScene("Right", 20, 6, 40, 23, 5, &closeGame);
    scene->CS_writeTexte(-1, "RIGHT : D");

    scene->CS_createButtonToScene("Left", 20, 6, 40, 31, 5, &closeGame);
    scene->CS_writeTexte(-1, "LEFT : Q");
    
    scene->CS_createButtonToScene("Jump", 30, 6, 35, 39, 5, &closeGame);
    scene->CS_writeTexte(-1, "JUMP : SPACE");

    scene->CS_createButtonToScene("Dodge", 30, 6, 35, 47, 5, &closeGame);
    scene->CS_writeTexte(-1, "DODGE : SHIFT");
    
    scene->CS_createButtonToScene("Att", 20, 6, 40, 55, 5, &closeGame);
    scene->CS_writeTexte(-1, "ATT : M1");

    scene->CS_createButtonToScene("Att sp", 20, 6, 40, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "ATT SP : M2");

    scene->CS_createButtonToScene("Use", 20, 6, 40, 71, 5, &closeGame);
    scene->CS_writeTexte(-1, "USE : F");

    scene->CS_createButtonToScene("Spell 1", 20, 6, 40, 79, 5, &closeGame);
    scene->CS_writeTexte(-1, "SPELL 1 : A");

    scene->CS_createButtonToScene("Spell 2", 20, 6, 40, 86, 5, &closeGame);
    scene->CS_writeTexte(-1, "SPELL 2 : E");

    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_play(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->CS_setBorderColor(0x00, 0x00, 0x00, 180);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 255);
    scene->CS_setSceneColor(0x00, 0x00, 0x00, 127);
    scene->CS_setBrightnessColor(0x00, 0x00, 0x00, 80);

    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);


    scene->CS_createButtonToSceneFromPng("Continue", "resources/source/FondJeu2.png", 25, 30, 37.5, 35, 5, &levelSelectToGame);
    scene->CS_writeTexteScaleW(-1, "Continue");
    scene->CS_addBorder(-1);


    scene->CS_createButtonToSceneFromPng("New", "resources/source/NewGame.png", 25, 30, 7.5, 35, 5, &levelSelectToGame);
    scene->CS_writeTexteScaleW(-1, "New Game");
    scene->CS_addBorder(-1);


    scene->CS_createButtonToSceneFromPng("Load", "resources/source/FondJeu2.png", 25, 30, 67.5, 35, 5, &levelSelectToGame);
    scene->CS_writeTexteScaleW(-1, "Load Game");
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 0x00);
    scene->CS_setBrightnessColor(0xFF, 0xFF, 0xFF, 80);
    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_homeVideo(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->CS_createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->CS_writeTexte(-1, "Play");

    scene->CS_createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->CS_writeTexte(-1, "Exit game");

    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Resolution", 38, 8, 31, 11, 5, &closeGame);
    scene->CS_writeTexte(-1, "Resolution : 1920x1080");

    scene->CS_createButtonToScene("Window", 38, 8, 31, 24, 5, &closeGame);
    scene->CS_writeTexte(-1, "Window Mode : Windowed");

    scene->CS_createButtonToScene("Vertical", 38, 8, 31, 37, 5, &closeGame);
    scene->CS_writeTexte(-1, "Vertical Sync : Disabled");

    scene->CS_createButtonToScene("Frame", 36, 8, 32, 50, 5, &closeGame);
    scene->CS_writeTexte(-1, "Frame Rate : No Limit");

    scene->CS_createButtonToScene("Brightness", 28, 8, 36, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "Brightness : 50");

    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_menuVideo(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Resolution", 38, 8, 31, 11, 5, &closeGame);
    scene->CS_writeTexte(-1, "Resolution : 1920x1080");

    scene->CS_createButtonToScene("Window", 38, 8, 31, 24, 5, &closeGame);
    scene->CS_writeTexte(-1, "Window Mode : Windowed");

    scene->CS_createButtonToScene("Vertical", 38, 8, 31, 37, 5, &closeGame);
    scene->CS_writeTexte(-1, "Vertical Sync : Disabled");

    scene->CS_createButtonToScene("Frame", 36, 8, 32, 50, 5, &closeGame);
    scene->CS_writeTexte(-1, "Frame Rate : No Limit");

    scene->CS_createButtonToScene("Brightness", 28, 8, 36, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "Brightness : 50");

    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToMenu);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_homeSound(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondHome2.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xA9, 0xA9, 0xA9, 180);

    scene->CS_createElementToScene("Play", 12, 6, 0, 52, 4);
    scene->CS_writeTexte(-1, "Play");

    scene->CS_createElementToScene("Hotkeys", 12, 6, 0, 60, 4);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createElementToScene("Video", 12, 6, 0, 68, 4);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createElementToScene("Sound", 12, 6, 0, 76, 4);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createElementToScene("Exit", 12, 6, 0, 84, 4);
    scene->CS_writeTexte(-1, "Exit game");

    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Master", 30, 8, 35, 11, 5, &closeGame);
    scene->CS_writeTexte(-1, "Master Volume : 100");

    scene->CS_createButtonToScene("Music", 30, 8, 35, 24, 5, &closeGame);
    scene->CS_writeTexte(-1, "Music Volume : 50");

    scene->CS_createButtonToScene("Sound", 38, 8, 31, 37, 5, &closeGame);
    scene->CS_writeTexte(-1, "Sound Effect Volume : 75");

    scene->CS_createButtonToScene("Ambient", 40, 8, 30, 50, 5, &closeGame);
    scene->CS_writeTexte(-1, "Ambient Sound Volume : 75");

    scene->CS_createButtonToScene("Disable", 30, 8, 35, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "Disable Sound : No");

    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToHome);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}

CS_Scene    *init_menuSound(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

//    scene->CS_createElementToSceneFromPng("Background", "resources/source/FondJeu2.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene("Filtre", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene("Master", 30, 8, 35, 11, 5, &closeGame);
    scene->CS_writeTexte(-1, "Master Volume : 100");

    scene->CS_createButtonToScene("Music", 30, 8, 35, 24, 5, &closeGame);
    scene->CS_writeTexte(-1, "Music Volume : 50");

    scene->CS_createButtonToScene("Sound", 38, 8, 31, 37, 5, &closeGame);
    scene->CS_writeTexte(-1, "Sound Effect Volume : 75");

    scene->CS_createButtonToScene("Ambient", 40, 8, 30, 50, 5, &closeGame);
    scene->CS_writeTexte(-1, "Ambient Sound Volume : 75");

    scene->CS_createButtonToScene("Disable", 30, 8, 35, 63, 5, &closeGame);
    scene->CS_writeTexte(-1, "Disable Sound : No");

    scene->CS_createButtonToScene("Back", 20, 10, 77, 85, 5, &goToMenu);
    scene->CS_writeTexte(-1, "Back");

    return (scene);
}