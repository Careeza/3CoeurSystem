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
    assetsBank->createAsset(render, "resources/source/assets/plateforme.png", Plateforme, 10, 5.8, 100, 100, 0, 0);
    assetsBank->createAsset(render, "resources/source/assets/dirt.png", Dirt, 10, 60.4, 100, 100, 0, 0);
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

    assets->loadAsset(Ground01, 1, 0, 94.2222);
    assets->loadAsset(Ground01, 1, 9.79167, 94.2222);
    assets->loadAsset(Ground01, 1, 19.7917, 94.2222);
    assets->loadAsset(Ground01, 1, 29.6528, 94.2222);
    assets->loadAsset(Ground01, 1, 39.6528, 94.2222);
    assets->loadAsset(Ground01, 1, 49.5139, 94.2222);
    assets->loadAsset(Ground01, 1, 59.5139, 94.2222);
    assets->loadAsset(Ground01, 1, 69.375, 94.2222);
    assets->loadAsset(Ground01, 1, 79.375, 94.2222);
    assets->loadAsset(Ground01, 1, 89.3056, 94.2222);
    assets->loadAsset(Ground01, 1, 99.1667, 94.2222);
    assets->loadAsset(Ground01, 1, 109.167, 94.2222);
    assets->loadAsset(Ground01, 1, 119.028, 94.2222);
    assets->loadAsset(Ground01, 1, 129.028, 94.2222);
    assets->loadAsset(Ground01, 1, 138.889, 94.2222);
    assets->loadAsset(Ground01, 1, 148.889, 94.2222);
    assets->loadAsset(Ground01, 1, 158.75, 94.2222);
    assets->loadAsset(Ground01, 1, 168.75, 94.2222);
    assets->loadAsset(Ground01, 1, 178.681, 94.2222);
    assets->loadAsset(Ground01, 1, 188.542, 94.2222);
    assets->loadAsset(Ground01, 1, 198.542, 94.2222);
    assets->loadAsset(Ground01, 1, 208.403, 94.2222);
    assets->loadAsset(Ground01, 1, 218.403, 94.2222);
    assets->loadAsset(Ground01, 1, 228.264, 94.2222);
    assets->loadAsset(Ground01, 1, 238.264, 94.2222);
    assets->loadAsset(Ground01, 1, 248.125, 94.2222);
    assets->loadAsset(Ground01, 1, 258.125, 94.2222);
    assets->loadAsset(Ground01, 1, 268.056, 94.2222);
    assets->loadAsset(Ground01, 1, 277.917, 94.2222);
    assets->loadAsset(Ground01, 1, 287.917, 94.2222);
    assets->loadAsset(Ground01, 1, 297.778, 94.2222);
    assets->loadAsset(Ground01, 1, 307.639, 94.2222);
    assets->loadAsset(Ground01, 1, 317.5, 94.2222);
    assets->loadAsset(Ground01, 1, 327.5, 94.2222);
    assets->loadAsset(Ground01, 1, 337.431, 94.2222);
    assets->loadAsset(Ground01, 1, 347.292, 94.2222);
    assets->loadAsset(Ground01, 1, 357.292, 94.2222);
    assets->loadAsset(Ground01, 1, 367.153, 94.2222);
    assets->loadAsset(Ground01, 1, 377.153, 94.2222);
    assets->loadAsset(Ground01, 1, 387.014, 94.2222);
    assets->loadAsset(Ground01, 1, -10, 94.2222);
    assets->loadAsset(Ground01, 1, -19.9306, 94.2222);
    assets->loadAsset(Plateforme, 1, 405.556, 84.4444);
    assets->loadAsset(Plateforme, 1, 429.792, 84.4444);
    assets->loadAsset(Ground01, 1, 448.333, 94.2222);
    assets->loadAsset(Ground01, 1, 458.264, 94.2222);
    assets->loadAsset(Plateforme, 1, 478.958, 88.8889);
    assets->loadAsset(Plateforme, 1, 500.625, 79.2222);
    assets->loadAsset(Plateforme, 1, 522.292, 68.4444);
    assets->loadAsset(Plateforme, 1, 543.403, 58.6667);

    return (assets);
}
