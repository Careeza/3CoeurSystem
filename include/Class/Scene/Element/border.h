#ifndef BORDER_H

# define BORDER_H

#include "../preSet.h"

class CS_Border
{
    public:
        CS_Border();
        ~CS_Border();
        void        createRect(SDL_Rect *rect, int w, int h, int x, int y);
        void        createTexture(CS_Color colorSource, SDL_Renderer *render);
        void        createBorder(SDL_Rect *elementSize);
        void        ChangeSettings(int w, int h);

        SDL_Rect    *QueryRectUp();
        SDL_Rect    *QueryRectDown();
        SDL_Rect    *QueryRectRight();
        SDL_Rect    *QueryRectLeft();
        SDL_Texture *QueryTexture();

    private:
        SDL_Surface *surface;
        SDL_Texture *texture;
        SDL_Rect    *rectUp;
        SDL_Rect    *rectDown;
        SDL_Rect    *rectRight;
        SDL_Rect    *rectLeft;
        int         borderSize_w;
        int         borderSize_h;
};


#endif