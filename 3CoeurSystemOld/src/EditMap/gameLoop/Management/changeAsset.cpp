#include "editMap.h"

void    deleteAssetSelected(CS_Asset *assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    int         index;

    index = assetSelected->QueryID();
    assets->deleteAsset(index);
    haveAnAsset = false;
}

void    changeButton(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    if (haveAnAsset)
        deleteAssetSelected(assetSelected, assets, haveAnAsset);
}
