#ifndef ELEMENT_H

# define ELEMENT_H

#include "../preSet.h"
# include "border.h"
# include "brightness.h"
# include "button.h"
# include "font.h"


class   CS_Element
{
    public:
        CS_Element();
        ~CS_Element();

        bool            isElementButton();
        bool            isElementDisp();
        bool            isButtonEnable();
        bool            containsText();
        bool            haveBorder();
        bool            haveBrightness();

        void            setButton(bool button);
        void            setDisp(bool disp);
        void            setZIndex(int z);
        void            setBrightness(bool disp);
        void            setZoom(int zoom);

        int             QueryElementZIndex();
        CS_Police       *QueryText();
        SDL_Texture     *QueryTextTexture();
        SDL_Texture     *QueryElementTexture();
        SDL_Rect        *QueryElementSize();
        SDL_Rect        *QueryTextSize();
        CS_Border       *QueryBorder();
        CS_Brightness   *QueryBrightness();
        std::string     QueryName();

        void            setPoliceSettings(CS_Color color, int flags = ALIGN_CENTER, int marginX = 5, int marginY = 5);
        void            addTextToElement(std::string comment, SDL_Renderer *render);
        void            addTextToElementScaleW(std::string comment, SDL_Renderer *render);
        void            changeText(std::string comment, SDL_Renderer *render);

        void            loadName(std::string nameSrc);
        void            loadBorder(CS_Color colorSource, SDL_Renderer *render);
        void            changeBorder(int w, int h);
        void            loadBrightness(SDL_Renderer *render, CS_Color colorSource);

        void            useFonction(void *info, SDL_Renderer *render);

        void            CreateNoButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y);
        void            CreateButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*));
        void            CreateNoButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y);
        void            CreateButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *, SDL_Renderer*));

        void            resizeElement(float w, float h, float x, float y);
        void            resizeElementPixel(int w, int h, int x, int y);


    private:
        CS_NoButton     *elementNoButton;
        CS_Button       *elementButton;
        CS_Police       *text;
        CS_Border       *border;
        CS_Brightness   *brightness;
        std::string     name;

        bool        haveText;
        bool        enabaleButton;
        bool        elementIsButton;
        bool        elementIsDisp;
        bool        dispBrightness;
        bool        dispBorder;
        int         elementZIndex;
};

#endif