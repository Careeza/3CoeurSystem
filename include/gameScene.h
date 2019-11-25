#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"
# include "tools.h"

typedef enum	e_enemy {
	CubeRouge =          0b00000000000000000000000000000001,
    CuveVert  =          0b00000000000000000000000000000010,
}				t_enemy;

typedef enum	e_aniamtion {
    STATIC,
    WALK,
}				t_animation;

# define NOINTERRUPT 1
# define INTERRUPT 2

class   CS_Layer
{
    public:
        CS_Layer();
        ~CS_Layer();
        void        createLayer(string source, float speedSource);

        void        moveLayer();

        SDL_Texture *queryTexture();
        SDL_Rect    *queryScopeMain();
        SDL_Rect    *querySizeMain();
        SDL_Rect    *queryScopeSecond();
        SDL_Rect    *querySizeSecond();

    private:
        SDL_Texture *layerTexture;
        
        int         scopeWidth;
        int         scopeHeight;
        SDL_Rect    *scopeMain;
        SDL_Rect    *scopeSecond;

        SDL_Rect    *sizeMain;
        SDL_Rect    *sizeSecond;
        
        int         speed;
}

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

        bool            CS_UseAnimation(bool right, SDL_Rect *size, SDL_Rect* &frame, SDL_Texture* &texture);


        t_animation     QueryName();
        SDL_Texture     *QueryTexture(bool right);
        SDL_Rect        *QueryFrame();
        int             QueryMovement();

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

        bool        useAnimation();
        void        setSize(float w, float h, float x, float y);

        void        setRight(bool rightSource);

        SDL_Texture *queryTexture();
        SDL_Rect    *querySize();
        SDL_Rect    *queryFrame();

    private:

        CS_BankAnimation    *bank;
        CS_Animation        *animation;
        CS_Animation        *saveAnimation;
        
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;

        bool                right;
};

class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();

        void    addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algoSource)(CS_Character *enemy, CS_Character *MC));
        void    spawnEnemy(float w, float h);
        void    reloadParam(CS_Character *MC);
        
        SDL_Texture *queryTexture();
        SDL_Rect    *querySize();
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

class   CS_GameScene : public CS_Scene
{
    public:
        CS_GameScene();
        ~CS_GameScene();

        void            loadMC(CS_Character *MCSource);
        void            loadEnemies(CS_Enemies *enemies);

        CS_Enemies      *CS_queryEnemies();
        CS_Character    *CS_queryMC();
    private:
        CS_Character    *MC;
        CS_Enemies      *enemies;
};

class   CS_HitBox
{
    public:
        CS_HitBox();
        ~CS_HitBox();
        void                addHitbox(SDL_Rect* hitbox, int type);
        int                 testHitbox(SDL_Rect* hitbox);
    private:
        std::vector<SDL_Rect*>          asset;
        std::vector<SDL_Rect*>          intelligentAsset;
        std::vector<SDL_Rect*>          floor;
        std::vector<SDL_Rect*>          ennemies;
        SDL_Rect*                       MC;

};

#endif