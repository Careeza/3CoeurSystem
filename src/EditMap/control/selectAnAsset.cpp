#include "editMap.h"

void    getAsset(CS_EditMapSetting *set, int xMouse, int yMouse)
{
    int         i;
    CS_Assets   *assets;
    CS_Asset    *asset;

    int         x;
    int         y;
    int         w;
    int         h;

    assets = set->QueryGameScene()->QueryAssets();
    i = assets->QueryNbAssets() - 1;
    while (i >= 0)
    {
        asset = assets->QueryAsset(i);
        asset->QuerySize(w, h, x, y);
        if (xMouse >= x && xMouse <= x + w && yMouse >= y && yMouse <= y + h)
            break ;
        i--;
    }
    if (i >= 0)
        set->setAssetSelected(assets->QueryAsset(i));
}