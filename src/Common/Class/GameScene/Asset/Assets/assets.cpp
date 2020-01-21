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
    CS_Asset    *asset;
    t_prop      *prop;
    t_prop      *propSource;

    asset = new (CS_Asset);

    asset->setTexture(assetSource->QueryTexture());
    asset->setName(assetSource->QueryName());
    asset->setSize(assetSource->QueryWidth(), assetSource->QueryHeight());

    prop = asset->QueryProportion();
    propSource = assetSource->QueryProportion();

    prop->w = propSource->w;
    prop->h = propSource->h;
    prop->x = propSource->x;
    prop->y = propSource->y;

    return (asset);
}

void        CS_Assets::updateID()
{
    unsigned long   i;

    i = 0;
    while (i < assets.size())
    {
        assets[i]->setID(i);
        i++;
    }
}


void        CS_Assets::addToGround(CS_Asset *asset, int xAsset)
{
    int x;
    int y;
    int w;
    int h;

    unsigned long   i;
    i = 0;
    while (i < ground.size())
    {
        ground[i]->QuerySize(w, h, x, y);
        if (x > xAsset)
            break;
        i++;
    }
    ground.emplace(ground.begin() + i, asset);
}

CS_Asset    *CS_Assets::loadAsset(t_assetName name, int zIndex, float x, float y)
{
    unsigned long   i;
    CS_Asset        *asset;
    CS_HitBox       *hitBox;
    t_prop          *prop;
    int             wAsset;
    int             hAsset;
    int             xAsset;
    int             yAsset;

    asset = copyAsset(assetsBank->QueryAsset(name));

    asset->addAsset(zIndex, x, y);

    hitBox = asset->QueryHitBox();

    asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
    prop = asset->QueryProportion();
    
    hitBox->setWPixel((wAsset * prop->w) / 100);
    hitBox->setHPixel((hAsset * prop->h) / 100);
    hitBox->setXPixel((wAsset * prop->x) / 100 + xAsset);
    hitBox->setYPixel((hAsset * prop->y) / 100 + yAsset);

    i = 0;
    while (i < assets.size() && zIndex >= assets[i]->QueryZIndex())
        i++;
    assets.emplace(assets.begin() + i, asset);

    if (name == Ground01)
        addToGround(asset, xAsset);

    updateID();
    return (asset);
}

CS_Asset    *CS_Assets::loadAssetPixel(t_assetName name, int zIndex, int x, int y)
{
    unsigned long   i;
    CS_Asset        *asset;
    CS_HitBox       *hitBox;
    t_prop          *prop;
    int             wAsset;
    int             hAsset;
    int             xAsset;
    int             yAsset;

    asset = copyAsset(assetsBank->QueryAsset(name));

    asset->addAssetPixel(zIndex, x, y);

    hitBox = asset->QueryHitBox();

    asset->QuerySize(wAsset, hAsset, xAsset, yAsset);
    prop = asset->QueryProportion();
    
    hitBox->setWPixel((wAsset * prop->w) / 100);
    hitBox->setHPixel((hAsset * prop->h) / 100);
    hitBox->setXPixel((wAsset * prop->x) / 100 + xAsset);
    hitBox->setYPixel((hAsset * prop->y) / 100 + yAsset);

    i = 0;
    while (i < assets.size() && zIndex >= assets[i]->QueryZIndex())
        i++;
    assets.emplace(assets.begin() + i, asset);

    if (name == Ground01)
        addToGround(asset, xAsset);

    updateID();
    return (asset);
}

void        printName(t_assetName name)
{
    if (name == BigTree01)
        std::cout << "BigTree01";
    else if (name == BigTree02)
        std::cout << "BigTree02";
    else if (name == BigTree03)
        std::cout << "BigTree03";
    else if (name == BushTree01)
        std::cout << "BushTree01";
    else if (name == BushTree02)
        std::cout << "BushTree02";
    else if (name == BushTree03)
        std::cout << "BushTree03";
    else if (name == BushTree04)
        std::cout << "BushTree04";
    else if (name == Grass01)
        std::cout << "Grass01";
    else if (name == Grass02)
        std::cout << "Grass02";
    else if (name == Grass03)
        std::cout << "Grass03";
    else if (name == Grass04)
        std::cout << "Grass04";
    else if (name == Grass05)
        std::cout << "Grass05";
    else if (name == Ground01)
        std::cout << "Ground01";
    else if (name == MediumTree01)
        std::cout << "MediumTree01";
    else if (name == MediumTree02)
        std::cout << "MediumTree02";
    else if (name == MediumTree03)
        std::cout << "MediumTree03";
    else if (name == SmallTree01)
        std::cout << "SmallTree01";
    else if (name == SmallTree02)
        std::cout << "SmallTree02";
    else if (name == SmallTree03)
        std::cout << "SmallTree03";
    else if (name == SmallTree04)
        std::cout << "SmallTree04";
    else if (name == Plateforme)
        std::cout << "Plateforme";
    else if (name == Dirt)
        std::cout << "Dirt";
}

//    assets->loadAsset(BigTree01, 1, XBigTree02, YBigTree01);

void        CS_Assets::printAsset()
{
    unsigned long   i;
    int             w;
    int             h;
    int             x;
    int             y;

    std::cout << "CS_Assets       *initAssets(SDL_Renderer *render)" << std::endl;
    std::cout << "{" << std::endl << std::endl;
    std::cout << "  assets = new (CS_Assets);" << std::endl;
    std::cout << "  assets->loadBank(initAssetsBankLevel1(render));" << std::endl << std::endl;

    i = 0;
    while (i < assets.size())
    {
        std::cout << "  assets->loadAsset(";

        printName(assets[i]->QueryName());
        std::cout << ", ";

        std::cout << assets[i]->QueryZIndex();
        std::cout << ", ";


        assets[i]->QuerySize(w, h, x, y);
        std::cout << x / (float)Tools->QueryWindowWidth() * 100;
        std::cout << ", ";
        std::cout << y / (float)Tools->QueryWindowHeight() * 100;
        std::cout << ");" << std::endl;

        i++;
    }
    
    std::cout << std::endl << " return (assets);" << std::endl;
    std::cout << "}" << std::endl;
}

void        CS_Assets::loadBank(CS_AssetsBank *assetsBankSource)
{
    assetsBank = assetsBankSource;
}

void        CS_Assets::deleteAsset(int index)
{
    std::cout << "here lol = " << index << std::endl;
    assets.erase(assets.begin() + index);
    updateID();
}


CS_Asset    *CS_Assets::QueryAsset(int index)
{
    return (assets[index]);
}

int         CS_Assets::QueryNbAssets()
{
    return (assets.size());
}