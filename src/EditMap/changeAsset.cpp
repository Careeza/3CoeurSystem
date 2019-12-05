#include "editMap.h"

void    deleteActualAsset(CS_EditMapSetting *set)
{
    CS_Asset    *asset;
    CS_Assets   *assets;
    int         index;

    asset = set->QueryAsset();
    assets = set->QueryGameScene()->QueryAssets();
    index = asset->QueryID();
    assets->deleteAsset(index);
    set->setSelected(false);
}

void    changeButton(CS_EditMapSetting *set)
{
    if (set->QuerySelected())
    {
        deleteActualAsset(set);
    }
}