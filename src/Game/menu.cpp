#include "class.h"
#include "game.h"

CS_Scene    *init_scene(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_createElementToSceneFromPng("resources/source/EcranAccueil.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0xA9, 0);
    scene->CS_setTextColor(0x00, 0x00, 0x00, 0xFF);

    scene->CS_createButtonToScene(30, 12, 35, 10, 5, &Function3);
    scene->CS_writeTexte(-1, "Play");

    scene->CS_createButtonToScene(30, 12, 35, 27, 5, &Function5);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createButtonToScene(30, 12, 35, 44, 5, &Function1);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createButtonToScene(30, 12, 35, 61, 5, &Function1);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createButtonToScene(30, 12, 35, 78, 5, &Function1);
    scene->CS_writeTexte(-1, "Exit game");
    
    return (scene);
}

CS_Scene    *init_scene1(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("resources/source/Deer.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene(100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene(30, 12, 35, 10, 5, &Function1);
    scene->CS_writeTexte(-1, "Continue");

    scene->CS_createButtonToScene(30, 12, 35, 27, 5, &Function2);
    scene->CS_writeTexte(-1, "Hotkeys");

    scene->CS_createButtonToScene(30, 12, 35, 44, 5, &Function1);
    scene->CS_writeTexte(-1, "Video");

    scene->CS_createButtonToScene(30, 12, 35, 61, 5, &Function1);
    scene->CS_writeTexte(-1, "Sound");

    scene->CS_createButtonToScene(30, 12, 35, 78, 5, &Function4);
    scene->CS_writeTexte(-1, "Save & exit");

    
    return (scene);
}

CS_Scene    *init_scene2(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("resources/source/Deer.png", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene(100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene(20, 6, 40, 7, 5, &Function1);
    scene->CS_writeTexte(-1, "UP = Z");

    scene->CS_createButtonToScene(20, 6, 40, 15, 5, &Function1);
    scene->CS_writeTexte(-1, "DOWN = S");

    scene->CS_createButtonToScene(20, 6, 40, 23, 5, &Function1);
    scene->CS_writeTexte(-1, "RIGHT = D");

    scene->CS_createButtonToScene(20, 6, 40, 31, 5, &Function1);
    scene->CS_writeTexte(-1, "LEFT = Q");
    
    scene->CS_createButtonToScene(30, 6, 35, 39, 5, &Function1);
    scene->CS_writeTexte(-1, "JUMP = SPACE");

    scene->CS_createButtonToScene(30, 6, 35, 47, 5, &Function1);
    scene->CS_writeTexte(-1, "DODGE = SPACE");
    
    scene->CS_createButtonToScene(20, 6, 40, 55, 5, &Function1);
    scene->CS_writeTexte(-1, "ATT = M1");

    scene->CS_createButtonToScene(20, 6, 40, 63, 5, &Function1);
    scene->CS_writeTexte(-1, "ATT SP = M2");

    scene->CS_createButtonToScene(20, 6, 40, 71, 5, &Function1);
    scene->CS_writeTexte(-1, "USE = F");

    scene->CS_createButtonToScene(20, 6, 40, 79, 5, &Function1);
    scene->CS_writeTexte(-1, "SPELL 1 = A");

    scene->CS_createButtonToScene(20, 6, 40, 86, 5, &Function1);
    scene->CS_writeTexte(-1, "SPELL 2 = E");

    scene->CS_createButtonToScene(20, 10, 77, 85, 5, &Function3);
    scene->CS_writeTexte(-1, "EXIT");

    return (scene);
}

CS_Scene    *init_scene3(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("resources/source/EcranAccueil.jpg", 100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 175);
    scene->CS_createElementToScene(100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene(20, 6, 40, 7, 5, &Function1);
    scene->CS_writeTexte(-1, "UP = Z");

    scene->CS_createButtonToScene(20, 6, 40, 15, 5, &Function1);
    scene->CS_writeTexte(-1, "DOWN = S");

    scene->CS_createButtonToScene(20, 6, 40, 23, 5, &Function1);
    scene->CS_writeTexte(-1, "RIGHT = D");

    scene->CS_createButtonToScene(20, 6, 40, 31, 5, &Function1);
    scene->CS_writeTexte(-1, "LEFT = Q");
    
    scene->CS_createButtonToScene(30, 6, 35, 39, 5, &Function1);
    scene->CS_writeTexte(-1, "JUMP = SPACE");

    scene->CS_createButtonToScene(30, 6, 35, 47, 5, &Function1);
    scene->CS_writeTexte(-1, "DODGE = SPACE");
    
    scene->CS_createButtonToScene(20, 6, 40, 55, 5, &Function1);
    scene->CS_writeTexte(-1, "ATT = M1");

    scene->CS_createButtonToScene(20, 6, 40, 63, 5, &Function1);
    scene->CS_writeTexte(-1, "ATT SP = M2");

    scene->CS_createButtonToScene(20, 6, 40, 71, 5, &Function1);
    scene->CS_writeTexte(-1, "USE = F");

    scene->CS_createButtonToScene(20, 6, 40, 79, 5, &Function1);
    scene->CS_writeTexte(-1, "SPELL 1 = A");

    scene->CS_createButtonToScene(20, 6, 40, 86, 5, &Function1);
    scene->CS_writeTexte(-1, "SPELL 2 = E");

    scene->CS_createButtonToScene(20, 10, 77, 85, 5, &Function4);
    scene->CS_writeTexte(-1, "EXIT");

    return (scene);
}

CS_Scene    *init_scene4(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_createElementToSceneFromPng("resources/source/Deer.png", 100, 100, 0, 0, 0);

    return (scene);
}

CS_Scene    *init_scene5(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_createElementToSceneFromPng("resources/source/EcranAccueil.jpg", 100, 100, 0, 0, 0);

    scene->CS_setBorderColor(0x00, 0x00, 0x00, 180);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 180);
    scene->CS_setSceneColor(0x00, 0x00, 0x00, 127);
    scene->CS_setBrightnessColor(0x00, 0x127, 0x00, 80);

    scene->CS_createElementToScene(100, 100, 0, 0, 0);


    scene->CS_createButtonToSceneFromPng("resources/source/Deer.png", 25, 30, 37.5, 35, 5, &Function1);
    scene->CS_writeTexteScaleW(-1, "Continue");
    scene->CS_addBorder(-1);


    scene->CS_createButtonToSceneFromPng("resources/source/NewGame.png", 25, 30, 7.5, 35, 5, &Function3);
    scene->CS_writeTexteScaleW(-1, "New Game");
    scene->CS_addBorder(-1);


    scene->CS_createButtonToSceneFromPng("resources/source/Deer.png", 25, 30, 67.5, 35, 5, &Function3);
    scene->CS_writeTexteScaleW(-1, "Load Game");
    scene->CS_addBorder(-1);


    return (scene);
}