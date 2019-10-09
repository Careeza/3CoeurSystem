#ifndef GAMESCENE_H

# define GAMESCENE_H

typedef struct      s_animation
{
    SDL_Texture         *textureR;
    SDL_Texture         *textureL;
    SDL_Rect            *size;
    vector<SDL_Rect>    frame;
    int                 nbFrame;
    int                 nbColumnFrame;
    int                 nbLineFrame;
}                   t_animation;

typedef struct      s_bankAnimation
{
    t_animation     animation1;
    t_animation     animation2;
}                  t_bankAnimation

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
        SDL_Texture         texture;
        SDL_Rect            size;
        SDL_Rect            frame;
        bool                right;
        bool                endAnimation;
        int                 i;
        t_bankAnimation     bank;
};

#endif