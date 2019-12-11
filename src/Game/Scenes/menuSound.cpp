#include "game.h"

CS_Scene    *init_menuSound(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);

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