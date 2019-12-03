#include "editMap.h"

# define YBigTree01 1
# define YBigTree02 1
# define YBigTree03 1
# define YBushTree01 1
# define YBushTree02 1
# define YBushTree03 1
# define YBushTree04 1
# define YGrass01 1
# define YGrass02 1
# define YGrass03 1
# define YGrass04 1
# define YGrass05 1
# define YGround01 1
# define YMediumTree01 1
# define YMediumTree02 1
# define YMediumTree03 1
# define YSmallTree01 1
# define YSmallTree02 1
# define YSmallTree03 1
# define YSmallTree04 1

void    loadBigTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BigTree01, 1, x, YBigTree01));
    set->setSelected(true);
}

void    loadBigTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BigTree02, 1, x, YBigTree02));
    set->setSelected(true);
}

void    loadBigTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BigTree03, 1, x, YBigTree03));
    set->setSelected(true);
}

void    loadBushTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BushTree01, 1, x, YBushTree01));
    set->setSelected(true);
}

void    loadBushTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BushTree02, 1, x, YBushTree02));
    set->setSelected(true);
}

void    loadBushTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BushTree03, 1, x, YBushTree03));
    set->setSelected(true);
}

void    loadBushTree04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(BushTree04, 1, x, YBushTree04));
    set->setSelected(true);
}

void    loadGrass01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Grass01, 1, x, YGrass01));
    set->setSelected(true);
}

void    loadGrass02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Grass02, 1, x, YGrass02));
    set->setSelected(true);
}

void    loadGrass03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Grass03, 1, x, YGrass03));
    set->setSelected(true);
}

void    loadGrass04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Grass04, 1, x, YGrass04));
    set->setSelected(true);
}

void    loadGrass05(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Grass05, 1, x, YGrass05));
    set->setSelected(true);
}

void    loadGround01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(Ground01, 1, x, YGround01));
    set->setSelected(true);
}

void    loadMediumTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(MediumTree01, 1, x, YMediumTree01));
    set->setSelected(true);
}

void    loadMediumTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(MediumTree02, 1, x, YMediumTree02));
    set->setSelected(true);
}

void    loadMediumTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(MediumTree03, 1, x, YMediumTree03));
    set->setSelected(true);
}

void    loadSmallTree01(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(SmallTree01, 1, x, YSmallTree01));
    set->setSelected(true);
}

void    loadSmallTree02(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(SmallTree02, 1, x, YSmallTree02));
    set->setSelected(true);
}

void    loadSmallTree03(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(SmallTree03, 1, x, YSmallTree03));
    set->setSelected(true);
}

void    loadSmallTree04(void* settings, SDL_Renderer *render)
{
    CS_EditMapSetting *set;
    CS_Assets   *assets;
    CS_Camera   *camera;
    int         x;
    int         y;

    (void)render;
    set = (CS_EditMapSetting*)settings;
    assets = set->QueryGameScene()->QueryAssets();
    camera = set->QueryGameScene()->QueryCamera();

    camera->queryCameraPosition(x, y);
    set->setAssetSelected(assets->loadAsset(SmallTree04, 1, x, YSmallTree04));
    set->setSelected(true);
}

int     bouttonManagement2(CS_KeyControl& control, CS_EditMapSetting& settings, SDL_Renderer *render)
{
    static std::shared_ptr<CS_Element>      saveButton = NULL;
    std::shared_ptr<CS_Element>             button;
    int                                     buttonInfo;

    button = control.CS_getBoutton(buttonInfo);
    if (button != saveButton && buttonInfo != NO_ACTION)
    {
        if (saveButton != NULL)
        {
            if (saveButton->CS_haveText())
                saveButton->CS_setZoom(NOZOOM);
            saveButton->CS_setBrightness(false);
        }
        saveButton = button;
    }
    if (buttonInfo == NO_BOUTON)
    {
        // do nothing for the moment
        return (0);
    }
    else if (buttonInfo == MOUSE_MOTION)
    {
        if (button->CS_haveText())
            button->CS_setZoom(ZOOMIN);
        button->CS_setBrightness(true);
        // set zoomIn on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTTON_PRESS)
    {
        if (button->CS_haveText())
            button->CS_setZoom(ZOOMOUT);
        button->CS_setBrightness(true);
        // set zoomOut on
        // set brillance on
        return (0);
    }
    else if (buttonInfo == BOUTON_RELEASE)
    {
        if (button->CS_haveText())
            button->CS_setZoom(NOZOOM);
        button->CS_setBrightness(false);
        button->CS_useFonction(&settings, render);
        // use fonction
        return (0);
    }
    else
        return (0);
}