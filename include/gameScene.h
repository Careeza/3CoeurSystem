#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"

typedef enum	e_enemy {
	CubeRouge =          0b00000000000000000000000000000001,
    CuveVert  =          0b00000000000000000000000000000010,
}				t_enemy;

class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();
        SDL_Texture             *textureR;
        SDL_Texture             *textureL;
        std::vector<SDL_Rect *>   frame;
        std::vector<int>        movement;
        std::string             name;
        int                     nbFrame;
        int                     nbColumnFrame;
        int                     nbLineFrame;
};


CS_Animation    *initAnimation(std::string name);
void            loadTexture(CS_Animation *animation, SDL_Renderer *render, std::string png_left, std::string png_right);
//void            setSize(CS_Animation *animation, float w, float h, float x, float y);
void            cutFrame(CS_Animation *animation, int nb_frame, int nb_columnframe, int nb_lineframe);
void            setMovement(CS_Animation *animation, int nb_frame, ...);


class CS_BankAnimation
{
    public:
        CS_BankAnimation();
        ~CS_BankAnimation();
        CS_Animation    *CS_queryAnimationByname(std::string name);
        void            loadNoMove(SDL_Renderer *render, void (*f)(SDL_Renderer *render, CS_Animation* &animation));
        void            loadAllenWalker(SDL_Renderer *render, void (*f)(SDL_Renderer *render, CS_Animation* &animation));

    private:
        CS_Animation    *noMove;
        CS_Animation    *AllenWalker;
};

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();
        SDL_Texture *queryTexture();
        SDL_Rect    *querySize();
        SDL_Rect    *queryFrame();
        void        loadAnimation(std::string name);
        bool        useAnimation();
        void        setRight(bool rightSource);
        void        loadBank(SDL_Renderer *render);

    private:
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        CS_Animation        *animation;
        CS_BankAnimation    *bank;
        bool                right;
        bool                endAnimation;
        int                 i;
};

class   CS_CommonEnemy
{
    public:
        CS_CommonEnemy();
        ~CS_CommonEnemy();
        void            loadAnimation(std::string name);
        void            setRight(bool rightSource);
        bool            useAnimation();
        SDL_Texture     *queryTexture();
        SDL_Rect        *querySize();
        SDL_Rect        *queryFrame();
    
    protected:        
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        SDL_Rect            *hitbox;
        CS_Animation        *animation;
        CS_BankAnimation    *bank;
        bool                right;
        bool                endAnimation;
        int                 i;
};

class   CS_Cube : public CS_CommonEnemy
{
    public:
        void        initRedCube();
        void        loadBank(SDL_Renderer *render);

    private:
};

class   CS_CubeGreen : public CS_CommonEnemy
{
    public:
        void        initGreenCube();
        void        loadBank(SDL_Renderer *render);

    private:
};

class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();
        SDL_Texture *queryTexture();
        SDL_Rect    *querySize();
        SDL_Rect    *queryFrame();
        void        reloadParam();
        void        addEnemy(t_enemy type, SDL_Renderer *render);
    
    private:
        t_enemy         EnemyType;
        CS_CommonEnemy  *enemy;
};

class   CS_Enemies
{
    public:
        CS_Enemies();
        ~CS_Enemies();
        void        addEnemy(t_enemy type, SDL_Renderer *render);
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
        void            loadMC();
        void            loadEnemies();
        CS_Enemies      *CS_queryEnemies();
        CS_Character    *CS_queryMC();
    private:
        CS_Character    *MC;
        CS_Enemies      *enemies;
};

void        setSize(SDL_Rect *size, float w, float h, float x, float y);
bool        CS_UseAnimation(bool right, CS_Animation *animation, SDL_Rect *size, SDL_Rect* &frame, SDL_Texture* &texture, int &i);

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

}

#endif