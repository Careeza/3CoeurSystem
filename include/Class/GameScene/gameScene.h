#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"
# include "animation.h"
# include "asset.h"
# include "backGround.h"
# include "character.h"
# include "enemy.h"
# include "projectile.h"
# include "../../Tools/tools.h"

class   CS_GameScene;

class   CS_Camera
{
    public:
        CS_Camera();
        ~CS_Camera();

        void    moveCamera(int xSource, int ySource);
        void    moveCamera2(int xSource, int ySource);
        void    moveCamera3(CS_Character *MC);

        void    QueryCameraPosition(int& xDest, int& yDest);
        int     QueryCameraPositionX();
        int     QueryCameraPositionY();

    private:
        float     x;
        float     y;
};

class   CS_OnScreen
{
    public:
        void    initOnScreen(CS_Character *MC, CS_Assets *ground);
        void    updateOnScreen(CS_Character *MC, CS_Assets *ground);

        CS_Asset    *QueryOnScreen(int index);
        int         QueryNbOnScreen();

    private:
        std::vector<CS_Asset *>     onScreen;
        int                         indexMin;
        int                         indexMax;
        int                         screenW;
        int                         screenH;
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
        void            loadProjectiles(CS_Projectiles *projectilesSource);
        void            loadOnScreen(CS_OnScreen *onScreenSource);
        void            setBorneMap(float borneMaxXSource, float borneMinXSource);

        bool            haveMC();
        bool            haveEnemies();
        bool            haveParallax();
        bool            haveAssets();

        CS_Enemies      *QueryEnemies();
        CS_Character    *QueryMC();
        CS_Parallax     *QueryParallax();
        CS_Assets       *QueryAssets();
        CS_Camera       *QueryCamera();
        CS_Projectiles  *QueryProjectile();
        CS_OnScreen     *QueryOnScreen();
        void            QueryBorne(int& borneMaxXDest, int& borneMinXDest);

    private:
        CS_Parallax                 *parallax;
        CS_Character                *MC;
        CS_Enemies                  *enemies;
        CS_Camera                   *camera;
        CS_Assets                   *assets;
        CS_Projectiles              *projectiles;
        CS_OnScreen                 *onScreen;

        bool                        verifyMC;
        bool                        verifyEnemies;
        bool                        verifyParallax;
        bool                        verifyAssets;

        int                         borneMinX;
        int                         borneMaxX;
};

#endif