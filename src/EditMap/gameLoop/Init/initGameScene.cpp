#include "editMap.h"

CS_GameScene    *initGameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->loadRenderer(render);

    scene->loadCamera(initCamera());

    scene->setBorderColor(0xFF, 0xFF, 0xFF, 0xFF);
    scene->setSceneColor(0x0, 0x0, 0x0, 0xFF);
    scene->createElementToScene("backGround2", 25, 100, 75, 0, 0);
    scene->addBorder(-1);

    scene->createButtonToSceneFromPng("Asset1", "resources/source/assets/BigTree01.png", 12.5, 10, 75, 0, 1, &useButton0);
    scene->createButtonToSceneFromPng("Asset2", "resources/source/assets/BigTree02.png", 12.5, 10, 87.5, 0, 1, &useButton1);
    scene->createButtonToSceneFromPng("Asset3", "resources/source/assets/BigTree03.png", 12.5, 10, 75, 10, 1, &useButton2);
    scene->createButtonToSceneFromPng("Asset4", "resources/source/assets/BushTree01.png", 12.5, 10, 87.5, 10, 1, &useButton3);
    scene->createButtonToSceneFromPng("Asset5", "resources/source/assets/BushTree02.png", 12.5, 10, 75, 20, 1, &useButton4);
    scene->createButtonToSceneFromPng("Asset6", "resources/source/assets/BushTree03.png", 12.5, 10, 87.5, 20, 1, &useButton5);
    scene->createButtonToSceneFromPng("Asset7", "resources/source/assets/BushTree04.png", 12.5, 10, 75, 30, 1, &useButton6);
    scene->createButtonToSceneFromPng("Asset8", "resources/source/assets/Grass01.png", 12.5, 10, 87.5, 30, 1, &useButton7);
    scene->createButtonToSceneFromPng("Asset9", "resources/source/assets/Grass02.png", 12.5, 10, 75, 40, 1, &useButton8);
    scene->createButtonToSceneFromPng("Asset10", "resources/source/assets/Grass03.png",  12.5, 10, 87.5, 40, 1, &useButton9);
    scene->createButtonToSceneFromPng("Asset11", "resources/source/assets/Grass04.png",  12.5, 10, 75, 50, 1, &useButton10);
    scene->createButtonToSceneFromPng("Asset12", "resources/source/assets/Grass05.png",  12.5, 10, 87.5, 50, 1, &useButton11);
    scene->createButtonToSceneFromPng("Asset13", "resources/source/assets/Ground01.png",  12.5, 10, 75, 60, 1, &useButton12);
    scene->createButtonToSceneFromPng("Asset14", "resources/source/assets/plateforme.png",  12.5, 10, 87.5, 60, 1, &useButton13);
    scene->createButtonToSceneFromPng("Asset15", "resources/source/assets/MediumTree02.png",  12.5, 10, 75, 70, 1, &useButton14);
    scene->createButtonToSceneFromPng("Asset16", "resources/source/assets/MediumTree03.png",  12.5, 10, 87.5, 70, 1, &useButton15);
    scene->createButtonToSceneFromPng("Asset17", "resources/source/assets/SmallTree01.png",  12.5, 10, 75, 80, 1, &useButton16);
    scene->createButtonToSceneFromPng("Asset18", "resources/source/assets/SmallTree02.png",  12.5, 10, 87.5, 80, 1, &useButton17);
    scene->createButtonToSceneFromPng("Asset19", "resources/source/assets/SmallTree03.png",  12.5, 10, 75, 90, 1, &useButton18);
    scene->createButtonToSceneFromPng("Asset20", "resources/source/assets/SmallTree04.png",  12.5, 10, 87.5, 90, 1, &useButton19);

    scene->loadParallax(initParallax(render));
    scene->loadAssets(initAssets(render));

    return (scene);
}