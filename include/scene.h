#ifndef SCENE_H

# define SCENE_H

# include "tools.h"

typedef enum	e_pos {
	homeHome =          0b00000000100000000000000000000000,
    homeVideo =         0b00000000100000010000000000000000,
    homeSound =         0b00000000100000100000000000000000,
    homeHotkeys =       0b00000000100001000000000000000000, 
    homeLevelSelect =   0b00000000100010000000000000000000,
    homeBox =           0b00000000100100000000000000000000,


    menuMenu =          0b00000000000000001000000000000000,
    menuVideo =         0b00000000000000001000000100000000,
    menuSound =         0b00000000000000001000001000000000,
    menuHotkeys =       0b00000000000000001000010000000000,

    game =              0b00000000000000000000000010000000,
}				t_pos;

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

# define    NOZOOM 0
# define    ZOOMIN 1
# define    ZOOMOUT 2

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
        void        changeText(std::string texte, SDL_Rect *size, SDL_Renderer *render);
        void        initZoomIn();
        void        initZoomOut();
        void        CS_zoomText(int zoomInfo);
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
        int                 zoom;

        SDL_Color           CS_color;
        SDL_Rect            *CS_size;
        SDL_Rect            *CS_zoomIn;
        SDL_Rect            *CS_zoomOut;
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
        void            CS_useFonction(void *info);
        void            CS_addButtonFromPng(std::string route, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *));
        void            CS_addButtonFromHand(CS_Color color, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *));
        SDL_Texture     *CS_queryButtonTexture();

    private:
            void    (*CS_buttonFunction)(void*);
};

class   CS_Brightness
{
    public:
        CS_Brightness();
        ~CS_Brightness();
        void            CS_initBright(SDL_Renderer *render, CS_Color color);
        void            addBrillance(SDL_Rect *size);
        void            CS_destroyTexture();

        SDL_Texture     *CS_queryTexture();
        SDL_Rect        *CS_querySize();


    private:
        SDL_Surface         *surface;
        SDL_Texture         *texture;
        SDL_Rect            *rect;
};

class   CS_Element
{
    public:
        CS_Element();
        ~CS_Element();

        bool            CS_isElementButton();
        bool            CS_isElementDisp();
        bool            CS_isButtonEnable();
        bool            CS_haveText();
        bool            CS_haveBorder();
        bool            CS_haveBrightness();

        void            CS_setButton(bool button);
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
        std::string     CS_queryName();

        void            setPoliceSettings(CS_Color color, int flags = ALIGN_CENTER, int marginX = 5, int marginY = 5);
        void            CS_addTextToElement(std::string comment, SDL_Renderer *render);
        void            CS_addTextToElementScaleW(std::string comment, SDL_Renderer *render);

        void            loadName(std::string nameSrc);
        void            loadBorder(CS_Color colorSource, SDL_Renderer *render);
        void            changeBorder(int w, int h);
        void            loadBrightness(SDL_Renderer *render, CS_Color colorSource);

        void            CS_useFonction(void *info);

        void            CS_CreateNoButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y);
        void            CS_CreateButtonFromHand(CS_Color color, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *));
        void            CS_CreateNoButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y);
        void            CS_CreateButtonFromPng(std::string route, CS_Color colorBrightness, SDL_Renderer *render, float w, float h, float x, float y, void (*f)(void *));

        void            CS_resizeElement(float w, float h, float x, float y);
        void            CS_resizeElementPixel(int w, int h, int x, int y);


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

class   CS_Scene
{
    public:
        CS_Scene();
        ~CS_Scene();

        void                                        CS_loadRenderer(SDL_Renderer *renderSource);

        void                                        CS_addElementToScene(std::shared_ptr<CS_Element> element);
        void                                        CS_createElementToScene(std::string name, float w, float h, float x, float y, int z);
        void                                        CS_createButtonToScene(std::string name, float w, float h, float x, float y, int z, void (*f)(void *));
        void                                        CS_createElementToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z);
        void                                        CS_createButtonToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z, void (*f)(void *));
        void                                        CS_deleteElementFromeScene(int index);
        
        void                                        CS_setSceneColor(int r, int g, int b, int a);
        void                                        CS_setTextColor(int r, int g, int b, int a);
        void                                        CS_setBorderColor(int r, int g, int b, int a);
        void                                        CS_setBrightnessColor(int r, int g, int b, int a);
        void                                        CS_setDisp(bool disp, int index);
        void                                        CS_setButton(bool button, int index);

        std::vector<std::shared_ptr<CS_Element>>    CS_querySceneElements();
        std::shared_ptr<CS_Element>                 CS_querySingleElement(int index);
        int                                         CS_querySceneLen();
        std::string                                 CS_queryName(int index);
        int                                         CS_queryIndexByName(std::string name);

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
        CS_Color                                    colorBrightness;

    protected:
        SDL_Renderer                                *render;
};

#endif