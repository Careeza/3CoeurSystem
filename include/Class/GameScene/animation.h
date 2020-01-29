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
    ATTACK,
    FALL,
    JUMP,
    DEAD,
}				t_animation;
 
class   CS_Animation
{
    public:
        CS_Animation();
        ~CS_Animation();

        void            newAnimation(t_animation nameSource, bool stop);
        void            loadTexture(SDL_Renderer *render, std::string png_left, std::string png_right);
        void            cutFrame(int nb_frame, int nb_columnframe, int nb_lineframe);
        void            setSpeed(float speedXSource, float speedYsource);
        void            setSize(float wSource, float hSource);
        void            setAnimationTime(int animationTimeSource, int indexStartSource = 0);
        void            setInterrupt(bool interruptSource);

        void            setHitBox(bool right, float wSource, float hSource, float xSource, float ySource);
        void            setAttack(bool right, float wSource, float hSource, float xSource, float ySource);

        void            restartAnimation();

        void            nextFrame2(int deltaT);
        void            nextFrame();
        void            previousFrame();
        bool            verifyAnimationEnd();
        
        void            getFrame(bool right, SDL_Rect* &frameDest, SDL_Texture* &textureDest);
        
        t_animation     QueryName();

        SDL_Texture     *QueryTexture(bool right);
        CS_HitBox       *QueryHitbox(bool right);
        CS_HitBox       *QueryAttack(bool right);
        SDL_Rect        *QueryFrame();
        void            QuerySize(int &wDest, int& hDest);
        
        float           QueryMovementX(bool right);
        float           QueryMovementY();
        int             QueryAnimationTime();
        int             QueryIndex();
        int             QueryMaxIndex();
        int             QueryNbColumnFrame();
        int             QueryNbLineFrame();
        int             QueryAnimationInterrupt();

        void            CopyAnimation(CS_Animation *animationSource);

    private:

        t_animation                 name;
        bool                        interrupt;

        SDL_Texture                 *textureR;
        SDL_Texture                 *textureL;
        std::vector<SDL_Rect *>     frame;
        CS_HitBox                   *hitboxesR;
        CS_HitBox                   *hitboxesL;
        CS_HitBox                   *attackR;
        CS_HitBox                   *attackL;

        float                       speedX;
        float                       speedY;

        int                         w;
        int                         h;

        int                         nbFrame;
        int                         nbColumnFrame;
        int                         nbLineFrame;

        bool                        animationEnd;

        int                         animationTime;
        float                       frameTime;
        float                       time;

        int                         index;
        int                         indexStart;
};

class CS_BankAnimation
{
    public:
        CS_BankAnimation();
        ~CS_BankAnimation();
        CS_Animation    *QueryAnimationByname(t_animation name);
        void            addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render));

        int             QueryNbAnimation();
        CS_Animation    *QueryAnimation(int index);

        void            CopyAnimationBank(CS_BankAnimation *animationBankSource);

    private:
        std::vector<CS_Animation*>   animations;
};

#endif