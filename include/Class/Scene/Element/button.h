#ifndef BUTTON_H

# define BUTTON_H

#include "../preSet.h"

typedef enum        e_buttonValue
{
    noButton,
    trueButton,
    falseButton,
    exitButton,
    levelSelectButton,
    creditButton,
    homeButton,
    gameButton,
    menuButton,
    backButton,
}                   t_buttonValue;

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
        t_buttonValue   useFonction();
        void            addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, t_buttonValue (*f)());
        void            addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, t_buttonValue (*f)());
        SDL_Texture     *QueryButtonTexture();

    private:
            t_buttonValue   (*buttonFunction)();
};

#endif