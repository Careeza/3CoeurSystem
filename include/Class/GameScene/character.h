#ifndef CHARACTER_H

# define CHARACTER_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

# include "animation.h"

# define MOINE true
# define KITSUNE false

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();

        void        addAnimation(SDL_Renderer *render, CS_Animation*(*f)(SDL_Renderer *render));
        void        loadAnimation(t_animation name);
        void        loadPhysic(CS_PersonalPhysic *physicSource);

        void        nextFrame();
        void        previousFrame();

        void        updateFrame(int deltaT);
        void        updateJump();

        void        getFrame();

        void        setAnimationTime(int animationTimeSource);

        void        moveCharacter(int deltaT, CS_GameScene *scene);
        void        setRight(bool rightSource);

        void        QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void        QuerySize(int& wDest, int& hDest);
        void        QueryPos(int& xDest, int& yDest);

        void        setOnGround(bool onGroundSource);
        bool        verifyOnGround();

        void        useJump();

        void        setJump(int jumpSource);
        void        setMaxJump(int maxJumpSource);
        int         QueryJump();

        void        swapMC();
        void        setMC(bool moineSource);

        CS_Animation        *QueryAnimation();
        CS_PersonalPhysic   *QueryPhysic();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();

        bool                VerifyRight();

        bool                verifyAnimationEnd();
        bool                MCIsMoine();

        int                 QueryMoveX();
//        int         QueryMoveY();


    private:
        SDL_Texture         *texture;
        SDL_Rect            *frame;

        CS_BankAnimation    *bankMoine;
        CS_BankAnimation    *bankKitsune;

        CS_Animation        *animation;
        CS_PersonalPhysic   *physic;

        bool                right;

        bool                moine;
        bool                onGround;
        int                 jump;
        int                 maxJump;
};

#endif