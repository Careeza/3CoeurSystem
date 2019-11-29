# include "gameScene.h"

CS_Assets::CS_Assets()
{

}

CS_Assets::~CS_Assets()
{
    delete assetsBank;
}

void        loadAsset(t_assetName name, int zIndex, float x, float y);
{
    CS_Asset    *asset;

    asset = assetsBank.QueryAsset(name);
}

void        CS_Assets::loadBank(CS_AssetsBank *assetsBankSource)
{
    assetsBank = assetsBankSource;
}

CS_Asset    *CS_Assets::QueryAsset(int index)
{
    return (assets[i]);
}

int         CS_Assets::QueryNbAssets()
{
    return (assets.size());
}