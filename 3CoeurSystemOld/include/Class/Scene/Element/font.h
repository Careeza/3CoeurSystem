#ifndef FONT_H

# define FONT_H

#include "../preSet.h"

class   CS_Police
{
    public:
        CS_Police();
        ~CS_Police();
        void        initPolice(std::string police);
        void        policeSetting(CS_Color colorSource, int flagsSource = ALIGN_CENTER, int marginXSource = 5, int marginYSource = 5);
        void        writeTexte(std::string texte, SDL_Rect *sizeSource, SDL_Renderer *render);
        void        writeTexteScaleW(std::string texte, SDL_Rect *sizeSource, SDL_Renderer *render);
        void        changeText(std::string texte, SDL_Rect *size, SDL_Renderer *render);
        void        initZoomIn();
        void        initZoomOut();
        void        zoomText(int zoomInfo);
        SDL_Texture *QueryTexte();
        SDL_Rect    *QuerySize();

    private:
        static TTF_Font     *font;

        int                 flags;
        int                 marginX;
        int                 marginY;

        int                 div_w;
        int                 div_h;
        int                 div_x;
        int                 div_y;
        int                 zoom;

        bool                haveTexture;

        SDL_Color           color;
        SDL_Rect            *size;
        SDL_Rect            *zoomIn;
        SDL_Rect            *zoomOut;
        SDL_Surface         *surface;
        SDL_Texture         *texture;
};

#endif