# include "gameScene.h"

void    CS_OnScreen::initOnScreen(CS_Character *MC, CS_Assets *assets)
{
    int bornMin;
    int bornMax;

    int w;
    int h;
    int x;
    int y;

    screenW = Tools->QueryWindowWidth() / 2;
    screenH = Tools->QueryWindowHeight();

    MC->QuerySizePos(w, h, x, y);
    bornMax = x + (w / 2) + screenW;
    bornMin = x + (w / 2) - screenW;

    int         i;
    CS_Asset    *asset;
    int         wAsset;
    int         hAsset;
    int         xAsset;
    int         yAsset;

    i = 0;
    while (i < assets->QueryNbGround())
    {
        asset = assets->QueryGround(i);
        asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
        if (xAsset + wAsset > bornMin && xAsset < bornMax)
            onScreen.push_back(asset);
        i++;
    }
    indexMin = onScreen[0]->QueryID();
    indexMax = onScreen[onScreen.size() - 1]->QueryID();
    std::cout << "test2 = " << onScreen.size() << std::endl;
    std::cout << "test3 = " << indexMin << " - " << indexMax << std::endl;
}

void    CS_OnScreen::updateOnScreen(CS_Character *MC, CS_Assets *ground)
{
    int bornMin;
    int bornMax;

    int w;
    int h;
    int x;
    int y;

    screenW = Tools->QueryWindowWidth() / 2;
    screenH = Tools->QueryWindowHeight();

    MC->QuerySizePos(w, h, x, y);
    bornMax = x + (w / 2) + screenW;
    bornMin = x + (w / 2) - screenW;

    CS_Asset    *asset;
    int         wAsset;
    int         hAsset;
    int         xAsset;
    int         yAsset;

    if (MC->VerifyRight())
    {
        while (indexMax + 1 < ground->QueryNbGround())
        {
            asset = ground->QueryGround(indexMax + 1);
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if (xAsset + wAsset > bornMin && xAsset < bornMax)
            {
                onScreen.push_back(asset);
                indexMax++;
            }
            else
                break;
        }
        while (indexMin < indexMax)
        {
            asset = ground->QueryGround(indexMin);
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if (!(xAsset + wAsset > bornMin && xAsset < bornMax))
            {
                onScreen.erase(onScreen.begin());
                indexMin++;
            }
            else
                break;
        }
    }
    else
    {
        while (indexMin - 1 > 0)
        {
            asset = ground->QueryGround(indexMin - 1);
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if (xAsset + wAsset > bornMin && xAsset < bornMax)
            {
                onScreen.emplace(onScreen.begin(), asset);
                indexMin--;
            }
            else
                break;
        }
        while (indexMax > indexMin)
        {
            asset = ground->QueryGround(indexMax);
            asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
            if (!(xAsset + wAsset > bornMin && xAsset < bornMax))
            {
                onScreen.pop_back();
                indexMax--;
            }
            else
                break;
        }
    }    
}


CS_Asset    *CS_OnScreen::QueryOnScreen(int index)
{
    return (onScreen[index]);
}

int         CS_OnScreen::QueryNbOnScreen()
{
    return (onScreen.size());
}