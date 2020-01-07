#ifndef ANIMATION_H

# define ANIMATION_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

# include "physicalEngine.h"

typedef enum	e_aniamtion {
    STATIC,
    WALK,
    SPRINT,
}				t_animation;

# define MCWALKL "resources/source/Slime/runLSlime.png"
# define MCWALKR "resources/source/Slime/runRSlime.png"

# define MCSTATICL "resources/source/MainCharacter/staticLMC.png"
# define MCSTATICR "resources/source/MainCharacter/staticRMC.png"

class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();

        void            newAnimation(t_animation nameSource, int stop);
        void            loadTexture(SDL_Renderer *render, std::string png_left, std::string png_right);
        void            cutFrame(int nb_frame, int nb_columnframe, int nb_lineframe);
        void            setSpeed(float speedXSource, float speedYsource);
        void            setSize(float wSource, float hSource);
        void            setAnimationTime(int animationTimeSource);

        void            restartAnimation();

        void            nextFrame2(int deltaT);
        void            nextFrame();
        void            previousFrame();
        bool            verifyAnimationEnd();
        
        void            getFrame(bool right, SDL_Rect* &frameDest, SDL_Texture* &textureDest);
        
        t_animation     QueryName();

        SDL_Texture     *QueryTexture(bool right);
        SDL_Rect        *QueryFrame();
        void            QuerySize(int &wDest, int& hDest);
        
        int             QueryMovementX(bool right);
        int             QueryMovementY();

    private:

        t_animation                 name;
        bool                        interrupt;

        SDL_Texture                 *textureR;
        SDL_Texture                 *textureL;
        std::vector<SDL_Rect *>     frame;
        std::vector<CS_HitBox *>    hitboxes;

        int                         speedX;
        int                         speedY;

        int                         w;
        int                         h;

        int                         nbFrame;
        int                         nbColumnFrame;
        int                         nbLineFrame;

        float                       pas;
        float                       indexPas;

        bool                        animationEnd;

        int                         animationTime;
        float                       frameTime;
        float                       time;

        int                         index;
};

class CS_BankAnimation
{
    public:
        CS_BankAnimation();
        ~CS_BankAnimation();
        CS_Animation    *QueryAnimationByname(t_animation name);
        void            addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render));

    private:
        std::vector<CS_Animation*>   animations;
};

#endif