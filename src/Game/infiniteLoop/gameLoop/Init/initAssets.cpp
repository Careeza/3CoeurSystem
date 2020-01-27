# include "gameScene.h"

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
    assetsBank->createAsset(render, "resources/source/assets/dirt.png", Dirt, 12, 20, 100, 100, 0, 0);
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

assets->loadAsset(Ground01, 1, 0, 94.1111);
  assets->loadAsset(Ground01, 1, 9.79167, 94.1111);
  assets->loadAsset(Ground01, 1, 19.7917, 94.1111);
  assets->loadAsset(Ground01, 1, 29.6528, 94.1111);
  assets->loadAsset(Ground01, 1, 39.6528, 94.1111);
  assets->loadAsset(Ground01, 1, 49.5139, 94.1111);
  assets->loadAsset(Ground01, 1, 59.5139, 94.1111);
  assets->loadAsset(Ground01, 1, 69.375, 94.1111);
  assets->loadAsset(Ground01, 1, 79.375, 94.1111);
  assets->loadAsset(Ground01, 1, 89.3056, 94.1111);
  assets->loadAsset(Ground01, 1, 99.1667, 94.1111);
  assets->loadAsset(Ground01, 1, 109.167, 94.1111);
  assets->loadAsset(Ground01, 1, 119.028, 94.1111);
  assets->loadAsset(Ground01, 1, 129.028, 94.1111);
  assets->loadAsset(Ground01, 1, 138.889, 94.1111);
  assets->loadAsset(Ground01, 1, 148.889, 94.1111);
  assets->loadAsset(Ground01, 1, 158.75, 94.1111);
  assets->loadAsset(Ground01, 1, 168.75, 94.1111);
  assets->loadAsset(Ground01, 1, 178.681, 94.1111);
  assets->loadAsset(Ground01, 1, 188.542, 94.1111);
  assets->loadAsset(Ground01, 1, 198.542, 94.1111);
  assets->loadAsset(Ground01, 1, 208.403, 94.1111);
  assets->loadAsset(Ground01, 1, 218.403, 94.1111);
  assets->loadAsset(Ground01, 1, 228.264, 94.1111);
  assets->loadAsset(Ground01, 1, 238.264, 94.1111);
  assets->loadAsset(Ground01, 1, 248.125, 94.1111);
  assets->loadAsset(Ground01, 1, 258.125, 94.1111);
  assets->loadAsset(Ground01, 1, 268.056, 94.1111);
  assets->loadAsset(Ground01, 1, -10, 94.1111);
  assets->loadAsset(Ground01, 1, -19.9306, 94.1111);
  assets->loadAsset(Plateforme, 1, 277.986, 94.1111);
  assets->loadAsset(Plateforme, 1, 309.167, 86);
  assets->loadAsset(Plateforme, 1, 338.403, 94.2222);
  assets->loadAsset(Ground01, 1, 348.333, 94.2222);
  assets->loadAsset(Ground01, 1, 358.264, 94.2222);
  assets->loadAsset(Plateforme, 1, 368.194, 94.2222);
  assets->loadAsset(Plateforme, 1, 396.111, 80.3333);
  assets->loadAsset(Plateforme, 1, 424.375, 64.8889);
  assets->loadAsset(Plateforme, 1, 453.819, 49.8889);
  assets->loadAsset(Plateforme, 1, 483.611, 49.8889);
  assets->loadAsset(Ground01, 1, 490.486, 49.8889);
  assets->loadAsset(Ground01, 1, 361.736, 94.2222);
  assets->loadAsset(Ground01, 1, 344.861, 94.2222);
  assets->loadAsset(Ground01, 1, 500.417, 49.8889);
  assets->loadAsset(Ground01, 1, 510.347, 49.8889);
  assets->loadAsset(Ground01, 1, 520.278, 49.8889);
  assets->loadAsset(Ground01, 1, 530.208, 49.8889);
  assets->loadAsset(Ground01, 1, 540.139, 49.8889);
  assets->loadAsset(Ground01, 1, 550.069, 49.8889);
  assets->loadAsset(Ground01, 1, 560, 49.8889);
  assets->loadAsset(Dirt, 1, 484.306, 55.5556);
  assets->loadAsset(Dirt, 1, 484.306, 75.4444);
  assets->loadAsset(Dirt, 1, 484.306, 89.8889);
  assets->loadAsset(Dirt, 1, 496.181, 55.5556);
  assets->loadAsset(Dirt, 1, 508.056, 55.5556);
  assets->loadAsset(Dirt, 1, 519.931, 55.5556);
  assets->loadAsset(Dirt, 1, 531.736, 55.5556);
  assets->loadAsset(Dirt, 1, 543.611, 55.5556);
  assets->loadAsset(Dirt, 1, 555.486, 55.5556);
  assets->loadAsset(Dirt, 1, 558.056, 55.5556);
  assets->loadAsset(Dirt, 1, 496.181, 75.4444);
  assets->loadAsset(Dirt, 1, 508.056, 75.4444);
  assets->loadAsset(Dirt, 1, 519.931, 75.4444);
  assets->loadAsset(Dirt, 1, 531.736, 75.4444);
  assets->loadAsset(Dirt, 1, 543.611, 75.4444);
  assets->loadAsset(Dirt, 1, 555.486, 75.4444);
  assets->loadAsset(Dirt, 1, 558.056, 75.4444);
  assets->loadAsset(Dirt, 1, 496.181, 89.8889);
  assets->loadAsset(Dirt, 1, 508.056, 89.8889);
  assets->loadAsset(Dirt, 1, 519.931, 89.8889);
  assets->loadAsset(Dirt, 1, 531.736, 89.8889);
  assets->loadAsset(Dirt, 1, 543.611, 89.8889);
  assets->loadAsset(Dirt, 1, 555.486, 89.8889);
  assets->loadAsset(Dirt, 1, 558.056, 89.8889);
  assets->loadAsset(Ground01, 1, 569.931, 49.8889);
  assets->loadAsset(Ground01, 1, 579.861, 49.8889);
  assets->loadAsset(Ground01, 1, 589.792, 49.8889);
  assets->loadAsset(Dirt, 1, 569.931, 55.5556);
  assets->loadAsset(Dirt, 1, 569.931, 75.4444);
  assets->loadAsset(Dirt, 1, 581.806, 55.5556);
  assets->loadAsset(Dirt, 1, 593.681, 55.5556);
  assets->loadAsset(Dirt, 1, 597.778, 55.5556);
  assets->loadAsset(Dirt, 1, 581.806, 75.4444);
  assets->loadAsset(Dirt, 1, 593.681, 75.4444);
  assets->loadAsset(Dirt, 1, 597.778, 75.4444);
  assets->loadAsset(Dirt, 1, 569.931, 89.8889);
  assets->loadAsset(Dirt, 1, 581.806, 89.8889);
  assets->loadAsset(Dirt, 1, 593.681, 89.8889);
  assets->loadAsset(Dirt, 1, 597.778, 89.8889);
  assets->loadAsset(Plateforme, 1, 600.417, 49.8889);
  assets->loadAsset(Ground01, 1, 595.694, 49.8889);
  assets->loadAsset(Plateforme, 1, 630.208, 49.8889);
  assets->loadAsset(Plateforme, 1, 660, 49.8889);
  assets->loadAsset(Plateforme, 1, 645.139, 30.5556);
  assets->loadAsset(Plateforme, 1, 645.069, 70.6667);
  assets->loadAsset(Plateforme, 1, 689.792, 49.8889);
  assets->loadAsset(Plateforme, 1, 717.431, 67);
  assets->loadAsset(Ground01, 1, 721.528, 67);
  assets->loadAsset(Ground01, 1, 731.458, 67);
  assets->loadAsset(Ground01, 1, 741.389, 67);
  assets->loadAsset(Ground01, 1, 751.319, 67);
  assets->loadAsset(Ground01, 1, 761.25, 67);
  assets->loadAsset(Ground01, 1, 771.181, 67);
  assets->loadAsset(Ground01, 1, 781.111, 67);
  assets->loadAsset(Ground01, 1, 791.042, 67);
  assets->loadAsset(Ground01, 1, 800.972, 67);
  assets->loadAsset(Ground01, 1, 810.903, 67);
  assets->loadAsset(Ground01, 1, 820.833, 67);
  assets->loadAsset(Ground01, 1, 830.764, 67);
  assets->loadAsset(Dirt, 1, 718.125, 72.6667);
  assets->loadAsset(Dirt, 1, 730, 72.6667);
  assets->loadAsset(Dirt, 1, 741.875, 72.6667);
  assets->loadAsset(Dirt, 1, 753.75, 72.6667);
  assets->loadAsset(Dirt, 1, 765.625, 72.6667);
  assets->loadAsset(Dirt, 1, 777.5, 72.6667);
  assets->loadAsset(Dirt, 1, 789.375, 72.6667);
  assets->loadAsset(Dirt, 1, 801.25, 72.6667);
  assets->loadAsset(Dirt, 1, 813.125, 72.6667);
  assets->loadAsset(Dirt, 1, 825, 72.6667);
  assets->loadAsset(Dirt, 1, 828.819, 72.6667);
  assets->loadAsset(Dirt, 1, 718.125, 89.8889);
  assets->loadAsset(Dirt, 1, 730, 89.8889);
  assets->loadAsset(Dirt, 1, 741.875, 89.8889);
  assets->loadAsset(Dirt, 1, 753.75, 89.8889);
  assets->loadAsset(Dirt, 1, 765.625, 89.8889);
  assets->loadAsset(Dirt, 1, 777.5, 89.8889);
  assets->loadAsset(Dirt, 1, 789.375, 89.8889);
  assets->loadAsset(Dirt, 1, 801.25, 89.8889);
  assets->loadAsset(Dirt, 1, 813.125, 89.8889);
  assets->loadAsset(Dirt, 1, 825, 89.8889);
  assets->loadAsset(Dirt, 1, 828.819, 89.8889);

    assets->loadGround();

    return (assets);
}
