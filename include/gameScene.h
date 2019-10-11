#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"

class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();
        SDL_Texture             *textureR;
        SDL_Texture             *textureL;
        std::vector<SDL_Rect>   frame;
        std::vector<int>        movement;
        std::string             name;
        int                     nbFrame;
        int                     nbColumnFrame;
        int                     nbLineFrame;
};


CS_Animation    *initAnimation(std::string name);
void            loadTexture(CS_Animation *animation, SDL_Renderer *render, std::string png_left, std::string png_right);
void            setSize(CS_Animation *animation, float w, float h, float x, float y);
void            cutFrame(CS_Animation *animation, int nb_frame, int nb_columnframe, int nb_lineframe);
void            setMovement(CS_Animation *animation, int nb_frame, ...);


class CS_BankAnimation
{
    public:
        CS_BankAnimation();
        ~CS_BankAnimation();
        CS_Animation    *CS_queryAnimationByname(std::string name);
        void            loadNoMove(SDL_Renderer *render);
    private:
        CS_Animation    *noMove;
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
        bool        useAnimation(int& i);
        void        setRight(bool rightSource);
        void        loadBank(SDL_Renderer *render);

    private:
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        bool                right;
        bool                endAnimation;
        int                 i;
        CS_Animation        *animation;
        CS_BankAnimation    *bank;
};

class   CS_GameScene : public CS_Scene
{
    public:
        CS_GameScene();
        ~CS_GameScene();
        void            loadMC();
        CS_Character    *CS_queryMC();
    private:
        CS_Character    *MC;
};

#endif