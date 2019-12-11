#ifndef BUTTON_H

# define BUTTON_H

#include "../preSet.h"

class   CS_NoButton
{
    public:
        CS_NoButton();
        ~CS_NoButton();
        
        void        addNoButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y);
        void        addNoButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y);
        void        resize(float w, float h, float x, float y);
        void        resizePixel(int w, int h, int x, int y);

        SDL_Texture *QueryNoButtonTexture();
        SDL_Rect    *QuerySize();

    protected:
        SDL_Rect    *buttonSize;
        SDL_Surface *noButtonSurface;
        SDL_Texture *noButtonTexture;
};

class   CS_Button : public CS_NoButton
{
    public:
        CS_Button();
        ~CS_Button();
        void            useFonction(void *info, SDL_Renderer *render);
        void            addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*));
        void            addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*));
        SDL_Texture     *QueryButtonTexture();

    private:
            void    (*buttonFunction)(void*, SDL_Renderer*);
};

#endif