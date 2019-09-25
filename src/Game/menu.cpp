#include "class.h"
#include "game.h"

CS_Scene    *init_scene(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_setBorderColor(0, 0x64, 0x00, 0xFF);
    scene->CS_createElementToScene(90, 90, 5, 5, 4);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(53, 84, 40, 8, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_createButtonToScene(30, 12, 7.5, 8, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_createButtonToScene(30, 12, 7.5, 26, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_writeTexte(-1, "Settings");
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(30, 12, 7.5, 44, 5, &Function1);
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0, 0, 0, 255);
    scene->CS_writeTexte(-1, "Resume");
    scene->CS_addBorder(-1);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0xFF);
    scene->CS_createButtonToScene(30, 12, 7.5, 62, 5, &Function1);
    scene->CS_addBorder(-1);
    scene->CS_createButtonToScene(30, 12, 7.5, 80, 5, &Function1);
    scene->CS_addBorder(-1);

    return (scene);
}

CS_Scene    *init_scene1(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 0xFF);
    scene->CS_createElementToScene(100, 100, 0, 0, 0);

    scene->CS_setSceneColor(0xA9, 0xA9, 0xA9, 0);
    scene->CS_setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->CS_createButtonToScene(30, 12, 35, 10, 5, &Function1);
    scene->CS_writeTexte(-1, "RESUME");

    scene->CS_createButtonToScene(30, 12, 35, 27, 5, &Function1);
    scene->CS_writeTexte(-1, "HOTKEYS");

    scene->CS_createButtonToScene(30, 12, 35, 44, 5, &Function1);
    scene->CS_writeTexte(-1, "VIDEO");

    scene->CS_createButtonToScene(30, 12, 35, 61, 5, &Function1);
    scene->CS_writeTexte(-1, "SOUND");

    scene->CS_createButtonToScene(30, 12, 35, 78, 5, &Function1);
    scene->CS_writeTexte(-1, "EXIT GAME");

    
    return (scene);
}

CS_Scene    *init_scene2(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->CS_loadRenderer(render);

    scene->CS_setSceneColor(0x00, 0x00, 0x00, 0xFF);
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

    return (scene);
}