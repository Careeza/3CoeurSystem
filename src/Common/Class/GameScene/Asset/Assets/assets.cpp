# include "gameScene.h"

CS_Assets::CS_Assets()
{

}

CS_Assets::~CS_Assets()
{
    delete assetsBank;
}

CS_Asset    *copyAsset(CS_Asset *assetSource)
{
    CS_Asset *asset;

    asset = new (CS_Asset);

    asset->setTexture(assetSource->QueryTexture());
    asset->setName(assetSource->QueryName());
    asset->setSize(assetSource->QueryWidth(), assetSource->QueryHeight());

    return (asset);
}

CS_Asset    *CS_Assets::loadAsset(t_assetName name, int zIndex, float x, float y)
{
    CS_Asset        *asset;
    unsigned long   i;

    asset = copyAsset(assetsBank->QueryAsset(name));

    asset->addAsset(zIndex, x, y);

    i = 0;
    while (i < assets.size() && zIndex >= assets[i]->QueryZIndex())
        i++;
    assets.emplace(assets.begin() + i, asset);
    asset->setID(i);
    return (asset);
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