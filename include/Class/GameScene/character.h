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

# include "physicalEngine.h"

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

        void        getFrame();

        void        setAnimationTime(int animationTimeSource);

        void        moveCharacter(float deltaT, int BorderMinX, int BorderMaxX);
        void        setRight(bool rightSource);

        void        QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void        QuerySize(int& wDest, int& hDest);
        void        QueryPos(int& xDest, int& yDest);

        CS_PersonalPhysic   *QeuryPhysique();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();

        bool                VerifyRight();

        bool                verifyAnimationEnd();

        int                 QueryMoveX();
//        int         QueryMoveY();


    private:
        SDL_Texture         *texture;
        SDL_Rect            *frame;

        CS_BankAnimation    *bank;
        CS_Animation        *animation;
        CS_Animation        *saveAnimation;
        CS_PersonalPhysic   *physic;

        bool                right;
};

#endif