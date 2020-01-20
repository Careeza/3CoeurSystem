#include "editMap.h"

CS_AssetsBank   *initAssetsBankLevel1(SDL_Renderer *render)
{
    CS_AssetsBank *assetsBank;

    assetsBank = new (CS_AssetsBank);

    assetsBank->createAsset(render, "resources/source/assets/BigTree01.png", BigTree01, 30.4, 96, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BigTree02.png", BigTree02, 18.75, 96, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BigTree03.png", BigTree03, 25.4, 96, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BushTree01.png", BushTree01, 10.5, 8.9, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BushTree02.png", BushTree02, 11, 10, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BushTree03.png", BushTree03, 9.4, 11.3, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/BushTree04.png", BushTree04, 10.9, 4.2, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Grass01.png", Grass01, 33.3, 5.3, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Grass02.png", Grass02, 2.4, 4.1, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Grass03.png", Grass03, 6.9, 8.2, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Grass04.png", Grass04, 5.5, 6.2, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Grass05.png", Grass05, 5.8, 8, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/Ground01.png", Ground01, 10, 5.8, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree01.png", MediumTree01, 10, 67.8, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree02.png", MediumTree02, 10, 60.4, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/MediumTree03.png", MediumTree03, 4.3, 52.9, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree01.png", SmallTree01, 2.8, 36.7, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree02.png", SmallTree02, 1.9, 42.2, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree03.png", SmallTree03, 3.75, 48, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/SmallTree04.png", SmallTree04, 2.3, 42.6, 100, 100, 0, 0);

    return (assetsBank);
}

CS_Assets       *initAssets(SDL_Renderer *render)
{
    CS_Assets *assets;

    assets = new (CS_Assets);

    assets->loadBank(initAssetsBankLevel1(render));

    return (assets);
}
