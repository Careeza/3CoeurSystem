#ifndef ACTION_H

# define ACTION_H

class   CS_Force
{
    public:
        CS_Force();
        ~CS_Force();

        void    setAccelerationX(float aX);
        void    setAccelerationY(float aY);

        float   QueryAX();
        float   QueryAY();

    private:
        float aX;
        float aY; 
};

class   CS_GamePhysics
{
    public:
        CS_WorldPhysics();
        ~CS_WorldPhysics();

        void        setGravity(float aX, float aY);
        CS_Force    QueryGravity();

    private:
        CS_Force    gravity;
};

class   CS_Speed
{
    public:
        CS_Speed();
        ~CS_Speed();

        void    setSpeedX(float vX);
        void    setSpeedY(float vY);
        void    setSpeed(float vX, float vY);

        void    updateSpeed(float aX, float aY, int deltaT);

        float   QuerySpeedX();
        float   QuerySpeedY();
        
    private:
        float     vX;
        float     vY;
};

class   CS_Position
{
    public:
        CS_Position();
        ~CS_Position();

        void    setPositionX(float x);
        void    setPositionY(float y);

        //VERIFICATION AVEC LES OBSTACLES
        bool    updateXAxis(CS_GameScene *scene, CS_HitBox *hitbox, float vX, int deltaT);
        bool    updateYAxis(CS_GameScene *scene, CS_HitBox *hitbox, float vY, int deltaT);

        bool    verifyOnGround();
        void    QueryPostion(int& xDest, int& yDest);
        int     QueryPostionX();
        int     QueryPostionY();

    private:
        float   x;
        float   y;
        bool    onGround;
        bool    onWall;
};



typedef struct      s_orientation
{
    bool    up;
    bool    down;
    bool    right;
    bool    left;
}                   t_orientation;

void                resetOrientation(t_orientation&  orientation); // ??
/*{
    up = false;
    down = false;
    right = right;
    left = left;
}*/

class   CS_PersonalPhysic
{
    public:
        CS_PersonalPhysic();
        ~CS_PersonalPhysic();
 

        //GRAVITY
        void        setGravity(float gravity);
        float       QueryGravity();


        //STAT
        void        setHP(int hp);
        void        increaseHP(int hp);
        int         QueryHP();
        void        setImmunity(int deltaT);
        void        updateImmunity(int deltaT);

        //SPEED
        void        setSpeedX(float speedX);
        void        setSpeedY(float speedY);
        void        updateSpeed(int deltaT);
        float       QuerySpeedX();
        float       QuerySpeedY();

        //POSITION
        void        setPositionX(int positionX);
        void        setPositionY(int positionY);
        void        updatePosition(CS_GameScene *scene, int deltaT);
        void        QueryPostion(int& xDest, int& yDest);
        int         QueryPostionX();
        int         QueryPostionY();
        bool        verifyOnGround();

        //SIZE
        void        setWidth(int width);
        void        setHeight(int height);
        void        setSize(int width, int height);
        void        QuerySize(int &wDest, int& hDest);
    

        // HITBOX
        void        setHitBox(CS_HitBox *hitbox);
        void        setAttack(CS_HitBox *attack);
        void        QueryHitBox(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawHitbox();
        void        QueryAttack(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawAttack();


    private:
        CS_Speed        *speed;
        CS_Position     *position;
        SDL_Rect        *size;

        CS_HitBox       *hitbox;
        CS_HitBox       *attack;
        
        float           gravity;
        int             hp;

        t_orientation   orientation;

        CS_Timer        immunity;
        int             immunityTime;
};

class   CS_SpriteSheet
{
    public:
        CS_SpriteSheet();
        ~CS_SpriteSheet();

        bool            loadSpriteSheet(SDL_Renderer *render, std::string route, int nC, int nL);

        bool            loadTexture(std::string route, SDL_Renderer *render);
        bool            cutFrame(int nbrColumn, int nbrLine);

        SDL_Texture     *QueryTexture();
        SDL_Rect        *QueryFrame();

    private:
        std::vector<SDL_Rect *>         frame;
        SDL_Texture                     *spriteSheet;

        int                             nC;
        int                             nL;
        int                             nT;
}




class   CS_CoreAnimation
{
    public:
        CS_CoreAnimation();
        ~CS_CoreAnimation();

        bool    animationStart(int spriteSheet, int indexStart, int indexEnd, int animationTime);

        int     animationNext(int deltaT);

        bool    animationEnd();

        int     queryIndex();
        int     querySpriteSheet();

    private:
        int     spriteSheet;

        int     animationTime;
        float   frameTime;
        float   time;

        int     index;
        int     indexStart;
        int     indexEnd;
}

class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();

        bool        initSpriteSheet(CS_SpriteSheet *spriteSheet);
        bool        initCoreAnimation(int spriteSheet, int indexStart, int indexEnd, int animationTime);

        void        updateAnimation(int deltaT);

        SDL_Rect    *QueryFrame();
        SDL_Rect    *QueryTexture();

    private:
        CS_CoreAnimation    *coreAnimation;
        CS_SpriteSheet      *spriteSheet;
}

class   CS_Particule
{
    public:
        CS_Particule();
        ~CS_Particule();

        bool            initParticule(CS_Animation *animation, CS_PersonalPhysic *physic);

        bool            updateParticule(int deltaT);

        SDL_Rect        *QueryFrame();
        SDL_Rect        *QuerySizePos();
        SDL_Texture     *QueryTexture();

    private:
        CS_Animation        *animation;
        CS_PersonalPhysic   *physic;
}

typedef 

class   CS_Projectile
{
    public:
        CS_Projectile();
        ~CS_Projectile();

        void            initProjectile(CS_Animation *animation, CS_PersonalPhysic *physic, void *summoner);

        bool            updateProjectile(int deltaT);

        SDL_Rect        *QueryFrame();
        SDL_Rect        *QuerySizePos();
        SDL_Texture     *QueryTexture();

    private:
        int                 id;

        CS_Timer            time;
        int                 lifeTime;

        CS_Animation        *animation;
        CS_PersonalPhysic   *physic;

        void                *summoner;
        bool                (*colision)(void *dataUser);

}

typedef struct      s_ActionCore
{
    bool        (*start)(void *dataUser);
    bool        (*next)(void *dataUser);
    bool        (*isFinish)(void *dataUser);
    bool        (*end)(void *dataUser); 

    int         coolDownTime;
    int         comboTime;
}                   t_ActionCore;

class   CS_Action
{
    public:
        CS_Action();
        ~CS_Action();

        void        loadStart(bool (*f)(void *dataUser));
        void        loadNext(bool (*f)(void *dataUser));
        void        loadIsFinish(bool (*f)(void *dataUser));
        void        loadEnd(bool (*f)(void *dataUser));

        bool        actionStart(void *dataUser);
        bool        actionNext(void *dataUser);
        bool        actionIsFinish(void *dataUser);
        bool        ActionEnd(void  *dataUser);

    private:
        bool        (*start)(void *dataUser);
        bool        (*next)(void *dataUser);
        bool        (*isFinish)(void *dataUser);
        bool        (*end)(void *dataUser); 

        CS_Timer    coolDown;
        int         coolDownTime;

        CS_Timer    combo;
        int         comboTime;
        int         comboIndex;
}

typedef struct      s_CharacterCore
{
    std::vector<CS_SpriteSheet *>   spriteSheets;
    std::vector<CS_Action *>        actions;
    std::vector<CS_Projectile *>    projectiles;
    std::vector<CS_Particule *>     particules; 
}                   t_CharacterCore;

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();

        bool    initCharacter(CS_SpriteSheet *spriteSheet, int nC, int nL);
        bool    addSpriteSheet(CS_SpriteSheet *spriteSheet);
        bool    addAction(CS_Action *action);

        bool    updateActions(); // IL A BESOINS DE QUOI LE CON ?


        bool    updateProjectile(int deltaT);
        bool    updateParticules(int deltaT);

        bool    spawnParticule(CS_Particule *particule);
        bool    spawnProjectile(CS_Projectile *projectile);

    private:
        CS_Animation                    *animation;
        CS_Action                       *action;

        std::vector<CS_SpriteSheet *>   spriteSheets; // 1 ANIMATION 2 PROJECTILE 3 PARTICULE 
        std::vector<CS_Action *>        actions;
        
        std::vector<CS_Projectile *>    projectiles; // TOUT LES PROJECTILES LANCER PAR LE PERSONNAGE
        std::vector<CS_Particule *>     particules; // TOUTES LES PARTICULES DU PERSONNAGE
}


class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();

        int                 QueryID();

        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int& yDest);

        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();

    private:
        CS_Character        *character;
        std::string         name;
        int                 id;
};

class   CS_EnemyBank
{
    public:


    private:
}


//TODO DEFINIR DANS LE .H DU JEU
/*
# define MUSIC_AMBIANCE0
# define MUSIC_AMBIANCE1

# define SON_MC0
# define SON_MC1

# define SON_ENEMY0
# define SON_ENEMY1
# define SON_ENEMY2
# define SON_ENEMY3
*/


class   CS_Sound
{
    public:
        CS_Sound();
        ~CS_Sound();

        void        createSound(std::string route, int canal = 0, std::string nameSoure);

        void        playSound(int n = 0);
        void        pauseMusic();
        void        resumeMusic();
        void        stopMusic();

        std::string QueryName();

    private:
        std::string     name;
        int             canal;
        Mix_Chunk       *sound;        
}



class   CS_BankOfSound
{
    public:
        void    createSound(std::string route, int canal = 0, std::string nameSoure);
        void    playSound(std::string name, int n = 0);
        void    pauseMusic(std::string name);
        void    resumeMusic(std::string name);
        void    stopMusic(std::string name);

    private:
        std::vector<CS_Sound *>     bankOfSound;
}



class   CS_GameSound
{
    public:
        CS_GameSound();
        ~CS_GameSound();

        void    initGameSound(int nbrCanal);
        void    setVolumeCanal(int canal, int volume);

    private:
        int                 nbrCanal;
        std::vector<int>    volumeCanal;
} // TODO GAME_H

class   CS_Layer
{
    public:
        CS_Layer();
        ~CS_Layer();

        void    createLayer(SDL_Renderer *render, std::string route, int w, int h, int x, int y, int zIndex, float speed)
        
        void    QuerySizePos(int& w, int& h, int& x, int& y);
        void    QuerySize(int& w, int& h);
        void    QueryPos(int& x, int& y);

        float   QuerySpeed();

        int     QueryZindex();


    private:
        SDL_Texture *texture;

        int         w;
        int         h;
        int         x;
        int         y;

        float       speed;
        int         zIndex;
};

class   CS_Parallax
{
    public:
        CS_Parallax();
        ~CS_Parallax();

        void        createLayer(SDL_Renderer *render, std::string route, int w, int h, int x, int y, int zIndex, float speed);

        int         QueryNbLayers();
        CS_Layer    *QueryLayer(int index);

    private:
        std::vector<CS_Layer *> layers;
};

class   CS_Map
{
    public:
        CS_Map();
        ~CS_Map();

        void            setBorneX(int xMin, int xMax);
        void            setBorneY(int yMin, int yMax);

        void            loadParallax(CS_Parallax *parallax);
        void            loadAssets(CS_Assets *assets);

    private:
        int             xMax;
        int             xMin;

        int             yMin;
        int             yMax;

        CS_Parallax     *parallax;
        CS_Assets       *assets;
}

class   CS_Camera
{
    public:
        CS_Camera();
        ~CS_Camera();

        void    setCameraPosition(int x, int y);

        void    moveCamera(int x, int y, bool flag = false, int deltaT = 0, int speed = 0);

        void    QueryCameraPosition(int& x, int& y);
        int     QueryCameraPositionX();
        int     QueryCameraPositionY();

    private:
        float       x;
        float       y;
};

class   CS_GameScene : public CS_Scene
{
    public:
        CS_GameScene();
        ~CS_GameScene();

        void            loadCamera(CS_Camera *camera);
        void            loadMap(CS_Map *map);

        CS_Camera       *QueryCamera();
        CS_Map          *QueryMap();

    private:
        CS_Camera                   *camera;
        CS_Map                      *map;

        std::vector<CS_Character *> characters;
};

typedef struct      s_RenderElement
{
    SDL_Texture     *texture;
    SDL_Rect        *size;
    SDL_Rect        *frame;
}                   t_RenderElement;

class   CS_Renderer
{
    
    public:
        CS_Renderer();
        ~CS_Renderer();

        void    loadRenderer(SDL_Renderer *renderSource);

        void    renderScene(CS_Scene *scene);
        void    renderElement(std::shared_ptr<CS_Element> element);
        void    renderText(CS_Police *text);
        void    renderBorder(CS_Border *border);
        void    renderBrightness(CS_Brightness *brightness);

        void    renderGameScene(CS_GameScene *gameScene);
        void    renderParallax(CS_Parallax *parallax);
        void    renderAssets(CS_Assets *assets, int cameraX, int cameraY);
        void    renderMC(CS_Character *MC, int cameraX, int cameraY);
        void    renderEnemy(CS_Enemies *enemies, int cameraX, int cameraY);
        void    renderProjectiles(CS_Projectiles *projectiles, int cameraX, int cameraY);

        void    renderTexture(SDL_Texture *texture, SDL_Rect *frame, SDL_Rect *size);
        void    renderScreenSave();

        void    dispScreen();
        void    saveScreen();

        SDL_Texture     *QueryScreen();
        SDL_Texture     *QueryScreenSave();
        SDL_Renderer    *QueryRender();

    private:
        std::vector<t_RenderElement>    renderList;

        SDL_Renderer                    *render;
        SDL_Texture                     *screen;
        SDL_Texture                     *screenSave;
};

class   CS_Game
{
    public:
        CS_Game();
        ~CS_Game();

        bool            start();

        t_actionValue   &QueryValue();
        t_actionTable   &QueryAction();
        CS_Render       &QueryRender();
        CS_GamePhysics  &QueryGamePhysics();
        SDL_Window      *QueryWindow();
        
    private:
        t_actionValue   value;
        t_actionTable   action;

        CS_Render       render;
        SDL_Window      *window;
        CS_GamePhysics  gamePhysic;
}

extern  CS_Game game;
/* DANS LE FICHIER DU JEU */
/*class   CS_MC
{
    public:

    private:
        t_action        *action;
        CS_Character    *moine;
        CS_Character    *kitsune;
}*/
#endif