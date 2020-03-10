#ifndef BACKGROUND_H

# define BACKGROUND_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

class   CS_Layer
{
    public:
        CS_Layer();
        ~CS_Layer();
        void        createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndexSource);

        void        moveLayer(int xSource);

        bool        secondScopeNeeded();

        int         QueryZindex();
        SDL_Texture *QueryTexture();
        SDL_Rect    *QueryScopeMain();
        SDL_Rect    *QuerySizeMain();
        SDL_Rect    *QueryScopeSecond();
        SDL_Rect    *QuerySizeSecond();

    private:
        SDL_Texture *layerTexture;
        
        int         scopeWidth;
        int         scopeHeight;
        int         scopeX;
        int         scopeY;

        int         textureW;
        int         textureH;

        SDL_Rect    *scopeMain;
        SDL_Rect    *scopeSecond;

        SDL_Rect    *sizeMain;
        SDL_Rect    *sizeSecond;
        
        float       speed;

        int         zIndex;

        bool        needSecondScope;
};


class   CS_Parallax
{
    public:
        CS_Parallax();
        ~CS_Parallax();

        void        createLayer(SDL_Renderer *render, std::string source, float speedSource, int zIndex);

        void        moveLayer(int index, int x);

        CS_Layer    *QueryLayer(int index);
        int         QueryNbLayers();

    private:
        std::vector<CS_Layer *> layers;
};

#endif