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

# include "tools.h"
# include "common.h"

# define    CS_MOTION 1
# define    CS_MOUSE_DOWN 2
# define    CS_MOUSE_UP 3

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


void    closeGame(void *settings, SDL_Renderer *render);
void    menuToHotkeys(void *settings, SDL_Renderer *render);
void    goToMenu(void *settings, SDL_Renderer *render);
void    goToHome(void *settings, SDL_Renderer *render);
void    homeToHotkeys(void *settings, SDL_Renderer *render);
void    homeToLevelSelect(void *settings, SDL_Renderer *render);
void    homeToVideo(void *settings, SDL_Renderer *render);
void    menuTovideo(void *settings, SDL_Renderer *render);
void    homeToSound(void *settings, SDL_Renderer *render);
void    menuToSound(void *settings, SDL_Renderer *render);
void    levelSelectToGame(void *settings, SDL_Renderer *render);
void    dispDialogueBox(void *settings, SDL_Renderer *render);
void    hideDialogueBox(void *settings, SDL_Renderer *render);

class   CS_Settings
{
    public:
        CS_Settings();
        ~CS_Settings();

        void            getWindowSize(int w, int h);

        void            getCloseRequest(bool close);
        void            getPauseRequest(bool pause);
        void            getFps(int fpsSource);

        void            initScene(SDL_Renderer *render);

        void            getScene(SDL_Renderer *render);
        void            getGameScene(SDL_Renderer *render);
        void            getPosition(t_pos position);

        int             QueryWindowsWidth();
        int             QueryWindowsHeight();
        float           QueryWindowsResolution();

        bool            QueryCloseRequest();
        bool            QueryPauseRequest();
        int             QueryFps();

        t_pos           QueryPosition();
        CS_Scene        *QueryScene();
        CS_GameScene    *QueryGameScene();

    private:
        int             windowWidth;
        int             windowHeight;
        float           resolution;

        bool            closeRequested;
        bool            pauseRequested;
        int             fps;

        t_pos           pos;

        CS_GameScene    *gameScene;
        CS_Scene        *Scene;
};

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

void    escapeKeyManagement(CS_KeyControl event, CS_Settings& settings, SDL_Renderer *render);
int     bouttonManagement(CS_KeyControl& control, CS_Settings& settings, SDL_Renderer *render);
void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, CS_Settings& settings);
void    filtreActionTable(t_actionTable *table, t_actionTable *filtre);
void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info);
void    resetActionTable(t_actionTable *table);
void    fillActionValue(t_actionValue *value);

#endif