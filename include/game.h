#ifndef GAME_H

# define GAME_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <stdarg.h>
# include <math.h>

# define    CS_MOTION 1
# define    CS_MOUSE_DOWN 2
# define    CS_MOUSE_UP 3

typedef enum	e_pos {
	homeHome =          0b00000000100000000000000000000000,
    homeVideo =         0b00000000100000010000000000000000,
    homeSound =         0b00000000100000100000000000000000,
    homeHotkeys =       0b00000000100001000000000000000000, 
    homeLevelSelect =   0b00000000100010000000000000000000,

    menuMenu =          0b00000000000000001000000000000000,
    menuVideo =         0b00000000000000001000000100000000,
    menuSound =         0b00000000000000001000001000000000,
    menuHotkeys =       0b00000000000000001000010000000000,

    game =              0b00000000000000000000000010000000,
}				t_pos;

class   CS_Scene;
class   CS_GameScene;
class   CS_Element;

void	        init(int flags);
SDL_Window      *create_window(int flags, const std::string name = "canvas", int x = 0, int y = 0, int w = 0, int h = 0);
SDL_Renderer    *init_renderer(SDL_Window    *window);
CS_Scene        *init_home(SDL_Renderer *render);
CS_Scene        *init_menu(SDL_Renderer *render);
CS_Scene        *init_menuHotkeys(SDL_Renderer *render);
CS_Scene        *init_homeHotkeys(SDL_Renderer *render);
CS_Scene        *init_play(SDL_Renderer *render);
CS_Scene        *init_homeVideo(SDL_Renderer *render);
CS_Scene        *init_menuVideo(SDL_Renderer *render);
CS_Scene        *init_homeSound(SDL_Renderer *render);
CS_Scene        *init_menuSound(SDL_Renderer *render);
CS_GameScene    *init_gameScene(SDL_Renderer *render);


void    closeGame(void);
void    menuToHotkeys(void);
void    goToMenu(void);
void    goToHome(void);
void    homeToHotkeys(void);
void    homeToLevelSelect(void);
void    homeToVideo(void);
void    menuTovideo(void);
void    homeToSound(void);
void    menuToSound(void);
void    levelSelectToGame(void);
void    dispDialogueBox(void);
void    hideDialogueBox(void);

class   CS_Scene;

typedef struct      s_settings
{
    int         window_width;
    int         window_height;
    float       resolution;
    bool        closeRequested;
    bool        pauseRequested;
    int         fps;
    bool        debug;

    t_pos       pos;

    CS_GameScene    *gameScene;
    CS_Scene        *home;
    CS_Scene        *saveMenu;
    CS_Scene        *menu;
    CS_Scene        *controlGame;
    CS_Scene        *controlHome;
    CS_Scene        *current;
    CS_Scene        *homeVideo;
    CS_Scene        *menuVideo;
    CS_Scene        *homeSound;
    CS_Scene        *menuSound;
}                   CS_settings;

extern CS_settings  gameSettings;

typedef struct  s_key
{
    int     value;
    std::string  name;
}               t_key;


class   authorizedKey
{
    public:
        void    loadAuthorizedKey();
        std::string  keyName(int key);

    private:
        t_key   keyA;
        t_key   keyB;
        t_key   keyC;
        t_key   keyD;
        t_key   keyE;
        t_key   keyF;
        t_key   keyG;
        t_key   keyH;
        t_key   keyI;
        t_key   keyJ;
        t_key   keyK;
        t_key   keyL;
        t_key   keyM;
        t_key   keyN;
        t_key   keyO;
        t_key   keyP;
        t_key   keyQ;
        t_key   keyR;
        t_key   keyS;
        t_key   keyT;
        t_key   keyU;
        t_key   keyV;
        t_key   keyW;
        t_key   keyX;
        t_key   keyY;
        t_key   keyZ;

        t_key   key0;
        t_key   key1;
        t_key   key2;
        t_key   key3;
        t_key   key4;
        t_key   key5;
        t_key   key6;
        t_key   key7;
        t_key   key8;
        t_key   key9;

        t_key   keyTab;
        t_key   keyMaj;
        t_key   keyCtrl;
        t_key   keySpace;
        t_key   keyEnter;
        t_key   keyUp;
        t_key   keyDown;
        t_key   keyRight;
        t_key   keyLeft;
};

#endif