# include "gameScene.h"

CS_Assets::CS_Assets()
{

}

CS_Assets::~CS_Assets()
{
    delete assetsBank;
}

void         CS_Assets::loadAsset(t_assetName name, int zIndex, float x, float y)
{
    CS_Asset        *asset;
    unsigned long   i;

    asset = assetsBank->QueryAsset(name);
    asset->addAsset(zIndex, x, y);

    i = 0;
    while (i < assets.size() && zIndex >= assets[i]->QueryZIndex())
        i++;
    assets.emplace(assets.begin() + i, asset);
}

void        CS_Assets::loadBank(CS_AssetsBank *assetsBankSource)
{
    assetsBank = assetsBankSource;
}

CS_Asset    *CS_Assets::QueryAsset(int index)
{
    return (assets[index]);
}

int         CS_Assets::QueryNbAssets()
{
    return (assets.size());
}