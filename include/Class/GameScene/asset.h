#ifndef ASSETS_H

# define ASSETS_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

# include "physicalEngine.h"

typedef enum	e_assetName {
    BigTree01,
    BigTree02,
    BigTree03,
    BushTree01,
    BushTree02,
    BushTree03,
    BushTree04,
    Grass01,
    Grass02,
    Grass03,
    Grass04,
    Grass05,
    Ground01,
    MediumTree01,
    MediumTree02,
    MediumTree03,
    SmallTree01,
    SmallTree02,
    SmallTree03,
    SmallTree04,
}				t_assetName;

typedef enum    e_assetBankName {
    Niveau1,
    Niveau2,
    Niveau3
}               t_assetBankName;

class   CS_Asset
{
    public:
        CS_Asset();
        ~CS_Asset();

        void            createAsset(SDL_Renderer *render, std::string source, t_assetName nameSource, float wSource, float hSource, float wProp, float hProp, float xProp, float yProp);
        void            addAsset(int zIndexSource, float xSource, float ySource);
        void            addAssetPixel(int zIndexSource, int xSource, int ySource);

        void            setID(int idSource);

        void            setTexture(SDL_Texture *textureSource);
        void            setName(t_assetName nameSource);
        void            setSize(int wSource, int hSource);

        void            resizeAsset(int wSource, int hSource, bool method);
        void            moveAsset(int xSource, int ySource, bool method);
        void            printSize();

        SDL_Texture     *QueryTexture();
        int             QueryID();
        int             QueryWidth();
        int             QueryHeight();
        void            QuerySize(int& wDest, int& hDest, int& xDest, int& yDest);
        t_assetName     QueryName();
        int             QueryZIndex();
        CS_HitBox       *QueryHitBox();
        t_prop          *QueryProportion();

    private:
        SDL_Texture     *texture;

        int             zIndex;
        int             w;
        int             h;
        int             x;
        int             y;

        int             id;
        t_assetName     name;

        CS_HitBox       *hitBox;
        t_prop          *prop;

        bool            collision;
};

class   CS_AssetsBank
{
    public:
        CS_AssetsBank();
        ~CS_AssetsBank();

        void        createAsset(SDL_Renderer *render, std::string source, t_assetName name, float w, float h, float wProp, float hProp, float xProp, float yProp);

        CS_Asset    *QueryAsset(t_assetName name);

    private:
        std::vector<CS_Asset *> assets;
};

class   CS_Assets
{
    public:
        CS_Assets();
        ~CS_Assets();

        CS_Asset    *loadAsset(t_assetName name, int zIndex, float x, float y);
        CS_Asset    *loadAssetPixel(t_assetName name, int zIndex, int x, int y);
        void        addToGround(CS_Asset *asset, int xAsset);

        void        loadBank(CS_AssetsBank *assetsBankSource);

        void        deleteAsset(int index);

        void        updateID();

        void        printAsset();

        CS_Asset    *QueryAsset(int index);
        int         QueryNbAssets();

    private:
        std::vector<CS_Asset *>     assets;
        std::vector<CS_Asset *>     ground;
        CS_AssetsBank               *assetsBank;
};

#endif