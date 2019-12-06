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

        void    setRed(int redSource);
        void    setGreen(int greenSource);
        void    setBlue(int blueSource);
        void    setAlpha(int alphaSource);
        void    setColor(int red = 0, int green = 0, int blue = 0, int alpha = 0);

        int QueryRed();
        int QueryGreen();
        int QueryBlue();
        int QueryAlpha();

    private:
        int red;
        int green;
        int blue;
        int alpha;
};

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

class   CS_Scene
{
    public:
        CS_Scene();
        ~CS_Scene();

        void                                        loadRenderer(SDL_Renderer *renderSource);

        void                                        addElementToScene(std::shared_ptr<CS_Element> element);
        void                                        createElementToScene(std::string name, float w, float h, float x, float y, int z);
        void                                        createButtonToScene(std::string name, float w, float h, float x, float y, int z, void (*f)(void *, SDL_Renderer*));
        void                                        createElementToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z);
        void                                        createButtonToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z, void (*f)(void *, SDL_Renderer*));
        void                                        deleteElementFromeScene(int index);
        
        void                                        setSceneColor(int r, int g, int b, int a);
        void                                        setTextColor(int r, int g, int b, int a);
        void                                        setBorderColor(int r, int g, int b, int a);
        void                                        setBrightnessColor(int r, int g, int b, int a);
        void                                        setDisp(bool disp, int index);
        void                                        setButton(bool button, int index);

        std::vector<std::shared_ptr<CS_Element>>    QuerySceneElements();
        std::shared_ptr<CS_Element>                 QuerySingleElement(int index);
        int                                         QuerySceneLen();
        std::string                                 QueryName(int index);
        int                                         QueryIndexByName(std::string name);

        void                                        writeTexte(int index, std::string comment);
        void                                        writeTexteScaleW(int index, std::string comment);
        void                                        addBorder(int index);

    private:
        std::vector<std::shared_ptr<CS_Element>>    sceneContain;
        int                                         lastElement;
        int                                         sceneLen;

        CS_Color                                    colorSource;
        CS_Color                                    colorText;
        CS_Color                                    colorBordure;
        CS_Color                                    colorBrightness;

    protected:
        SDL_Renderer                                *render;
};

#endif