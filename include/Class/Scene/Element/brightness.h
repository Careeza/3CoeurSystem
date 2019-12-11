#ifndef BRIGHTNESS_H

# define BRIGHTNESS_H

#include "../preSet.h"

class   CS_Brightness
{
    public:
        CS_Brightness();
        ~CS_Brightness();
        void            initBright(SDL_Renderer *render, CS_Color color);
        void            addBrillance(SDL_Rect *size);
        void            destroyTexture();

        SDL_Texture     *QueryTexture();
        SDL_Rect        *QuerySize();


    private:
        SDL_Surface         *surface;
        SDL_Texture         *texture;
        SDL_Rect            *rect;
};

#endif