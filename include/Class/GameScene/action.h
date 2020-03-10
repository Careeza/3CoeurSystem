#ifndef ACTION_H

# define ACTION_H

class   CS_Force
{
    public:
        CS_Force();
        ~CS_Force();

        void    setAccelerationX(float aXsource);
        void    setAccelerationY(float aYsource);

        float   QueryAX();
        float   QueryAY();

    private:
        float aX;
        float aY; 
};

class   CS_Speed
{
    public:
        CS_Speed();
        ~CS_Speed();

        void    setSpeedX(float vXSource);
        void    setSpeedY(float vYSource);
        void    setSpeed(float vXSource, float vYSource);

        void    updateSpeed(float aXSource, float aYSource, int deltaT);

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

        void    setPositionX(float xSource);
        void    setPositionY(float ySource);

        //VERIFICATION AVEC LES OBSTACLES
        bool    updateXAxis(CS_GameScene *scene, CS_HitBox *hitbox, float vXSource, int deltaT);
        bool    updateYAxis(CS_GameScene *scene, CS_HitBox *hitbox, float vYSource, int deltaT);

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


typedef enum        e_orientation
{
    up,
    down,
    right,
    left,
    upRight,
    upLeft,
    downRight,
    downLeft,
}                   t_orientation;

class   CS_PersonalPhysic
{
    public:
        CS_PersonalPhysic();
        ~CS_PersonalPhysic();



        //GRAVITY
        void        setGravity(float gravitySource);
        float       QueryGravity();


        //STAT
        void        setHP(int hpSource);
        void        increaseHP(int hpSource);
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
        void        setHitBox(CS_HitBox *hitboxSource);
        void        setAttack(CS_HitBox *attackSource);
        void        QueryHitBox(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawHitbox();
        void        QueryAttack(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawAttack();


    private:
        CS_Speed        speed;
        CS_Position     position;
        SDL_Rect        size;

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

        bool            loadTexture(std::string route, SDL_Renderer *render);
        bool            cutFrame(int nbrColumn, int nbrLine);

        SDL_Texture     *QueryTexture();
        SDL_Rect        *QueryFrame();

    private:
        std::vector<SDL_Rect *>         frame;
        SDL_Texture                     *spriteSheet;
}

class   CS_newAnimation
{
    public:
        CS_newAnimation();
        ~CS_newAnimation();

        bool    animationStart(int indexStartSource, int indexEndSource, int animationTimeSource);
        int     animationNext(int deltaT);

    private:

        int     animationTime;
        float   frameTime;
        float   time;

        int     index;
        int     indexStart;
        int     indexEnd;
}

class   CS_Particule
{
    public:
        CS_Particule();
        ~CS_Particule();

    private:
        CS_SpriteSheet  *spriteSheet;
}

class   CS_Projectile
{
    public:
        CS_Projectile();
        ~CS_Projectile();

    private:
        int             id;

        CS_Timer        time;
        int             lifeTime;

        CS_SpriteSheet  *spriteSheet;
        void            *summoner;
        bool            (*colision)(void *dataUser);
}

/*class   CS_Projectile
{
    public:
        CS_Projectile();
        ~CS_Projectile();


        void                initPhysicProjectile(CS_PersonalPhysic *physicSource);
        void                initAnimation(CS_Animation *animationSource);

        void                updateFrame(int deltaT);
        void                moveProjectile(CS_GameScene *scene, int deltaT);
        void                getFrame();
        bool                projectileEnd();
        
        void                setName(t_projectile nameSource);
        void                setID(int idSource);
        void                setRight(int rightSource);
        void                setRange(int rangeSource);
        void                setAlly(bool allySource);

        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int& yDest);

        int                 QueryID();
        int                 QueryRange();
        bool                QueryAlly();
        t_projectile        QueryName();
        CS_Animation        *QueryAnimation();
        CS_PersonalPhysic   *QueryPhysic();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();

    private:
        t_projectile        name;
        SDL_Texture         *texture;
        SDL_Rect            *frame;
        CS_PersonalPhysic   *physic;
        CS_Animation        *animation;
        int                 range;
        int                 id;
        bool                right;
        bool                ally;
};
*/

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


class   CS_Character
{
    public:
        CS_Character();
        CS_Character(std::string route, int nC, int nL);

        bool    updateProjectile(int deltaT);
        bool    updateParticules(int deltaT);

        ~CS_Character();

    private:
        std::vector<CS_SpriteSheet *>   spriteSheet;
        std::vector<CS_Action *>        action;
        std::vector<CS_Projectile *>    projectiles;
        std::vector<CS_Particule *>     particules;

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

        CS_BankAnimation    *QueryAnimationBank();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();


    private:
        CS_Character        *character;
        int                 id;
};


/* DANS LE FICHIER DU JEU */
/*class   CS_MC
{
    public:

    private:
        t_action        *action;
        CS_Character    *moine;
        CS_Character    *kitsune;
}*/

class   CS_Layer
{
    public:
        CS_Layer();
        ~CS_Layer();

        void    createLayer(std::string route, SDL_Renderer *render, float speedSource, int zIndexSource, SDL_Rect scope);
        
        int     QueryZindex();


    private:
        SDL_Texture *texture;
        SDL_Rect    *scope;
        //Taille = full anyway !

        float       speed;
        int         zIndex;
};


class   CS_Parallax
{
    public:
        CS_Parallax();
        ~CS_Parallax();

        void        createLayer(SDL_Renderer *render, std::string source, float SpeedSource, int zIndex, SDL_Rect scope);

        int         QueryNbLayers();
        CS_Layer    *QueryLayer(int index);

    private:
        std::vector<CS_Layer *> layers;
};

class   CS_Map
{
    public:
        void            setBorneX(int xMinSource, int xMaxSource);
        void            setBorneY(int yMinSource, int yMaxSource);

        void            loadOnScreen();

        void            loadParallax(CS_Parallax *parallaxSource);
        void            loadAssets(CS_Assets *assetsSource);

    private:
        int             xMax;
        int             xMin;

        int             yMin;
        int             yMax;

        CS_OnScreen     *onScreen;
        CS_Parallax     *parallax;
        CS_Assets       *assets;        
}

class   CS_GameScene : public CS_Scene
{
    public:
        CS_GameScene();
        ~CS_GameScene();

        void            loadCamera(CS_Camera *cameraSource);
        void            loadMap(CS_Map *mapSource);

        CS_Map          *QueryMap();
        CS_Camera       *QueryCamera();

    private:
        CS_Camera                   *camera;
        CS_Map                      *map;

        std::vector<CS_Character *> characters;
};
#endif