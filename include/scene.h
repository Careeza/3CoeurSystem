#ifndef SCENE_H

# define SCENE_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

# include "game.h"

# if SDL_BYTEORDER == SDL_BIG_ENDIAN
    #define rmask 0xff000000
    #define gmask 0x00ff0000
    #define bmask 0x0000ff00
    #define amask 0x000000ff
# else
    #define rmask 0x000000ff
    #define gmask 0x0000ff00
    #define bmask 0x00ff0000
    #define amask 0xff000000
# endif

# define ALIGN_LEFT 1
# define ALIGN_RIGHT 2
# define ALIGN_CENTER 3
# define ZOOM 8

class   CS_Color
{
    public:
        CS_Color();
        CS_Color(int red, int green, int blue, int alpha);

        void    CS_setRed(int red);
        void    CS_setGreen(int green);
        void    CS_setBlue(int blue);
        void    CS_setAlpha(int alpha);
        void    CS_setColor(int red = 0, int green = 0, int blue = 0, int alpha = 0);

        int CS_queryRed();
        int CS_queryGreen();
        int CS_queryBlue();
        int CS_queryAlpha();

    private:
        int CS_red;
        int CS_green;
        int CS_blue;
        int CS_alpha;
};

class CS_Border
{
    public:
        CS_Border();
        ~CS_Border();
        void        CS_createRect(SDL_Rect *rect, int w, int h, int x, int y);
        void        CS_createTexture(CS_Color colorSource, SDL_Renderer *render);
        void        CS_createBorder(SDL_Rect *elementSize);
        void        CS_ChangeSettings(int w, int h);

        SDL_Rect    *CS_queryRectUp();
        SDL_Rect    *CS_queryRectDown();
        SDL_Rect    *CS_queryRectRight();
        SDL_Rect    *CS_queryRectLeft();
        SDL_Texture *CS_queryTexture();

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

class   CS_Police
{
    public:
        CS_Police();
        ~CS_Police();
        void        CS_initPolice(std::string police);
        void        CS_policeSetting(CS_Color color, int flags = ALIGN_CENTER, int marginX = 5, int marginY = 5);
        void        CS_writeTexte(std::string texte, SDL_Rect *size, SDL_Renderer *render);
        void        CS_writeTexteScaleW(std::string texte, SDL_Rect *size, SDL_Renderer *render);
        void        CS_zoomText(int pixel);
        SDL_Texture *CS_queryTexte();
        SDL_Rect    *querySize();

    private:
        static TTF_Font     *CS_font;

        int                 CS_flags;
        int                 CS_marginX;
        int                 CS_marginY;

        int                 div_w;
        int                 div_h;
        int                 div_x;
        int                 div_y;

        SDL_Color           CS_color;
        SDL_Rect            *CS_size;
        SDL_Surface         *surface;
        SDL_Texture         *texture;
};

class   CS_NoButton
{
    public:
        CS_NoButton();
        ~CS_NoButton();
        
        void        CS_addNoButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y);
        void        CS_addNoButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y);
        void        CS_resize(float w, float h, float x, float y);
        void        CS_resizePixel(int w, int h, int x, int y);

        SDL_Texture *CS_queryNoButtonTexture();
        SDL_Rect    *CS_QuerySize();

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
        void            CS_useFonction(void);
        void            CS_addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void));
        void            CS_addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void));
        SDL_Texture     *CS_queryButtonTexture();

    private:
            void    (*CS_buttonFunction)(void);
};

class   CS_Brightness
{
    public:
        CS_Brightness();
        ~CS_Brightness();
        void            CS_initBright(SDL_Renderer *render);
        void            addBrillance(SDL_Rect *size);
        void            CS_destroyTexture();

        SDL_Texture     *CS_queryTexture();
        SDL_Rect        *CS_querySize();


    private:
        SDL_Surface         *surface;
        static SDL_Texture  *texture;
        SDL_Rect            *rect;
};

class   CS_Element
{
    public:
        CS_Element();
        ~CS_Element();

        bool            CS_isElementButton();
        bool            CS_isElementDisp();
        bool            CS_haveText();
        bool            CS_haveBorder();
        bool            CS_haveBrightness();

        void            CS_setDisp(bool disp);
        void            CS_setZIndex(int z);
        void            CS_setBrightness(bool disp);
        void            CS_setZoom(int zoom);

        int             CS_queryElementZIndex();
        CS_Police       *CS_queryText();
        SDL_Texture     *CS_queryTextTexture();
        SDL_Texture     *CS_queryElementTexture();
        SDL_Rect        *CS_queryElementSize();
        SDL_Rect        *CS_queryTextSize();
        CS_Border       *CS_queryBorder();
        CS_Brightness   *CS_queryBrightness();

        void            setPoliceSettings(CS_Color color, int flags = ALIGN_CENTER, int marginX = 5, int marginY = 5);
        void            CS_addTextToElement(std::string comment, SDL_Renderer *render);
        void            CS_addTextToElementScaleW(std::string comment, SDL_Renderer *render);

        void            loadBorder(CS_Color colorSource, SDL_Renderer *render);
        void            loadBrightness();

        void            CS_useFonction();

        void            CS_CreateNoButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y);
        void            CS_CreateButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void));
        void            CS_CreateNoButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y);
        void            CS_CreateButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void));

        void            CS_resizeElement(float w, float h, float x, float y);
        void            CS_resizeElementPixel(int w, int h, int x, int y);


    private:
        CS_NoButton     *elementNoButton;
        CS_Button       *elementButton;
        CS_Police       *text;
        CS_Border       *border;
        CS_Brightness   *brightness;

        bool        haveText;
        bool        elementIsButton;
        bool        elementIsDisp;
        bool        dispBrightness;
        bool        dispBorder;
        int         elementZIndex;
};

class   CS_Scene
{
    public:
        CS_Scene();
        ~CS_Scene();

        void                                        CS_loadRenderer(SDL_Renderer *renderSource);

        void                                        CS_addElementToScene(std::shared_ptr<CS_Element> element);
        void                                        CS_createElementToScene(float w, float h, float x, float y, int z);
        void                                        CS_createButtonToScene(float w, float h, float x, float y, int z, void (*f)(void));
        void                                        CS_createElementToSceneFromPng(std::string route, float w, float h, float x, float y, int z);
        void                                        CS_createButtonToSceneFromPng(std::string route, float w, float h, float x, float y, int z, void (*f)(void));
        void                                        CS_deleteElementFromeScene(int index);
        
        void                                        CS_setSceneColor(int r, int g, int b, int a);
        void                                        CS_setTextColor(int r, int g, int b, int a);
        void                                        CS_setBorderColor(int r, int g, int b, int a);

        std::vector<std::shared_ptr<CS_Element>>    CS_querySceneElements();
        std::shared_ptr<CS_Element>                 CS_querySingleElement(int index);
        int                                         CS_querySceneLen();

        void                                        CS_writeTexte(int index, std::string comment);
        void                                        CS_writeTexteScaleW(int index, std::string comment);
        void                                        CS_addBorder(int index);

    private:
        std::vector<std::shared_ptr<CS_Element>>    CS_sceneContain;
        int                                         lastElement;
        int                                         CS_sceneLen;

        CS_Color                                    colorSource;
        CS_Color                                    colorText;
        CS_Color                                    colorBordure;

        SDL_Renderer                                *render;
};

class   CS_Menu
{
    public:
        void            CS_addBrillance();
        void            CS_loadKeyControl(CS_KeyControl *control);
        void            CS_getMouseInfo();
        void            CS_useButton();
        void            getButton();
        CS_KeyControl   *event;

    private:
        std::shared_ptr<CS_Element>     button;
        std::shared_ptr<CS_Element>     Lockbutton;
        SDL_Rect                        *size;
        int                             x_mouse;
        int                             y_mouse;
        int                             buttons;
};

#endif