#include "editMap.h"

CS_GameScene    *init_home(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);
    scene->CS_loadRenderer(render);
    
    scene->CS_setSceneColor(0x0, 0x0, 0x0, 0xFF);
//    scene->CS_createElementToScene("filtre", 75, 100, 0, 0, 2);

    scene->CS_createElementToScene("backGround", 25, 100, 75, 0, 0);
    scene->CS_createButtonToSceneFromPng("Asset1", "resources/source/assets/BigTree01.png", 12.5, 10, 75, 0, 1, &loadBigTree01);
    scene->CS_createButtonToSceneFromPng("Asset2", "resources/source/assets/BigTree02.png", 12.5, 10, 87.5, 0, 1, &loadBigTree02);
    scene->CS_createButtonToSceneFromPng("Asset3", "resources/source/assets/BigTree03.png", 12.5, 10, 75, 10, 1, &loadBigTree03);
    scene->CS_createButtonToSceneFromPng("Asset4", "resources/source/assets/BushTree01.png", 12.5, 10, 87.5, 10, 1, &loadBushTree01);
    scene->CS_createButtonToSceneFromPng("Asset5", "resources/source/assets/BushTree02.png", 12.5, 10, 75, 20, 1, &loadBushTree02);
    scene->CS_createButtonToSceneFromPng("Asset6", "resources/source/assets/BushTree03.png", 12.5, 10, 87.5, 20, 1, &loadBushTree03);
    scene->CS_createButtonToSceneFromPng("Asset7", "resources/source/assets/BushTree04.png", 12.5, 10, 75, 30, 1, &loadBushTree04);
    scene->CS_createButtonToSceneFromPng("Asset8", "resources/source/assets/Grass01.png", 12.5, 10, 87.5, 30, 1, &loadGrass01);
    scene->CS_createButtonToSceneFromPng("Asset9", "resources/source/assets/Grass02.png", 12.5, 10, 75, 40, 1, &loadGrass02);
    scene->CS_createButtonToSceneFromPng("Asset10", "resources/source/assets/Grass03.png",  12.5, 10, 87.5, 40, 1, &loadGrass03);
    scene->CS_createButtonToSceneFromPng("Asset11", "resources/source/assets/Grass04.png",  12.5, 10, 75, 50, 1, &loadGrass04);
    scene->CS_createButtonToSceneFromPng("Asset12", "resources/source/assets/Grass05.png",  12.5, 10, 87.5, 50, 1, &loadGrass05);
    scene->CS_createButtonToSceneFromPng("Asset13", "resources/source/assets/Ground01.png",  12.5, 10, 75, 60, 1, &loadGround01);
    scene->CS_createButtonToSceneFromPng("Asset14", "resources/source/assets/MediumTree01.png",  12.5, 10, 87.5, 60, 1, &loadMediumTree01);
    scene->CS_createButtonToSceneFromPng("Asset15", "resources/source/assets/MediumTree02.png",  12.5, 10, 75, 70, 1, &loadMediumTree02);
    scene->CS_createButtonToSceneFromPng("Asset16", "resources/source/assets/MediumTree03.png",  12.5, 10, 87.5, 70, 1, &loadMediumTree03);
    scene->CS_createButtonToSceneFromPng("Asset17", "resources/source/assets/SmallTree01.png",  12.5, 10, 75, 80, 1, &loadSmallTree01);
    scene->CS_createButtonToSceneFromPng("Asset18", "resources/source/assets/SmallTree02.png",  12.5, 10, 87.5, 80, 1, &loadSmallTree02);
    scene->CS_createButtonToSceneFromPng("Asset19", "resources/source/assets/SmallTree03.png",  12.5, 10, 75, 90, 1, &loadSmallTree03);
    scene->CS_createButtonToSceneFromPng("Asset20", "resources/source/assets/SmallTree04.png",  12.5, 10, 87.5, 90, 1, &loadSmallTree04);

    scene->setBorneMap(0, 1000);
    scene->loadAssets(initAssets(render));
    setGround(scene);
    scene->loadParallax(initParallax(render));
    scene->loadCamera(initCamera());

    return (scene);
}