#include "game.h"

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