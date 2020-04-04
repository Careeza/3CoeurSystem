#include "editAnimation.h"

CS_GameScene    *initGameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->loadRenderer(render);

    scene->loadMC(initMC(render));
    scene->loadCamera(initCamera());

    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);
//    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);
    scene->setSceneColor(0x00, 0x00, 0xFF, 0xFF);
    scene->createElementToScene("backGround", 75, 100, 0, 0, 0);
    scene->setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->createElementToScene("backGround2", 25, 100, 75, 0, 0);
    scene->addBorder(-1);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->createButtonToScene("Asset1", 12.5, 10, 75, 0, 1, &useButton0);
    scene->writeTexte(-1, ">");
    scene->createButtonToScene("Asset2", 12.5, 10, 87.5, 0, 1, &useButton1);
    scene->writeTexte(-1, "<");
    scene->createButtonToScene("Asset3", 12.5, 10, 75, 10, 1, &useButton2);
    scene->writeTexte(-1, "Go");
    scene->createButtonToScene("Asset4", 12.5, 10, 87.5, 10, 1, &useButton3);
    scene->writeTexte(-1, "||");
    scene->createButtonToScene("Asset5", 12.5, 10, 75, 20, 1, &useButton4);
    scene->writeTexte(-1, "+");
    scene->createButtonToScene("Asset6", 12.5, 10, 87.5, 20, 1, &useButton5);
    scene->writeTexte(-1, "-");
    scene->createButtonToScene("Asset7", 12.5, 10, 75, 30, 1, &useButton6);
    scene->writeTexte(-1, "++");
    scene->createButtonToScene("Asset8", 12.5, 10, 87.5, 30, 1, &useButton7);
    scene->writeTexte(-1, "--");
    scene->createButtonToScene("Asset9", 12.5, 10, 75, 40, 1, &useButton8);
    scene->writeTexte(-1, "w+");
    scene->createButtonToScene("Asset10", 12.5, 10, 87.5, 40, 1, &useButton9);
    scene->writeTexte(-1, "w-");
    scene->createButtonToScene("Asset11", 12.5, 10, 75, 50, 1, &useButton10);
    scene->writeTexte(-1, "h+");
    scene->createButtonToScene("Asset12", 12.5, 10, 87.5, 50, 1, &useButton11);
    scene->writeTexte(-1, "h-");
    scene->createButtonToScene("Asset13", 12.5, 10, 75, 60, 1, &useButton12);
    scene->writeTexte(-1, "x+");
    scene->createButtonToScene("Asset14", 12.5, 10, 87.5, 60, 1, &useButton13);
    scene->writeTexte(-1, "x-");
    scene->createButtonToScene("Asset15", 12.5, 10, 75, 70, 1, &useButton14);
    scene->writeTexte(-1, "y+");
    scene->createButtonToScene("Asset16", 12.5, 10, 87.5, 70, 1, &useButton15);
    scene->writeTexte(-1, "y-");
    scene->createButtonToScene("Asset17", 12.5, 10, 75, 80, 1, &useButton16);
    scene->writeTexte(-1, "pas+");
    scene->createButtonToScene("Asset18", 12.5, 10, 87.5, 80, 1, &useButton17);
    scene->writeTexte(-1, "pas-");
    scene->createButtonToSceneFromPng("Asset19", "resources/source/old/greenCube.png",  12.5, 10, 75, 90, 1, &useButton18);
    scene->createButtonToSceneFromPng("Asset20", "resources/source/old/greenCube.png",  12.5, 10, 87.5, 90, 1, &closeGame);

    scene->setTextColor(0x00, 0x00, 0x00, 0xFF);
    scene->setSceneColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->createElementToScene("fps", 10, 10, 0, 0, 0);
    scene->writeTexte(-1, "542");
    scene->createElementToScene("pas", 10, 10, 10, 0, 0);
    scene->writeTexte(-1, "1");
    scene->createElementToScene("index", 20, 10, 0, 10, 0);
    scene->writeTexte(-1, "1 / 1");

    scene->createElementToScene("w", 18.75, 10, 0, 90, 0);
    scene->writeTexte(-1, "w=10000");
    scene->createElementToScene("h", 18.75, 10, 18.75, 90, 0);
    scene->writeTexte(-1, "h = 1");
    scene->createElementToScene("x", 18.75, 10, 37.5, 90, 0);
    scene->writeTexte(-1, "x = 1");
    scene->createElementToScene("y", 18.75, 10, 56.25, 90, 0);
    scene->writeTexte(-1, "y = 1");

    return (scene);
}
