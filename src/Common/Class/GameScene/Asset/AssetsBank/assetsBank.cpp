# include "gameScene.h"

CS_AssetsBank::CS_AssetsBank()
{

}

CS_AssetsBank::~CS_AssetsBank()
{
    //TODO delete bank
}

void        CS_AssetsBank::createAsset(SDL_Renderer *render, std::string source, t_assetName name, float w, float h)
{
    CS_Asset    *asset;

    asset = new (CS_Asset);
    asset->createAsset(render, source, name, w, h);
    assets.push_back(asset);
}

CS_Asset    *CS_AssetsBank::QueryAsset(t_assetName name)
{
    unsigned long i;

    i = 0;
    while (i < assets.size())
    {
        if (assets[i]->QueryName() == name)
        {
            return (assets[i]);
        }
        i++;
    }
    return (NULL);
}
