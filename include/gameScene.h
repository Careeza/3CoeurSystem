#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"
# include "tools.h"

class   CS_Layer
{
    public:
        CS_Layer();
        ~CS_Layer();
        void        createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndexSource);

        void        moveLayer(int xSource);

        bool        secondScopeNeeded();

        int         queryZindex();
        SDL_Texture *queryTexture();
        SDL_Rect    *queryScopeMain();
        SDL_Rect    *querySizeMain();
        SDL_Rect    *queryScopeSecond();
        SDL_Rect    *querySizeSecond();

    private:
        SDL_Texture *layerTexture;
        
        int         scopeWidth;
        int         scopeHeight;
        int         scopeX;
        int         scopeY;

        int         textureW;
        int         textureH;

        SDL_Rect    *scopeMain;
        SDL_Rect    *scopeSecond;

        SDL_Rect    *sizeMain;
        SDL_Rect    *sizeSecond;
        
        float       speed;

        int         zIndex;

        bool        needSecondScope;
};


class   CS_Parallax
{
    public:
        CS_Parallax();
        ~CS_Parallax();

        void        createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndex);

        void        moveLayer(int index, int x);

        CS_Layer    *QueryLayer(int index);
        int         QueryNbLayers();

    private:
        std::vector<CS_Layer *> layers;
};

class   CS_HitBox
{
    public:
        CS_HitBox();
        ~CS_HitBox();
        bool                Collision(int wTest, int hTest, int xTest, int yTest);

        void                setW(float wSource);
        void                setH(float hSource);
        void                setX(float xSource);
        void                setY(float ySource);

        void                setWPixel(int wSource);
        void                setHPixel(int hSource);
        void                setXPixel(int xSource);
        void                setYPixel(int ySource);

        void                moveX(int xSource);
        void                moveY(int ySource);
        void                extandW(int wSource);
        void                extandH(int hSource);
        void                extandSize(int wSource, int hSource);

        void                setHitBoxSize(float wSource, float hSource);
        void                setHitBoxPos(float xSource, float ySource);
        void                setHitBox(float wSource, float hSource, float xSource, float ySource);

        void                setHitBoxSizePixel(int wSource, int hSource);
        void                setHitBoxPosPixel(int xSource, int ySource);
        void                setHitBoxPixel(int wSource, int hSource, int xSource, int ySource);

        int                 QueryW();
        int                 QueryH();
        int                 QueryX();
        int                 QueryY();

        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int &yDest);
        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);

    private:
        int                 w;
        int                 h;
        int                 x;
        int                 y;
};

typedef struct  e_prop {
    float w;
    float h;
    float x;
    float y;
}               t_prop;

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

        void            createAsset(SDL_Renderer *render, std::string source, t_assetName nameSource, float wSource, float hSource);
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
        t_prop          prop;

        bool            collision;
};

class   CS_AssetsBank
{
    public:
        CS_AssetsBank();
        ~CS_AssetsBank();

        void        createAsset(SDL_Renderer *render, std::string source, t_assetName name, float w, float h);

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


        void        loadBank(CS_AssetsBank *assetsBankSource);

        void        deleteAsset(int index);

        void        updateID();

        void        printAsset();

        CS_Asset    *QueryAsset(int index);
        int         QueryNbAssets();

    private:
        std::vector<CS_Asset *>     assets;
        CS_AssetsBank               *assetsBank;
};

typedef enum	e_aniamtion {
    STATIC,
    WALK,
    SPRINT,
}				t_animation;

# define NOINTERRUPT 1
# define INTERRUPT 2


# define MCWALKL "resources/source/MainCharacter/RunL.png"
# define MCWALKR "resources/source/MainCharacter/RunR.png"

# define MCSTATICL "resources/source/MainCharacter/staticL.png"
# define MCSTATICR "resources/source/MainCharacter/staticR.png"

class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();

        void            newAnimation(t_animation nameSource, int stop);
        void            loadTexture(SDL_Renderer *render, std::string png_left, std::string png_right);
        void            cutFrame(int nb_frame, int nb_columnframe, int nb_lineframe);
        void            setMovement(int nb_frame, ...);

        void            restartAnimation();

        bool            nextFrame();
        bool            previousFrame();
        
        void            getFrame(bool right, SDL_Rect* &frameDest, SDL_Texture* &textureDest);
        

        void            moveCharacter(bool right, int& x, int &y);

        t_animation     QueryName();
        SDL_Texture     *QueryTexture(bool right);
        SDL_Rect        *QueryFrame();
        int             QueryMovementX(bool right);
        int             QueryMovementY();

    private:

        t_animation             name;
        int                     interrupt;

        SDL_Texture             *textureR;
        SDL_Texture             *textureL;
        std::vector<SDL_Rect *> frame;

        std::vector<int>        movement;
        
        int                     nbFrame;
        int                     nbColumnFrame;
        int                     nbLineFrame;

        int                     index;
};

class CS_BankAnimation
{
    public:
        CS_BankAnimation();
        ~CS_BankAnimation();
        CS_Animation    *CS_queryAnimationByname(t_animation name);
        void            addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render));

    private:
        std::vector<CS_Animation*>   animations;
};

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();

        void        addAnimation(SDL_Renderer *render, CS_Animation*(*f)(SDL_Renderer *render));
        void        loadAnimation(t_animation name);

        bool        nextFrame();
        bool        previousFrame();
        void        getFrame();
        void        moveCharacter();

        void        setSizePos(float wSource, float hSource, float xSource, float ySource);
        void        setSize(float wSource, float hSource);
        void        setPos(float xSource, float ySource);

        void        setRight(bool rightSource);

        SDL_Texture *queryTexture();
        SDL_Rect    *queryFrame();

        void        querySizePos(int& w, int& h, int& x, int& y);
        void        querySize(int& w, int& h);
        void        queryPos(int& x, int& y);

        int         queryMoveX();
//        int         queryMoveY();


    private:

        CS_BankAnimation    *bank;
        CS_Animation        *animation;
        CS_Animation        *saveAnimation;
        
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        int                 x;
        int                 y;
        int                 w;
        int                 h;

        bool                right;
};

typedef enum	e_enemy {
	CubeRouge,
    CuveVert
}				t_enemy;

class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();

        void    addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algoSource)(CS_Character *enemy, CS_Character *MC));
        void    spawnEnemy(float xSource, float ySource);
        void    reloadParam(CS_Character *MC);
        void    getFrame();
        void    moveCharacter();
        
        SDL_Texture *queryTexture();
        void        querySize(int& w, int& h, int& x, int& y);
        SDL_Rect    *queryFrame();
    private:
        CS_Character    *enemy;
        void            (*algo)(CS_Character *enemy, CS_Character *MC);
};

class   CS_Enemies
{
    public:
        CS_Enemies();
        ~CS_Enemies();

        void        addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algo)(CS_Character *enemy, CS_Character *MC), float w, float h);
        void        reloadParam(int index, CS_Character *MC);

        CS_Enemy    *QueryEnemy(int index);
        int         QueryNbEnemies();

    private:
        std::vector<CS_Enemy *> enemies;   
};

class   CS_GameScene;

class   CS_Camera
{
    public:
        CS_Camera();
        ~CS_Camera();

        void    moveCamera(int xSource, int ySource);
        void    moveCamera2(int xSource, int ySource, CS_GameScene *map);

        void    queryCameraPosition(int& xDest, int& yDest);

    private:
        int     x;
        int     y;
};

class   CS_GameScene : public CS_Scene
{
    public:
        CS_GameScene();
        ~CS_GameScene();

        void            loadMC(CS_Character *MCSource);
        void            loadEnemies(CS_Enemies *enemiesSource);
        void            loadParallax(CS_Parallax *parallaxSource);
        void            loadAssets(CS_Assets *assetsSource);
        void            loadCamera(CS_Camera *cameraSource);
        void            setBorneMap(float borneMaxXSource, float borneMinXSource);

        bool            haveMC();
        bool            haveEnemies();
        bool            haveParallax();
        bool            haveAssets();

        CS_Enemies      *CS_queryEnemies();
        CS_Character    *CS_queryMC();
        CS_Parallax     *QueryParallax();
        CS_Assets       *QueryAssets();
        CS_Camera       *QueryCamera();
        void            QueryBorne(int& borneMaxXDest, int& borneMinXDest);

    private:
        CS_Parallax     *parallax;
        CS_Character    *MC;
        CS_Enemies      *enemies;
        CS_Camera       *camera;
        CS_Assets       *assets;

        bool            verifyMC;
        bool            verifyEnemies;
        bool            verifyParallax;
        bool            verifyAssets;

        int             borneMinX;
        int             borneMaxX;
};

void    moveWithTest(bool right, int w, int h, int& x, int &y, CS_GameScene *map);

#endif