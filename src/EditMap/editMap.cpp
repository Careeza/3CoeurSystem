#include "editMap.h"

CS_EditMapSetting::CS_EditMapSetting()
{
    selected = false;
}

CS_EditMapSetting::~CS_EditMapSetting()
{

}

void        CS_EditMapSetting::setAssetSelected(CS_Asset *assetSource)
{
    assetSelected = assetSource;
    selected = true;
}

void        CS_EditMapSetting::setSelected(bool selectedSource)
{
    selected = selectedSource;
}

bool        CS_EditMapSetting::QuerySelected()
{
    return (selected);
}

CS_Asset    *CS_EditMapSetting::QueryAsset()
{
    return (assetSelected);
}

