#include "editMap.h"

void    loadBigTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BigTree01, 1, 0, YBigTree01));
    set->setSelected(true);
}

void    loadBigTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BigTree02, 1, 0, YBigTree02));
    set->setSelected(true);
}

void    loadBigTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BigTree03, 1, 0, YBigTree03));
    set->setSelected(true);
}

void    loadBushTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BushTree01, 1, 0, YBushTree01));
    set->setSelected(true);
}

void    loadBushTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BushTree02, 1, 0, YBushTree02));
    set->setSelected(true);
}

void    loadBushTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BushTree03, 1, 0, YBushTree03));
    set->setSelected(true);
}

void    loadBushTree04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(BushTree04, 1, 0, YBushTree04));
    set->setSelected(true);
}

void    loadGrass01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Grass01, 1, 0, YGrass01));
    set->setSelected(true);
}

void    loadGrass02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Grass02, 1, 0, YGrass02));
    set->setSelected(true);
}

void    loadGrass03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Grass03, 1, 0, YGrass03));
    set->setSelected(true);
}

void    loadGrass04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Grass04, 1, 0, YGrass04));
    set->setSelected(true);
}

void    loadGrass05(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Grass05, 1, 0, YGrass05));
    set->setSelected(true);
}

void    loadGround01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(Ground01, 1, 0, YGround01));
    set->setSelected(true);
}

void    loadMediumTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(MediumTree01, 1, 0, YMediumTree01));
    set->setSelected(true);
}

void    loadMediumTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(MediumTree02, 1, 0, YMediumTree02));
    set->setSelected(true);
}

void    loadMediumTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(MediumTree03, 1, 0, YMediumTree03));
    set->setSelected(true);
}

void    loadSmallTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(SmallTree01, 1, 0, YSmallTree01));
    set->setSelected(true);
}

void    loadSmallTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(SmallTree02, 1, 0, YSmallTree02));
    set->setSelected(true);
}

void    loadSmallTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;


    (void)render;
    set = (CS_EditMapSetting*)settings;

    changeButton(set);

    assets = set->QueryGameScene()->QueryAssets();

    set->setAssetSelected(assets->loadAsset(SmallTree03, 1, 0, YSmallTree03));
    set->setSelected(true);
}

void    loadSmallTree04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    changeButton(set);
    assets = set->QueryGameScene()->QueryAssets();
    set->setAssetSelected(assets->loadAsset(SmallTree04, 1, 0, YSmallTree04));
    set->setSelected(true);
}