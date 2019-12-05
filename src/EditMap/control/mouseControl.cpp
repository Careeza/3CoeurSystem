#include "editMap.h"

void    moveAssetSelected(CS_EditMapSetting *settings, int xMouse, int yMouse)
{
    CS_Asset    *asset;
    int         w;
    int         h;
    int         x;
    int         y;

    if (settings->QuerySelected())
    {
        asset = settings->QueryAsset();
        asset->QuerySize(w, h, x, y);
        asset->moveAsset(xMouse - w / 2, y, true);
    }
}

void    mouseAction(CS_KeyControl event, CS_EditMapSetting &settings, int& xMouse, int &yMouse, int xCamera, int Ycamera)
{
    int             buttonInfo;
    CS_Assets       *assets;
    CS_Asset        *asset;
    int             i;
    int             y;

    buttonInfo = event.CS_getMouseActions(xMouse, yMouse);
    if (buttonInfo == BOUTON_RELEASE)
    {
        if (settings.QuerySelected())
        {
            asset = settings.QueryAsset();
            asset->QuerySize(i, i, i, y);
            assets = settings.QueryGameScene()->QueryAssets();
            settings.setAssetSelected(assets->loadAssetPixel(asset->QueryName(), 1, 300, y));
        }
        else
            getAsset(&settings, xMouse + xCamera, yMouse + Ycamera);
    }
}