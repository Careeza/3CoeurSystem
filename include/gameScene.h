#ifndef GAMESCENE_H

# define GAMESCENE_H

# include "scene.h"

class   CS_Animation
{
    public:
    CS_Animation();
    ~CS_Animation();
    SDL_Texture         *textureR;
    SDL_Texture         *textureL;
    SDL_Rect            *size;
    std::vector<SDL_Rect>    frame;
    int                 nbFrame;
    int                 nbColumnFrame;
    int                 nbLineFrame;
};

class CS_BankAnimation
{
    public:
    CS_BankAnimation();
    ~CS_BankAnimation()
    CS_Animation     *noMove;
};

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();
        SDL_Texture *queryTexture();
        SDL_Rect    *querySize();
        SDL_Rect    *queryFrame();
        bool        useAnimation();
        void        loadFunction();

    private:
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        bool                right;
        bool                endAnimation;
        int                 i;
        CS_BankAnimation    bank;
};

#endif