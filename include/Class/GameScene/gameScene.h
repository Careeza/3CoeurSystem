#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"
# include "animation.h"
# include "asset.h"
# include "backGround.h"
# include "character.h"
# include "enemy.h"
# include "../../Tools/tools.h"

class   CS_GameScene;

class   CS_Camera
{
    public:
        CS_Camera();
        ~CS_Camera();

        void    moveCamera(int xSource, int ySource);
        void    moveCamera2(int xSource, int ySource, CS_GameScene *map);
        void    moveCamera3(CS_Character *MC, float deltaT);

        void    QueryCameraPosition(int& xDest, int& yDest);
        int     QueryCameraPositionX();
        int     QueryCameraPositionY();

    private:
        float     x;
        float     y;
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

        CS_Enemies      *QueryEnemies();
        CS_Character    *QueryMC();
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

void            verifyHitbox(CS_PersonalPhysic *physic, int w, int h, int BorderMinX, int BorderMaxX);
void            moveWithTest(bool right, int w, int h, int& x, int &y, CS_GameScene *map);

#endif