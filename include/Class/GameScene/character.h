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

class   CS_Character
{
    public:
        CS_Character();
        ~CS_Character();

        void        addAnimation(SDL_Renderer *render, CS_Animation*(*f)(SDL_Renderer *render));
        void        loadAnimation(t_animation name);

        bool        nextFrame();
        bool        previousFrame();
        void        getFrame();
        void        moveCharacter();

        void        setPas(float pasSource);
        bool        nextIndexPas();

        void        setSizePos(float wSource, float hSource, float xSource, float ySource);
        void        setSize(float wSource, float hSource);
        void        setPos(float xSource, float ySource);

        void        setRight(bool rightSource);

        SDL_Texture *QueryTexture();
        SDL_Rect    *QueryFrame();

        void        QuerySizePos(int& w, int& h, int& x, int& y);
        void        QuerySize(int& w, int& h);
        void        QueryPos(int& x, int& y);

        int         QueryMoveX();
//        int         QueryMoveY();


    private:

        CS_BankAnimation    *bank;
        CS_Animation        *animation;
        CS_Animation        *saveAnimation;
        
        SDL_Texture         *texture;
        SDL_Rect            *size;
        SDL_Rect            *frame;
        int                 x;
        int                 y;
        int                 w;
        int                 h;

        bool                right;
};

#endif